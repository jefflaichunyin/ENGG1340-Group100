#include <iostream>
#include <string>
#include <ctime>

#include "records.h"
using namespace std;
int main()
{

    Records JeffRecords;
    Record *r = nullptr;
    r = new Record();
    r->setAccount("credit card");
    r->setAmount(1000);
    r->setCategory("toys");

    JeffRecords.addRecord(*r); // content of r will be copied to JeffRecords
    delete r;

    // add another record
    r = new Record();
    r->setAccount("octopus");
    r->setAmount(6.6);
    r->setCategory("mtr");
    JeffRecords.addRecord(*r);
    delete r;

    for(unsigned int i=0; i<JeffRecords.countRecord(); i++)
    {
        Record *r=JeffRecords.getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }
    cout << endl;
    JeffRecords.deleteRecord(1); // delete the 2nd record
    JeffRecords.getRecord(0)->setAmount(800); // modify 1st record
    for(unsigned int i=0; i<JeffRecords.countRecord(); i++)
    {
        Record *r=JeffRecords.getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }

    return 0;
}