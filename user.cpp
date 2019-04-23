#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

// Class User member function implementation
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
            std::strcpy(user_records->type, r->getType().c_str());
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
}