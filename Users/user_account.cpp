#include "user_account.h"
#include <cstring>
#include <iostream>
#include <fstream>
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
        newUser->setSavingGoal_t(0, 0);
        _users.push_back(*newUser); // copy new user to vector _users
        delete newUser;
        // std::cout << "User " << username << " is created sucessfully\n";
        return true; // sucessfully add the user        
    }
    else
    {
        // std::cout << "User " << username << " already exist! Please choose another username.\n";
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
        //std::cout << "Password correct.\n";
        return true;
    }
}

bool UserAccounts::removeUser(std::string username, std::string password)
{
    if(checkPassword(username, password) == true)
    {
        getUser(username)->removeRecords();
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
            user_info->saving_goal = _users[i].getSavingGoal();
            user_info->deadline = _users[i].getDeadline_t();
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
        // std::cout << "Cannot load user login information\n";
        return false;
    }
    else
    {
        POD_UserInfo *user_info = new POD_UserInfo;
        while(inputfile.read((char*)user_info, sizeof(POD_UserInfo)))
        {
            addUser(std::string(user_info->username), std::string(user_info->password));
            _users[_users.size()-1].setSavingGoal_t(user_info->saving_goal, user_info->deadline);
        }
        delete user_info;
        user_info = nullptr;
        inputfile.close();
        return (_users.size()>0); // return false if no existing user
    }
}