#include <string>
#include <vector>
class User
{
    public:
        User(std::string username, std::string password);
        bool setUsername(std::string username);
        bool setPassword(std::string password); // use this when password is not set yet
        std::string getUsername(void); // return empty string "" if not set yet
        std::string getPassword(void); // return empty string "" if not set yet 
    private:
        std::string _username;
        std::string _password;
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
    private:
        int searchUser(std::string username);
        std::vector<User> _users;
    
};
