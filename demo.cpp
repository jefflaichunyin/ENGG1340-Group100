#include <iostream>
#include <string>
#include <ctime>
#include "record.h"
using namespace std;
int main()
{
    Record r1;

    r1.setAmount(1000);
    r1.setCategory("food");

    cout << r1.getAmount() << endl;
    cout << r1.getCategory() << endl;
    return 0;
}