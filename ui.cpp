#include "user.h"
#include "ui.h"
using namespace std;
void startUI()
{
    cout << "start\n";

    UserAccounts user_accounts;
    user_accounts.addUser("Jeff", "123");
    Record *new_record = new Record();
    new_record->setAccount("Bank");
    user_accounts.getUser("Jeff")->getUserRecords()->addRecord(*new_record);
    delete new_record;
    
    cout << user_accounts.getUser("Jeff")->getUserRecords()->getRecord(0)->getAccount();
    
}