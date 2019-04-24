// This class "Records" is used to manage a collection of records of an user
#include "record.h"
#include <vector>

enum Field{DATE,AMOUNT,TYPE,CATEGORY,ACCOUNT,REMARK};

class Records
{
    public:
        
        unsigned int countRecord(void); // return number of records
        Record * getRecord(unsigned int no); // return the address of the n-th record, return NULL if n is out of range
        void addRecord(Record record);
        void clearRecords(void);
        bool deleteRecord(unsigned int no);
        bool replaceRecord(unsigned int no, Record record);
        
        // not implemented yet
        std::vector<Record> searchRecords(unsigned int key, std::string value); // return a vector containing indexes pointing to the records
        void sortRecords(Field field, bool ascending);


    private:
        void swapRecords(unsigned int a, unsigned int b); // swap two records
        std::vector<Record> _records;
};

