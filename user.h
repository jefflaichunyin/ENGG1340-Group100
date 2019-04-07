#include <string>
#include <vector>
class User
{
    public:
        bool setUsername(string username);
        bool setPassword(string password);
        std::string getUsername(void); // return empty string "" if not set yet
        std::string getPassword(void); // return empty string "" if not set yet
    private:
        std::string _username;
        std::string _username;
};

class UserAccounts
{
    public:
        bool addUser(string username, std::string password);
        bool checkPassword(string username, std::string password);
        bool changePassword(string username, std::stirng password);
    private:
        std::vector<User> _users;
    
};