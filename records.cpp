#include "records.h"
#include <vector>
#include <fstream>
unsigned int Records::countRecord(void)
{
    return _records.size();
}

Record * Records::getRecord(unsigned int no)
{
    if(no >= 0 && no < _records.size())
        return &_records[no];
    else
        return nullptr;
}

void Records::addRecord(Record record)
{
    _records.push_back(record);
}

void Records::clearRecords(void)
{
    _records.clear();
}
bool Records::deleteRecord(unsigned int no)
{
    if(no >= 0 && no < _records.size())
    {
        _records.erase(_records.begin() + no);
        return true;
    }
    else
    {
        return false;
    }
}

bool Records::replaceRecord(unsigned int no, Record record)
{
    if(no >= 0 && no < _records.size())
    {
        _records[no] = record;
        return true;
    }
    else
    {
        return false;
    }
}

void Records::sortRecords(unsigned int key, bool ascending)
{
    // not implemented yet
}