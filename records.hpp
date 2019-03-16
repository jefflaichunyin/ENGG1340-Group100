#ifndef CTIME_H
#define CTIME_H
#include <ctime>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif
class Record
{
    public:
        bool Record(); //constructor
        //getters
        time_t getDate();
        float getAmount();
        string getType();
        string getAccount();
        string getRemark();
        //setters with data validation
        //return true if valid
        bool setDate(time_t date);
        bool setAmount(float amount);
        bool setType(string type);
        bool setAccount(string account);
        bool setRemark(string remark);
    private:
        time_t  _date;
        float   _amount;
        string  _type;
        string  _account;
        string  _remark;
};

class Records
{
    public:
        Record getRecord(int no);
        bool addRecord(Record record);
        bool deleteRecord(int no);
        bool modifyRecord(int no, Record record);
        void sortRecords(int key, bool ascending);
        bool readRecords(string location);
        bool writeRecords(string location);
    private:
        vector<Record> _records;
};

