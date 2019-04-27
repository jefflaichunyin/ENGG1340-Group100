#include "user.h"
class UserAccounts
{
    public:
        // all 3 functions will return true if sucess, false will be returned if the operation if unsucessful and the reason why will be printed out
        // e.g user already exist, user doesn't exist, password incorrect, password cannot be same ...
        User * getUser(std::string username); // return the address that point the User
        bool addUser(std::string username, std::string password);
        bool removeUser(std::string username, std::string password);
        bool checkPassword(std::string username, std::string password);
        bool changePassword(std::string username, std::string old_password, std::string new_password); // return false if old_password doesn't match current password or user doesn't exist
        bool saveUserInfo(void); 
        bool loadUserInfo(void); // return false when no previous user info is saved
        int searchUser(std::string username); // return the position of the user in _users vector
    private:
        std::vector<User> _users;

};
