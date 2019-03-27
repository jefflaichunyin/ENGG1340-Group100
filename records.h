// This class "Records" is used to manage a collection of records of an user
#ifndef RECORD_H
#define RECORD_H
#include "record.h"
#endif

#include <string>
class Records
{
    public:
        Record getRecord(int no);
        bool addRecord(Record record);
        bool deleteRecord(int no);
        bool modifyRecord(int no, Record record); //replace old record with new record
        void sortRecords(int key, bool ascending);
        bool readRecords(std::string location);
        bool writeRecords(std::string location);
    private:
        std::vector<Record> _records;
};

