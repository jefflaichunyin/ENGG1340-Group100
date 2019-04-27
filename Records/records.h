// This class "Records" is used to manage a collection of records of an user
#include "record.h"
#include <vector>

enum Field{ID,DATE,ACCOUNT,CATEGORY,AMOUNT,TYPE,REMARK};

class Records
{
    public:
        unsigned int countRecord(void); // return number of records
        Record * getRecord(unsigned int no); // return the address of the n-th record, return NULL if n is out of range
        void addRecord(Record record);
        void clearRecords(void);       // remove records and free the memory
        bool deleteRecord(unsigned int no);
        bool replaceRecord(unsigned int no, Record record); // replace existing record with new record
        // return a pointer pointing to Records object containing the result, delete it when not useful anymore
        Records * searchRecords(Field field, std::string keyword); 
        void sortRecords(Field field, bool ascending);
        void normalizeID(void);     // re-number the ID of the record, which may be not continuous after deletion
    private:
        void swapRecords(unsigned int a, unsigned int b); // swap two records
        std::vector<Record> _records;
};

