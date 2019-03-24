#include "record.hpp"
#include <cctype>
#include <cstring>




//getters
time_t Record::getDate(){return _date;}
float Record::getAmount(){return _amount;}
std::string Record::getType(){return _type;}
std::string Record::getAccount(){return _account;}
std::string Record::getRemark(){return _remark;}
std::string Record::getCategory(){return _category;}
//setters
bool Record::setDate(time_t date)
{
    _date=date;
    return true;
}
bool Record::setAmount(float amount)
{
    if(amount>0) //valid
    {
        _amount=amount;
        return true;
    }
    else //you can't earn/spend 0 or negative amount of dollar
    {
        return false;
    }
}
bool Record::setType(std::string type)
{
    for(auto &c : type)
        c=toupper(c);
    if(type == "INCOME" || type == "EXPENSE")
    {
        _type=type;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool Record::setCategory(std::string category)
{
    for(auto &c : category)
        c=toupper(c);
    _category=category;
    return true;
}
bool Record::setAccount(std::string account)
{
    for(auto &c : account)
        c=toupper(c);
    _account=account;
    return true;
}
bool Record::setRemark(std::string remark)
{
    _remark=remark;
    return true;
}

//default initialization of a record
Record::Record()
{
    time_t now=time(0);
    setDate(now);
    _amount=-1; //undefined
    setType("");
    setCategory("");
    setAccount("");
    setRemark("");
}

Record::Record(time_t date, float amount, std::string type, std::string category, std::string account, std::string remark)
{
    setDate(date);
    setAmount(amount);
    setType(type);
    setCategory(category);
    setAccount(account);
    setRemark(remark);
}