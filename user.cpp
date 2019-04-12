#include "user.h"
#include <iostream>
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

// constructor of User object
User::User(std::string username, std::string password)
{
    _username = username;
    _password = password;
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