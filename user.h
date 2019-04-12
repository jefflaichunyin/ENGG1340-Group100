#include <string>
#include <vector>
#include "records.h"
class User
{
    public:
        User(std::string username, std::string password); // use this constructor to create user
        Records * getUserRecords(void);

        // plz avoid using following functions, use functions in UserAccount instead
        bool setUsername(std::string username);
        bool setPassword(std::string password); // only use this when password is not set yet, always use changePassword() if possible
        std::string getUsername(void); // return empty string "" if not set yet
        std::string getPassword(void); // return empty string "" if not set yet 
        
    private:
        std::string _username;
        std::string _password;
        Records _records;
};

class UserAccounts
{
    public:
        // all 3 functions will return true if sucess, false will be returned if the operation if unsucessful and the reason why will be printed out
        // e.g user already exist, user doesn't exist, password incorrect, password cannot be same ...
        
        bool addUser(std::string username, std::string password);
        bool removeUser(std::string username, std::string password);
        bool checkPassword(std::string username, std::string password);
        bool changePassword(std::string username, std::string old_password, std::string new_password); // return false if old_password doesn't match current password or user doesn't exist
        User * getUser(std::string username); // return the address that point the User
    private:
        int searchUser(std::string username); // return the position of the user in _users vector
        std::vector<User> _users;

};
