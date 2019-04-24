#include "ui.h"
#include "RecordEditor.cpp"
using namespace std;

void createNewAccount(UserAccounts &user_accounts)
{
	string username, password, verification;// double data entry for password
	cin.ignore();		       // ignore \n in read buffer
	ClearScreen();
	cout << "User name: ";
	getline(cin, username);
	cout << endl;
	cout << "Password: ";
	getline(cin, password);
	cout << endl;
	cout << "Please type the password again: ";
	getline(cin, verification);

	if (password == verification)
	{
		if (user_accounts.addUser(username, password))
		cout << "User " << username << " is created sucessfully\n";
		else
		cout << "User " << username << " already exist! Please choose another username.\n";
		User(username, password);
		user_accounts.saveUserInfo();
	}
	else
	{
		cout << "Please input the same password twice." << endl;
		createNewAccount(user_accounts); // ask user to create the account again
	}
}

void startUI()
{
    int choice = 0;
    string username;
    string userpw;
    UserAccounts user_accounts;

	ClearScreen();
    cout << "start\n";
    while (choice != 3)
	{
	    cout << endl;
	    cout << "1. Log in\n";
	    cout << "2. Create account\n";
	    cout << "3. Exit" << endl << endl;
		cout << "Your choice: " ;
	    cin >> choice; // get user choice
		cout << endl;

	    if (choice == 1)
		{	
			if (!user_accounts.loadUserInfo()) // first run, no existing user
			{
				cout << "Welcome to SaveNow. Please press 2 to create a new user.\n";
				continue;
			}
			// log in
		    cin.ignore(); // ignore \n in read buffer
			ClearScreen();
		    cout << "User name: ";
		    getline(cin, username);
		    cout << endl;
		    cout << "User password: ";
		    getline(cin, userpw);
		    cout << endl;

			if (!user_accounts.checkPassword(username, userpw)) // password is incorrect
			{
				continue;
			}
			cout << "Password correct.\n";
			cout << endl;
			RecordsEditor(user_accounts, username, userpw);
		}
	    if (choice == 2)
		{				       // create new account
			createNewAccount(user_accounts);
		}
	}
    user_accounts.saveUserInfo();
}
