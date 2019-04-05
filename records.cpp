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

bool Records::readRecords(std::string location)
{
    // not implemented yet
    bool returnval;
    std::ifstream inputfile(location.c_str(), std::ios::binary);
    if(inputfile.is_open())
    {
        inputfile.read((char *)&_records,sizeof(_records));
        returnval = true;
    }
    else
    {
        returnval = false;
    }
    return returnval;
}

bool Records::writeRecords(std::string location)
{
    // not implemented yet   
    bool returnval;
    std::ofstream outputfile(location.c_str(), std::ios::binary);
    if(outputfile.is_open())
    {
        outputfile.write((char *)&_records,sizeof(_records));
        outputfile.close();
        returnval = true;
    }
    else
    {
        returnval = false;
    }
    return returnval;
}