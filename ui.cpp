#include "user.h"
#include "ui.h"
#include <iostream>
#include <string>
using namespace std;
void startUI()
{
    int choice=0;
    //UserAccounts user_accounts;
    cout << "start\n";
    cout << "1. Log in\n2. Create account"<<endl;
    while(choice!=1 && choice!= 2){
        cin >> choice;   //get user preference
    //if(lorc==1){
       // if(user_account.loadUserInfo())
    //}

    if (choice==2){
        string *username= new string;
        string *userpw= new string;
        string *verification = new string; //double data entry for password
        cin.ignore(); //ignore \n in read buffer
        cout << "User name: ";
        getline(cin,*username);
        cout << endl;
        cout << "User password: ";
        getline(cin, *userpw);
        cout << endl;
        cout << "input user password again: ";
        getline(cin, *verification);
        cout << *username << " " << *userpw << endl;
        }

    }
}
