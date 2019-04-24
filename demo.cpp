#include <iostream>
#include <string>
#include <ctime>

//#include "user.h"
#include "user_account.h"

using namespace std;


void printRecords(Records *userRecords)
{
    // print records
    for(unsigned int i=0; i<userRecords->countRecord(); i++)
    {
        Record *r=userRecords->getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    }
}
int main()
{
    //create object user_account for user management
    UserAccounts user_account;
    // load login info
    user_account.loadUserInfo();
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
    
    // Load user records
    User *user = user_account.getUser("Jeff");
    user->loadRecords();

    // Create new records
    Record *r = new Record();
    r->setAccount("credit card");
    r->setAmount(10);
    r->setCategory("toys");
    // Add new record to user

    user->getUserRecords()->addRecord(*r); // <- Preferred for sure

    // Alternatively, but not recommended
    Records *userRecords = user->getUserRecords();
    userRecords->addRecord(*r);

    r->setAccount("bank");
    r->setAmount(200);
    r->setCategory("food");
    userRecords->addRecord(*r);

    r->setAccount("cash");
    r->setAmount(3000);
    r->setCategory("gadget");
    userRecords->addRecord(*r);

    delete r; // record is added, no longer useful, delete it to save memory

    printRecords(userRecords);
    // delete the first record
    // user->getUserRecords()->deleteRecord(0); // 2nd record will become 1st record after deletion

    // print record
    cout << "sort by date\n";
    userRecords->sortRecords(DATE, false);
    printRecords(userRecords);

    cout << "sort by amount\n";
    userRecords->sortRecords(AMOUNT, false);
    printRecords(userRecords);

    cout << "sort by category\n";
    userRecords->sortRecords(CATEGORY, false);
    printRecords(userRecords);

    cout << "sort by account\n";
    userRecords->sortRecords(ACCOUNT, false);
    printRecords(userRecords);

    // NEVER DELETE A POINTER THAT POINT TO DATA INSIDE User/Records/Record!!!! Use removeXXX() or deleteYYY() instead;
    // delete Jeff; 
    // Only remove pointer that points to an object created by yourself
    // e.g. Record *r = new Record(); you can do delete r; because you create it

    // cout << "Unexpected error will occur below\n";
    // for(unsigned int i=0; i<JeffRecords->countRecord(); i++)
    // {
    //     Record *r=JeffRecords->getRecord(i);
    //     cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
    // }

    
    // save user reocrds
    user->saveRecords();
    // save login info
    user_account.saveUserInfo();
    return 0;
}