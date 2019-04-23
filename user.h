
#include "records.h"
#define MAX_LENGTH 255

// only use basic data type without internal pointers so that it can be save in binary file
struct POD_UserInfo
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};
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
        bool saveRecords(void);
        bool loadRecords(void);
    private:
        std::string _username;
        std::string _password;
        std::string _records_path;
        Records _records;
};