#include <iostream>
#include <string>
#include <ctime>

#include "user.h"

using namespace std;
int main()
{
    //create object user_account for user management
    UserAccounts user_account;
    // Create user
    cout << user_account.addUser("Jeff" , "12345") << endl;         // create new user -> sucess
    cout << user_account.addUser("Jeff" , "12345") << endl;         // try to create new user using existing username -> fail
    // Check password
    cout << user_account.checkPassword("Jeff", "54321") << endl;    // try to check an incorrect pwd
    cout << user_account.checkPassword("Jeff", "12345") << endl;    // try to check an correct pwd
    cout << user_account.checkPassword("Kiwi", "abc") <<endl;       // try to check the password of a non-existent user
    // Change password
    cout << user_account.changePassword("Jeff", "12345", "54321") << endl;
    cout << user_account.checkPassword("Jeff", "54321") << endl;
    
    // Create new records
    Record *r = new Record();
    r->setAccount("credit card");
    r->setAmount(1000);
    r->setCategory("toys");
    // Add new record to user
    user_account.getUser("Jeff", "54321")->getUserRecords()->addRecord(*r); // <- Preferred for sure
    // Alternatively, but not recommended
    User *Jeff = user_account.getUser("Jeff", "54321");
    Records *JeffRecords = Jeff->getUserRecords();
    JeffRecords->addRecord(*r);

    delete r; // record is added, no longer useful, delete it to save memory
    // print records
    for(unsigned int i=0; i<JeffRecords->countRecord(); i++)
    {
        Record *r=JeffRecords->getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }
    Jeff->getUserRecords()->deleteRecord(0); // delete the first record
    // print record
    cout << "After deleting first record\n";
    for(unsigned int i=0; i<JeffRecords->countRecord(); i++)
    {
        Record *r=JeffRecords->getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }
    // NEVER DELETE A POINTER THAT POINT TO DATA INSIDE User/Records/Record!!!! Use removeXXX() or deleteYYY() instead;
    delete Jeff; 
    // Only remove pointer that points to an object created by yourself
    // e.g. Record *r = new Record(); you can do delete r; because you create it

    cout << "Unexpected error will occur below\n";
    for(unsigned int i=0; i<JeffRecords->countRecord(); i++)
    {
        Record *r=JeffRecords->getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }

    return 0;
}