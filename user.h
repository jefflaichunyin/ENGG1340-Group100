
#include "records.h"
#define MAX_LENGTH 255

// only use basic data type without internal pointers so that it can be save in binary file
struct POD_UserInfo
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    float saving_goal;
    time_t deadline;
};
class User
{
    public:
        User(std::string username, std::string password); // use this constructor to create user
        Records * getUserRecords(void);

        // plz avoid using following functions, use functions in UserAccount instead
        bool setUsername(std::string username);
        // only use this when password is not set yet, always use changePassword() if possible
        bool setPassword(std::string password); 
        std::string getUsername(void);  // return empty string "" if not set yet
        std::string getPassword(void);  // return empty string "" if not set yet 

        bool setSavingGoal(float amount, int month, int year); // e.g. save $10000 by Apr,2020, setSavingGoal(10000,4,2020); 
        bool setSavingGoal_t(float amount, time_t deadline);

        float getSavingGoal(void);
        float getTotalIncome(void);
        float getTotalExpense(void);

        float getCategoryIncome(std::string category);
        float getCategoryExpense(std::string category);

        // get income/expense for this month
        float getMonthlyIncome();
        float getMonthlyExpense();
        // return 0 if saving goal is not set / already meet / already passed the deadline
        float getMonthlyGoal(void);
        // 
        // if saving goal is not set, return amount of money the user can spend , return -ve value if grand total < 0
        // return +ve value if there is still remaining quota
        // return -ve value if the user overspend, the value will be amount of overspend
        float getMonthlyQuota(void);
        
        std::string getDeadline(void);
        time_t getDeadline_t(void);

        bool saveRecords(void);
        bool removeRecords(void);
        bool loadRecords(void);         // load records from the data file [Username].dat
        void unloadRecords(void);       // remove loaded records from the memory to free up spaces

    private:
        std::string _username;
        std::string _password;
        float       _saving_goal;
        time_t      _deadline;
        std::string _records_path;
        Records _records;
};