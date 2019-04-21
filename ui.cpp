#include "user.h"
#include "ui.h"
using namespace std;

void clrscr(){
    cout << string(100,'\n');

}

int uimenu1(void){
    int choice; 
    cout << "1. Add record\t";
    cout << "2. Edit record\t";
    cout << "3. Filter record\n";
    cout << "4. Sort record\t";
    cout << "5. Delete record\t";
    cout << "6. Log out\n";
    cout << endl;
    cout<<"Make your choice: ";
    cin>> choice;
    cout << endl;
    return choice;
}

void uiprintrecord(string username,UserAccounts user_accounts){

       User *user = user_accounts.getUser(username);
                user->loadRecords(); 
                 Records *userRecords = user->getUserRecords();
    for(unsigned int i=0; i<userRecords->countRecord(); i++)
    {
        Record *r=userRecords->getRecord(i);
        cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;

    }
    cout << endl;
    
}

void startUI()
{
    int choice=0;
    string *username= new string;    //need to delete!!!
    string *userpw= new string;
    UserAccounts user_accounts;
    
    cout << "start\n";  
    while(choice!=3){
        cout << "1. Log in\n2. Create account\n3. Exit"<<endl;
        
        cin >> choice;   //get user preference
        if(choice==1){   //log in
        cin.ignore();  //ignore \n in read buffer
        cout<<"User name: ";
        getline(cin,*username);
        cout << endl; 
        cout << "User password: ";
        getline(cin, *userpw);
        cout << endl;
        if(user_accounts.loadUserInfo()){ 
            if(user_accounts.checkPassword(*username,*userpw)){ 
                User *user = user_accounts.getUser(*username);
                //user->loadRecords();   

                bool logout=false;
                while(!logout){ 
                uiprintrecord(*username,user_accounts);

                int recordway = uimenu1();
                Record *r = new Record();

                switch(recordway){  //see what the users want to do after log in
                    case 1:
                    //have to print all the account type!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    r->setAccount("credit card");
                    r->setAmount(1000);
                    r->setCategory("toys");
                    user->getUserRecords()->addRecord(*r);
                    delete r;
                    break;
                    case 5:
                    user->getUserRecords()->deleteRecord(0); // 2nd record will become 1st record after deletion
                    break;

                    case 6:
                    logout=true;  //log out
                    user->saveRecords();
                    break;
                    default:
                    cout << "No such a choice. Please try again!" <<endl;
                    break;
                }

            }
            }
          
            
        }

    }

    if (choice==2){    //create new account
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
        cout<< user_accounts.addUser(*username,*userpw)<<endl;
        //cout<<string(100,'\n');

        user_accounts.saveUserInfo();
        User(*username, *userpw);
        

        }

    }
}
