// This class "Records" is used to manage a collection of records of an user
#ifndef RECORD_H
#define RECORD_H
#include "record.h"
#endif
#include <vector>
#include <string>
class Records
{
    public:
        unsigned int countRecord(void); // return number of records
        Record * getRecord(unsigned int no); // return the address of the n-th record, return NULL if n is out of range
        void addRecord(Record record);
        bool deleteRecord(unsigned int no);
        bool replaceRecord(unsigned int no, Record record); //replace old record with new record

        // not implemented yet
        std::vector<int> searchRecords(unsigned int key, std::string value); // return a vector containing indexes pointing to the records
        void sortRecords(unsigned int key, bool ascending);


    private:
        std::vector<Record> _records;
};

