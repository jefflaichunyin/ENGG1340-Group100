#include "records.h"
#include <vector>
#include <fstream>
#include <iostream> //debug
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

void Records::swapRecords(unsigned int a, unsigned int b)
{
    Record tmp = _records[a];
    _records[a] = _records[b];
    _records[b] = tmp;
}
void Records::sortRecords(Field field, bool ascending)
{
    unsigned int num_of_records = countRecord();
    // selection sort is used as it's simple and more efficient than bubble sort
    for(unsigned int i=0; i<num_of_records-1; i++)
    {
        unsigned int target = i; // position of n-th record
        for(unsigned int j = i+1; j<num_of_records; j++)
        {
            if(field == DATE)
            {
                if( (ascending) ? (_records[j].getDate_t() < _records[i].getDate_t()) : (_records[j].getDate_t() > _records[i].getDate_t()))
                    target = j;
            }
            if(field == AMOUNT)
            {
                if( (ascending) ? (_records[j].getAmount() < _records[i].getAmount()) : (_records[j].getAmount() > _records[i].getAmount()))
                    target = j;
            }
            if(field == TYPE)
            {
                if( (ascending) ? (_records[j].getType() < _records[i].getType()) : (_records[j].getType() > _records[i].getType()))
                    target = j;
            }
            if(field == CATEGORY)
            {
                if( (ascending) ? (_records[j].getCategory() < _records[i].getCategory()) : (_records[j].getCategory() > _records[i].getCategory()))
                    target = j;
            }
            if(field == ACCOUNT)
            {
                if( (ascending) ? (_records[j].getAccount() < _records[i].getAccount()) : (_records[j].getAccount() > _records[i].getAccount()))
                    target = j;
            }
        }
        if(i!=target)
            swapRecords(i, target);
    }

}

std::vector<Record> searchRecords(unsigned int key, std::string value)
{
    std::vector<Record> result;
    return result;
}