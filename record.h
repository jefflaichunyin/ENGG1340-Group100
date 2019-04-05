// The class "Record" is used to store details of a single transaction
#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#ifndef STRING_H
#define STRING_H
#include <string>
#endif
class Record
{
    public:
        Record(); //constructor
        Record(time_t date, float amount, std::string type, std::string category, std::string account, std::string remark);
        //getters
        std::string getDate();
        float getAmount(); //return -1 if undefined
        std::string getType();
        std::string getCategory();
        std::string getAccount();
        std::string getRemark();
        //setters with data validation
        //return true if valid
        bool setDate(time_t date);
        bool setAmount(float amount);
        bool setType(std::string type);
        bool setCategory(std::string category);
        bool setAccount(std::string account);
        bool setRemark(std::string remark);
    private:
        time_t  _date;
        float   _amount;        //always +ve
        std::string  _type;     //either "INCOME" OR "EXPENSE"
        std::string _category;  //e.g FOOD/TRANSPORT...
        std::string  _account;  //e.g BANK/CREDIT CARD
        std::string  _remark;
};