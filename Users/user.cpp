#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;
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
        // The income record is created in the current month
        if(r->getType()=="INCOME" && r->getCategory()!="TRANSFER" && localtime(&current_t)->tm_mon == localtime(&record_t)->tm_mon)
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
        // The expense record is created in the current month
        if(r->getType()=="EXPENSE" && r->getCategory()!="TRANSFER" &&  localtime(&current_t)->tm_mon == localtime(&record_t)->tm_mon)
            expense += r->getAmount();
    }
    return expense;
}

// return the deadline of the saving goal in MM-YYYY format
string User::getDeadline(void)
{
    if(_deadline > 0)
    {
        char buffer[50];
        strftime(buffer, 50, "%B-%Y", localtime(&_deadline));
        string date_str(buffer);
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
    if(amount>0 && month>0 && year>=1900) 
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

bool User::setUsername(string username)
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

bool User::setPassword(string password)
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

string User::getUsername(void)
{
    return _username;
}

string User::getPassword(void)
{
    return _password;
}

bool User::exportRecordsToCSV(string filepath)
{
    ofstream outputfile(filepath.c_str());
    if(outputfile.fail())
    {
        cout << "Failed to write to " << filepath << endl;
        return false;
    }
    else
    {
        outputfile << "ID,DATE,ACCOUNT,CATEGORY,AMOUNT,TYPE,REMARK\n"; // write CSV header
        for(unsigned int i = 0; i<getUserRecords()->countRecord(); i++)
        {
            Record *r = getUserRecords()->getRecord(i);
            outputfile << r->getID() << ",\"" << r->getDate() << "\",\"" << r->getAccount() << "\",$" 
            << r->getAmount() << ",\"" << r->getType() << "\",\"" << r->getRemark() << "\"" << endl;
        }
        cout << "Records have been written to " << filepath << endl;
        outputfile.close();
        return true;
    }
    
}
bool User::saveRecords(void)
{
    ofstream outputfile(_records_path.c_str(), ios::binary);
    if(outputfile.fail())
    {
        cout << "Failed to save records\n";
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
            strcpy(user_records->category, r->getCategory().c_str());
            strcpy(user_records->type, r->getType().c_str());
            strcpy(user_records->account, r->getAccount().c_str());
            strcpy(user_records->remark, r->getRemark().c_str());
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
        cout << "Failed to remove user records\n";
        return false;
    }
    else
    {
        return true;
    }
}

bool User::loadRecords(void)
{
    ifstream inputfile(_records_path.c_str(), ios::binary);
    if(inputfile.fail())
    {
        return false;
    }
    else
    {
        POD_Record *user_record = new POD_Record;
        while(inputfile.read((char*)user_record, sizeof(POD_Record)))
        {
            Record new_record(
                user_record->date, user_record->amount, 
                string(user_record->type),
                string(user_record->category),
                string(user_record->account), 
                string(user_record->remark)
            );
            getUserRecords()->addRecord(new_record);
        }
        delete user_record;
        user_record = nullptr;
        inputfile.close();
        return true;
    }
}

// delete user records from  the memory
void User::unloadRecords(void)
{
    _records.clearRecords();
}

// constructor of User object
User::User(string username, string password)
{
    _username = username;
    _password = password;
    _records_path = username + ".dat";
    _saving_goal = 0;
    _deadline = 0;
}