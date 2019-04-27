#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>

// Class User member function implementation
float User::getTotalIncome(void)
{
    float total_income=0;
    Records *user_records = getUserRecords();
    for(unsigned int i=0; i< user_records->countRecord(); i++)
    {
        Record *r = user_records->getRecord(i);
        if(r->getType()=="INCOME" && r->getCategory()!="TRANSFER") // exclude all transfer records
            total_income += r->getAmount();
    }
    return total_income;
}

float User::getTotalExpense(void)
{
    float total_expense=0;
    Records *user_records = getUserRecords();
    for(unsigned int i=0; i< user_records->countRecord(); i++)
    {
        Record *r = user_records->getRecord(i);
        if(r->getType()=="EXPENSE" && r->getCategory()!="TRANSFER") // exclude all transfer records
            total_expense += r->getAmount();
    }
    return total_expense;
}

float User::getMonthlyIncome()
{
    float income = 0;
    time_t current_t = time(nullptr);
    
    Records *user_records = getUserRecords();
    for(unsigned int i=0; i< user_records->countRecord(); i++)
    {
        Record *r = user_records->getRecord(i);
        time_t record_t = r->getDate_t();
        if(r->getType()=="INCOME" && localtime(&current_t)->tm_mon == localtime(&record_t)->tm_mon)
            income += r->getAmount();
    }
    return income;
}

float User::getMonthlyExpense()
{
    float expense = 0;
    time_t current_t = time(nullptr);
    
    Records *user_records = getUserRecords();
    for(unsigned int i=0; i< user_records->countRecord(); i++)
    {
        Record *r = user_records->getRecord(i);
        time_t record_t = r->getDate_t();
        if(r->getType()=="EXPENSE" && localtime(&current_t)->tm_mon == localtime(&record_t)->tm_mon)
            expense += r->getAmount();
    }
    return expense;
}

std::string User::getDeadline(void)
{
    if(_deadline > 0)
    {
        char buffer[50];
        std::strftime(buffer, 50, "%B-%Y", std::localtime(&_deadline));
        std::string date_str(buffer);
        return date_str;
    }
    else
    {
        return "Not set yet";
    }
}
time_t User::getDeadline_t(void)
{
    return _deadline;
}

float User::getSavingGoal(void)
{
    return _saving_goal;
}

bool User::setSavingGoal_t(float amount, time_t deadline)
{
    if(amount>=0 && deadline>=0)
    {
        _saving_goal = amount;
        _deadline = deadline;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool User::setSavingGoal(float amount, int month, int year)
{
    if(amount>0 && month>0 && year>=1990)
    {
        time_t deadline_t;
        time(&deadline_t);
        struct tm deadline = *localtime(&deadline_t);
        deadline.tm_mon = month - 1; // no. of months since January
        deadline.tm_year = year - 1900; // no. of years since 1990
        _saving_goal = amount;
        _deadline = mktime(&deadline);
        return true;
    }
    else
    {
        return false;
    }
}

float User::getMonthlyGoal(void)
{
    float goal = 0;
    time_t current = time(NULL);
    time_t deadline = getDeadline_t();
    int remaining_year = localtime(&deadline)->tm_year - localtime(&current)->tm_year;
    int remaining_month = remaining_year*12 + localtime(&deadline)->tm_mon - localtime(&current)->tm_mon;
    float grand_total = getTotalIncome()-getTotalExpense();
    // cannot meet deadline or meet target or target not set
    if(remaining_month<0 || grand_total>getSavingGoal() || getSavingGoal()==0) 
    {
        goal = 0;
    }
    else
    {
        goal = (getSavingGoal() - (grand_total))/remaining_month;
    }
    return goal;
}

float User::getMonthlyQuota(void)
{
    float grand_total = getTotalIncome()-getTotalExpense();
    if(getSavingGoal()!=0 && grand_total>getSavingGoal())
    {
        return grand_total - getSavingGoal();
    }
    else
    {
        return grand_total-getMonthlyGoal();
    }
}

Records * User::getUserRecords(void)
{
    return &_records;
}

bool User::setUsername(std::string username)
{
    if(_username == "")
    {
        _username = username;
        return true;
    }
    else // username is already set
    {
        return false;
    }   
}

bool User::setPassword(std::string password)
{
    if(_password == "")
    {
        _password = password;
        return true;
    }
    else // password is already set
    {
        _password = password; // set it anyway but return false as warning
        return false;
    }   
}

std::string User::getUsername(void)
{
    return _username;
}

std::string User::getPassword(void)
{
    return _password;
}
bool User::saveRecords(void)
{
    std::ofstream outputfile(_records_path.c_str(), std::ios::binary);
    if(outputfile.fail())
    {
        std::cout << "Failed to save records\n";
        return false;
    }
    else
    {
        POD_Record *user_records = new POD_Record;
        // copy user record to POD_Record so that it can be saved as binary format
        for(unsigned int i=0; i < _records.countRecord(); i++)
        {
            Record *r = _records.getRecord(i);
            user_records->date = r->getDate_t();
            user_records->amount = r->getAmount();
            std::strcpy(user_records->category, r->getCategory().c_str());
            std::strcpy(user_records->type, r->getType().c_str());
            std::strcpy(user_records->account, r->getAccount().c_str());
            std::strcpy(user_records->remark, r->getRemark().c_str());
            outputfile.write((char *)user_records, sizeof(POD_Record));
        }
        outputfile.close();
        delete user_records;
        user_records = nullptr;
        return true;
    }
}

bool User::removeRecords(void)
{
    if(!remove(_records_path.c_str()))
    {
        std::cout << "Failed to remove user records\n";
        return false;
    }
    else
    {
        return true;
    }
}
bool User::loadRecords(void)
{
    std::ifstream inputfile(_records_path.c_str(), std::ios::binary);
    if(inputfile.fail())
    {
        // std::cout << "Cannot open record file for " << _username << std::endl;
        return false;
    }
    else
    {
        POD_Record *user_record = new POD_Record;
        while(inputfile.read((char*)user_record, sizeof(POD_Record)))
        {
            Record new_record(
                user_record->date, user_record->amount, 
                std::string(user_record->type),
                std::string(user_record->category),
                std::string(user_record->account), 
                std::string(user_record->remark)
            );
            getUserRecords()->addRecord(new_record);
        }
        delete user_record;
        user_record = nullptr;
        inputfile.close();
        return true;
    }
}

void User::unloadRecords(void)
{
    _records.clearRecords();
}

// constructor of User object
User::User(std::string username, std::string password)
{
    _username = username;
    _password = password;
    _records_path = username + ".dat";
    _saving_goal = 0;
    _deadline = 0;
}