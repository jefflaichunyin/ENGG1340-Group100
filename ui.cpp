#include "user.h"
#include "ui.h"
using namespace std;
void startUI()
{
    cout << "start\n";

    UserAccounts user_accounts;
    user_accounts.addUser("kiwi", "234");
    user_accounts.addUser("jeff","123");
    Record *new_record = new Record();
    new_record->setAccount("Bank");
    user_accounts.getUser("kiwi")->getUserRecords()->addRecord(*new_record);
    delete new_record;


    cout << user_accounts.getUser("kiwi")->getUserRecords()->getRecord(0)->getAccount();

}
