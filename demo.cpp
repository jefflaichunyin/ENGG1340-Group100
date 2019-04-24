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
        cout << r->getID() << " " << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << " " << r->getType() << endl;
    }
}
int main()
{
    //create object user_account for user management
    UserAccounts user_account;
    // load login info
    user_account.loadUserInfo();
    // Create user
    user_account.addUser("Jeff" , "12345");         // create new user -> sucess
    user_account.addUser("Jeff" , "12345");         // try to create new user using existing username -> fail


    // Create new records
    Record *r = new Record();
    r->setAccount("credit card");
    r->setType("expense");
    r->setAmount(10);
    r->setCategory("toys");
    // Add new record to user
    User *user = user_account.getUser("Jeff");
    user->getUserRecords()->addRecord(*r); // <- Preferred for sure

    // Alternatively, but not recommended
    Records *userRecords = user->getUserRecords();
    userRecords->addRecord(*r);

    r->setAccount("bank");
    r->setAmount(200);
    r->setType("expense");
    r->setCategory("food");
    userRecords->addRecord(*r);

    r->setAccount("bank");
    r->setAmount(3200);
    r->setType("income");
    r->setCategory("");
    userRecords->addRecord(*r);

    r->setAccount("cash");
    r->setAmount(3000);
    r->setType("expense");
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

    cout << "sort by id ascending\n";
    userRecords->sortRecords(ID, true);
    printRecords(userRecords);

    cout << "search for category = food\n";
    // userRecords create a new set of records containing the result and return a pointer pointing to those records
    // deleting the result won't affect user existing records
    Records *result = userRecords->searchRecords(CATEGORY,"FOOD");
    printRecords(result);
    delete result; // size of result may be large, must delete everytime
    result = nullptr;
    cout << "search for amount = 3000\n";
    result = userRecords->searchRecords(AMOUNT,"3000");
    printRecords(result);
    delete result; // size of result may be large, must delete everytime
    result = nullptr;
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
    cout << "Total income: " << user->getTotalIncome() << endl;
    cout << "Total expense: " << user->getTotalExpense() << endl;
    cout << "Grand total: " << user->getTotalIncome() - user->getTotalExpense() << endl << endl;

    cout << "Monthly income: " << user->getMonthlyIncome() << endl;
    cout << "Monthly expense: " << user->getTotalExpense() << endl;
    cout << "Monthly total: " << user->getTotalIncome() - user->getTotalExpense() << endl;

    user->setSavingGoal(1000,12,2019);

    cout << "\ndeadline: " << user->getDeadline() << endl;
    cout << "monthly goal: " << user->getMonthlyGoal() << endl;
    cout << "monthly quota: " << user->getMonthlyQuota() << endl;
    // save user reocrds
    user->saveRecords();
    // save login info
    user_account.saveUserInfo();
    return 0;
}