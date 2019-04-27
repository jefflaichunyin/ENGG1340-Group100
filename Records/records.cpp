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
    record.setID(countRecord()+1);
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
        normalizeID();
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
        normalizeID();
        return true;
    }
    else
    {
        return false;
    }
}

void Records::normalizeID(void)
{
    if(countRecord()>1) // meaningless to sort just 1 record
        sortRecords(ID, true);
    for(unsigned int i=0; i<countRecord(); i++)
    {
        getRecord(i)->setID(i+1); // re-number the ID
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
    for(unsigned int i=0; i<num_of_records-1 && num_of_records!=0; i++) // 0-1 will underflow
    {
        unsigned int target = i; // position of n-th record
        for(unsigned int j = i+1; j<num_of_records; j++)
        {
            // Figure out swap or not
            if(field == ID)
            {
                // std::cout << "A: " << _records[j].getID() << " B: " <<  _records[i].getID() << std::endl;
                if( (ascending) ? (_records[j].getID() < _records[target].getID()) : (_records[j].getID() > _records[target].getID()))
                    target = j;
            }
            else if(field == DATE)
            {
                if( (ascending) ? (_records[j].getDate_t() < _records[target].getDate_t()) : (_records[j].getDate_t() > _records[target].getDate_t()))
                    target = j;
            }
            else if(field == AMOUNT)
            {
                if( (ascending) ? (_records[j].getAmount() < _records[target].getAmount()) : (_records[j].getAmount() > _records[target].getAmount()))
                    target = j;
            }
            else if(field == TYPE)
            {
                if( (ascending) ? (_records[j].getType() < _records[target].getType()) : (_records[j].getType() > _records[target].getType()))
                    target = j;
            }
            else if(field == CATEGORY)
            {
                if( (ascending) ? (_records[j].getCategory() < _records[target].getCategory()) : (_records[j].getCategory() > _records[target].getCategory()))
                    target = j;
            }
            else if(field == ACCOUNT)
            {
                if( (ascending) ? (_records[j].getAccount() < _records[target].getAccount()) : (_records[j].getAccount() > _records[target].getAccount()))
                    target = j;
            }
        }
        if(i!=target)
            swapRecords(i, target);
    }
}

Records * Records::searchRecords(Field field, std::string keyword)
{
    // Capitalize keyword, so that the search is case-insensitive
    for(auto &c : keyword)
        c=toupper(c);

    Records *result = new Records;
    unsigned int num_of_records = countRecord();
    for(unsigned int i=0; i<num_of_records; i++)
    {
        std::string FieldContent;
        Record *candidate = getRecord(i); // never change candidate, it points to original record
        if(field == ID)
        {
            FieldContent = std::to_string(candidate->getID());
        }
        else if(field == DATE)
        {
            FieldContent = candidate->getDate();
        }
        else if(field == AMOUNT)
        {
            FieldContent = std::to_string(candidate->getAmount());
        }
        else if(field == TYPE)
        {
            FieldContent = candidate->getType();
        }
        else if(field == CATEGORY)
        {
            FieldContent = candidate->getCategory();
        }
        else if(field == ACCOUNT)
        {
            FieldContent = candidate->getAccount();
        }
        else if(field == REMARK)
        {
            FieldContent = candidate->getRemark();
        }

        if(FieldContent.find(keyword) != std::string::npos) // FieldContent contain keyword
        {
            result->addRecord(*candidate); // add i-th target to result
            result->getRecord(result->countRecord()-1)->setID(candidate->getID()); // ID of result = ID  of the original record
        } 
    }
    return result;
}