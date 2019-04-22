#include "ui.h"
#include "user.h"
using namespace std;

void clearScreen() { cout << string(100, '\n'); }

int Menu1(void)
{
    int choice;
    cout << "1. Add record\t";
    cout << "2. Edit record\t\t";
    cout << "3. Filter record\n";
    cout << "4. Sort record\t";
    cout << "5. Delete record\t";
    cout << "6. Log out\n";
    cout << "7. Delete accout permanently\n";
    cout << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}

void printRecord(User *user)
{
    Records *userRecords = user->getUserRecords();
    for (unsigned int i = 0; i < userRecords->countRecord(); i++)
	{
	    Record *r = userRecords->getRecord(i);
	    cout << r->getDate() << " " << r->getAccount() << " " << r->getCategory() << " " << r->getAmount() << endl;
	}
    cout << endl;
}

void startUI()
{
    int choice = 0;
    string *username = new string; // need to delete!!!
    string *userpw = new string;
    UserAccounts user_accounts;
    int executetime = 1;
    cout << "start\n";
    while (choice != 3)
	{
	    cout << endl;
	    cout << "1. Log in\n";
	    cout << "2. Create account\n";
	    cout << "3. Exit" << endl;

	    cin >> choice; // get user preference
	    if (choice == 1)
		{		  // log in
		    cin.ignore(); // ignore \n in read buffer
		    cout << "User name: ";
		    getline(cin, *username);
		    cout << endl;
		    cout << "User password: ";
		    getline(cin, *userpw);
		    cout << endl;
		    if (user_accounts.loadUserInfo())
			{
			    if (user_accounts.checkPassword(*username, *userpw))
				{
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

					    int recordway = Menu1();
					    Record *r = new Record();

					    switch (recordway)
						{ // see what the users want to do after log in
						case 1:
						    // have to print all the account
						    // type!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						    r->setAccount("credit card");
						    r->setAmount(1000);
						    r->setCategory("toys");
						    user->getUserRecords()->addRecord(*r);
                            delete r;
					    break;
						case 2:

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
						    logout = true; // log out
						    user->saveRecords();
						    break;
						case 7:
						    user_accounts.removeUser(*username, *userpw);
						    logout = true;
                            user_accounts.saveUserInfo();
						    break;
						default:
						    cout << "No such a choice. Please try again!" << endl;
						    break;
			
						}
					}
				}
			    else
				{
				    cout << "Incorrect password. Please try again." << endl;
				}
			}
		    else
			{
			    cout << "User " << *username << " does not exist.\n";
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
		    // cout << *username << " " << *userpw << endl;
		    if (*userpw == *verification)
			{
			    if (user_accounts.addUser(*username, *userpw))
				cout << "User " << *username << " is created sucessfully\n";
			    else
				cout << "User " << *username << " already exist! Please choose another username.\n";
			    // cout<<string(100,'\n');

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
