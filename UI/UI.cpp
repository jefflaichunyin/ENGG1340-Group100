#define MIN_USERNAME_LENGTH 4
#define MAX_USERNAME_LENGTH 255
#define MIN_PASSWORD_LENGTH 4
#define MAX_PASSWORD_LENGTH 255
#define MAX_STRING_LEN 15
#define MIN_STRING_LEN 1

#include "UI.h"

using namespace std;
UserAccounts user_accounts;
#include "ui_tools.cpp"
#include "Homepage.cpp"



void createNewAccount()
{
	string username, password, verification;// double data entry for password
	bool SUCCESS = false;
	ClearScreen();
	while(!SUCCESS)
	{
		username = validatedString("\nUsername: ", MIN_USERNAME_LENGTH, MAX_USERNAME_LENGTH);
		password = validatedString("Password: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
		verification = validatedString("Please type the same password again: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);

		if (password == verification)
		{
			if (user_accounts.addUser(username, password))
			{
				cout << "User " << username << " is created sucessfully\n";
				SUCCESS = true;
				user_accounts.saveUserInfo();
			}
			else
			{
				cout << "User " << username << " already exist! Please choose another username.\n";
				SUCCESS = false;
			}
		}
		else
		{
			cout << "The second input doesn't match the first input. Please try again." << endl;
			SUCCESS = false;
		}
	}
}

void Login()
{
	
	bool SUCCESS = false;
	unsigned int trials = 0;
	string username, password;
	ClearScreen();
	while(!SUCCESS && trials < 3)
	{
		username = validatedString("Username: ", MIN_USERNAME_LENGTH, MAX_USERNAME_LENGTH);
		password = validatedString("Password: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
		if(user_accounts.searchUser(username) == -1) // user doesn't exist
		{
			cout << username << " does not exist. Please create it first.\n" << endl;
			Pause();
			UI();
		}
		else // user exist
		{
			if(user_accounts.checkPassword(username, password)) // password correct
			{
				SUCCESS = true;
			}
			else // password incorrect
			{
				trials++;
			}
		}
	}

	if(SUCCESS)
	{
		ClearScreen();
		Homepage(user_accounts.getUser(username));
	}
	else if(trials>=3)
	{
		cout << "\nYour have entered the wrong password for three times. Please try again later.\n";
		Pause();

		UI();
	}
}

void UI()
{
    int choice = 0;
	ClearScreen();
	cout << "Welcome to SaveNow.\n";
	while(true)
	{
		string message = 
		"1. Login\n"
		"2. Create account\n"
		"3. Exit\n\n"
		"Enter your choice: ";
		choice = validatedInt(message, 1, 3);
		if (choice == 1)
		{	
			if (!user_accounts.loadUserInfo()) // first run, no existing user
			{
				cout << "\nNo existing user is found. Please press 2 to create a new user.\n";
				Pause();
			}
			else
			{
				Login();
				user_accounts.saveUserInfo();
				ClearScreen();
			}
		}
		else if (choice == 2)
		{	 // create new account
			createNewAccount();
			user_accounts.saveUserInfo();
		}
		else if (choice == 3)
		{
			user_accounts.saveUserInfo();
			cout << "\nAll data is saved\n";
			cout << "Goodbye!\n";
			exit(0);
		}
	}

}