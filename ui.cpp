#include "user.h"
#include "ui.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int lorc=0;
    //UserAccounts user_accounts;
    cout << "start\n";
    cout << "1. Log in\n2. Create account"<<endl;
    while(lorc!=1 && lorc!= 2){
        cin >> lorc;   //get user preference
    //if(lorc==1){
       // if(user_account.loadUserInfo())
    //}

    if (lorc==2){
        string *username= new string;
        string *userpw= new string;
        string *verification = new string; //double data entry for password
        cout << "User name: " <<endl;
        //fflush(stdout);
        getline(cin,*username);
        cout << "User password: " <<endl;
        //maskuserpw(*userpw);
        cin >> *userpw;
        cout << "input user password again: " <<endl;
       // maskuserpw(*verification);
        cin >> *verification;
        cout<<*username<<" "<<*userpw<<endl;
        }

    }
}
