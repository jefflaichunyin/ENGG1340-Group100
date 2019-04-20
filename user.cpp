#include "user.h"
#include <iostream>
#include <fstream>
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
        // std::cout << "VERBOSE POD_RECORD: " << sizeof(POD_Record) << " NUM of REC " << num_of_record << std::endl;
        outputfile.close();
        delete user_records;
        user_records = nullptr;
        return true;
    }
}

bool User::loadRecords(void)
{
    std::ifstream inputfile(_records_path.c_str(), std::ios::binary);
    if(inputfile.fail())
    {
        std::cout << "Cannot open record file for " << _username << std::endl;
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

// constructor of User object
User::User(std::string username, std::string password)
{
    _username = username;
    _password = password;
    _records_path = username + ".dat";
}

// Class UserAccount member function implementation

// Function: return the position of the user in the _users vector
//           return -1 if username is not found in the _users vector
int UserAccounts::searchUser(std::string username)
{
    int pos = -1;
    for(int i = 0; i < int(_users.size()); i++)
    {
        if(_users[i].getUsername() == username)
        {
            pos = i;
            break;
        }    
    }
    return pos;
}
bool UserAccounts::addUser(std::string username, std::string password)
{
    if(searchUser(username) == -1) // username is not found
    {
        User *newUser = new User(username, password);
        _users.push_back(*newUser); // copy new user to vector _users
        delete newUser;
        std::cout << "User " << username << " is created sucessfully\n";
        return true; // sucessfully add the user        
    }
    else
    {
        std::cout << "User " << username << " already exist! Please choose another username.\n";
        return false;
    }
}

bool UserAccounts::checkPassword(std::string username, std::string password)
{
    int pos = searchUser(username);
    if(pos == -1) // user doesn't exist
    {
        std::cout << username << " doesn't exist. Please try again.\n";
        return false;
    }
    else if(_users[pos].getPassword() != password) // user exist but password is incorrect
    {
        std::cout << "Incorrect password. Please enter the password correctly.\n";
        return false;
    }
    else
    {
        std::cout << "Password correct.\n";
        return true;
    }
}

bool UserAccounts::removeUser(std::string username, std::string password)
{
    if(checkPassword(username, password) == true)
    {
        _users.erase(_users.begin() + searchUser(username));
        std::cout << username << " is deleted.\n";
        return true;
    }
    else
    {
        return false;
    }
}

bool UserAccounts::changePassword(std::string username, std::string old_password, std::string new_password)
{
    if(checkPassword(username, old_password) == true)
    {
        if(old_password == new_password)
        {
            std::cout << "New password cannot be the same as the old password. Please use a different password.\n";
            return false;
        }
        else
        {
            _users[searchUser(username)].setPassword(new_password);
            std::cout << "Password changed sucessfully.\n";
            return true;
        }
    }
    else
    {
        return false;
    }
}

User * UserAccounts::getUser(std::string username)
{
    int pos = searchUser(username);
    if(pos != -1) // user exist and password correct
    {
        return &_users[(unsigned int)pos];
    }
    else
    {
        return nullptr;
    }
}

bool UserAccounts::saveUserInfo(void)
{
    std::ofstream outputfile("UserInfo.dat", std::ios::binary);
    if(outputfile.fail())
    {
        std::cout << "Failed to save user login information\n";
        return false;
    }
    else
    {
        POD_UserInfo *user_info = new POD_UserInfo;
        // copy username and password to POD_UserInfo so that it can be saved as binary format
        for(unsigned int i=0; i < _users.size(); i++)
        {
            strcpy(user_info->username, _users[i].getUsername().c_str());
            strcpy(user_info->password, _users[i].getPassword().c_str());
            outputfile.write((char *)user_info, sizeof(POD_UserInfo));
        }
        outputfile.close();
        delete user_info;
        user_info = nullptr;
        return true;
    }    
}

bool UserAccounts::loadUserInfo(void)
{
    std::ifstream inputfile("UserInfo.dat", std::ios::binary);
    if(inputfile.fail())
    {
        std::cout << "Cannot load user login information\n";
        return false;
    }
    else
    {
        POD_UserInfo *user_info = new POD_UserInfo;
        while(inputfile.read((char*)user_info, sizeof(POD_UserInfo)))
        {
            addUser(std::string(user_info->username), std::string(user_info->password));
        }
        delete user_info;
        user_info = nullptr;
        inputfile.close();
        return true;
    }
}