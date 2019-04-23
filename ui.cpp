#include "ui.h"

using namespace std;

void ClearScreen() 
{ 
	cout << string(100, '\n'); 
}

void printRecord(User *user)
{
    Records *userRecords = user->getUserRecords();
    for (unsigned int i = 0; i < userRecords->countRecord(); i++)
	{
	    Record *r = userRecords->getRecord(i);
	    cout << i+1 << ". " << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() << setw(2)<<"$"<<setw(10)<<left<< r->getAmount() << endl;

	}
    cout << endl;
}

void getRecordDetails(Record * &r)
{
	string account,category;
	float amount;
	cin.ignore();
	cout << "Account: ";
	getline(cin,account);
	cout << endl;
	cout << "Category: ";
	getline(cin,category);
	cout << endl;
	cout << "Amount: ";
	cin >> amount;
	cout << endl;

	r->setAccount(account);
	r->setAmount(amount);
	r->setCategory(category);
}

void EditUserRecord(User *user)
{
	int EditRecordNo;
	printRecord(user);
	cout << "Number of record to be edit: ";
	cin >> EditRecordNo;
	cout << endl;

	EditRecordNo-=1; //The number of records printed start from 1

	Record *q = new Record();
	
	getRecordDetails(q);
	user->getUserRecords()->replaceRecord(EditRecordNo, *q);


}

int printUserManagementItems()
{
	int userpreference;
	cout << "1. Change password\n";
	cout << "2. Delete user account permanently\n";
	cout << endl;

	cout << "Your choice: ";
	cin >> userpreference;
	return userpreference;

}

int Menu1(void)
{
    int choice;
    cout << "1. Add record\t";
    cout << "2. Edit record\t\t";
    cout << "3. Filter record\n";
    cout << "4. Sort record\t";
    cout << "5. Delete record\t";
    cout << "6. Manage user account\n";
    cout << "7. Log out\n";
    cout << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}

void startUI()
{
    int choice = 0;
    string *username = new string; // need to delete!!!
    string *userpw = new string;
    UserAccounts user_accounts;
	string newpassword;
    int executetime = 1;
	ClearScreen();
    cout << "start\n";
    while (choice != 3)
	{
	    cout << endl;
	    cout << "1. Log in\n";
	    cout << "2. Create account\n";
	    cout << "3. Exit" << endl;

		cout << endl ;

		cout << "Your choice: " ;
	    cin >> choice; // get user choice

		cout << endl;


	    if (choice == 1)
		{	
			// log in
		    cin.ignore(); // ignore \n in read buffer
		    cout << "User name: ";
		    getline(cin, *username);
		    cout << endl;
		    cout << "User password: ";
		    getline(cin, *userpw);
		    cout << endl;
		    if (!user_accounts.loadUserInfo())
			{
				continue;
			}
			if (!user_accounts.checkPassword(*username, *userpw))
			{
				continue;
			}
			cout << "Password correct.\n";
			User *user = user_accounts.getUser(*username);

			if (executetime == 1)
			{
				user->loadRecords();
				executetime++;
			}

			bool logout = false;
			while (!logout)
			{
				printRecord(user);

				switch (Menu1())
				{ // see what the users want to do after log in
				case 1:
				{
					// have to print all the account
					// type!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					Record *r = new Record(); //delete after use
					getRecordDetails(r);  //no *r
					user->getUserRecords()->addRecord(*r);
					delete r;							
				}

				break;
				case 2:
					EditUserRecord(user);
				
					break;
				case 3:

					break;
				case 4:

					break;
				case 5:
					user->getUserRecords()->deleteRecord(0); // 2nd record will become 1st record after
											// deletion
					break;

				case 6:
					int action;
					action = printUserManagementItems();
					switch(action)
					{
						case 1:

							cin.ignore();
							cout << "New password: ";
							getline(cin, newpassword);
							cout << endl;
							cout << user_accounts.changePassword(*username, *userpw, newpassword) << endl;
							cout << user_accounts.checkPassword(*username, newpassword) << endl;
							
						break;
						case 2:
							user_accounts.removeUser(*username, *userpw);
							logout = true;
							user_accounts.saveUserInfo();
							break;
						default:
						cout << "Not a valid choice." <<endl;
						break;
					}
					cout << endl;
					break;
				case 7:
					logout = true; // log out
					user->saveRecords();
					break;
				default:
					cout << "No such a choice. Please try again!" << endl;
					break;
				}
			}

			 

		}

	    if (choice == 2)
		{				       // create new account
		    string *verification = new string; // double data entry for password
		    cin.ignore();		       // ignore \n in read buffer
		    cout << "User name: ";
		    getline(cin, *username);
		    cout << endl;
		    cout << "Password: ";
		    getline(cin, *userpw);
		    cout << endl;
		    cout << "Please type the password again: ";
		    getline(cin, *verification);

		    if (*userpw == *verification)
			{
			    if (user_accounts.addUser(*username, *userpw))
				cout << "User " << *username << " is created sucessfully\n";
			    else
				cout << "User " << *username << " already exist! Please choose another username.\n";

			    user_accounts.saveUserInfo();
			    User(*username, *userpw);
			}
		    else
			{
			    cout << "Please input the same password twice." << endl;
			}
		}
	}
    user_accounts.saveUserInfo();
}
