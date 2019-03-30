#include <iostream>
#include <string>
#include <ctime>

#include "records.h"
using namespace std;
int main()
{
    Records JeffRecords;
    Record *r = NULL;
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

    return 0;
}