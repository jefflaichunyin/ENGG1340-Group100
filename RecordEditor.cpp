using namespace std;

void ClearScreen() 
{ 
	std::cout << std::string(100, '\n'); 
}

void printRecord(Records *userRecords)
{
    for (unsigned int i = 0; i < userRecords->countRecord(); i++)
	{
	    Record *r = userRecords->getRecord(i);
	    cout << r->getID() << ". " << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() << setw(2)<<"$"<<setw(10)<<left<< r->getAmount() << endl;

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
	int id;
	printRecord(user->getUserRecords());
	cout << "Please enter the ID of the record: ";
	cin >> id;
	cout << endl;

	Record *new_record = new Record();
	getRecordDetails(new_record);
	new_record->setID(id);
	user->getUserRecords()->replaceRecord(id-1, *new_record);
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

void RecordsEditor(UserAccounts &user_accounts, string &username, string &userpw)
{
	bool logout = false;
	User *user = user_accounts.getUser(username);
	user->loadRecords();
	while (!logout)
	{
		printRecord(user->getUserRecords());
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
				break;							
			}
			case 2:
			{
				if(user->getUserRecords()->countRecord()==0)
					cout << "No record at the moment, please add some records first.\n";
				else
					EditUserRecord(user);
				break;				
			}
			case 3:
			{
				break;				
			}
			case 4:
			{
				break;				
			}
			case 5:
			{
				user->getUserRecords()->deleteRecord(0); // 2nd record will become 1st record after deletion
				break;				
			}
			case 6:
			{
				int action;
				action = printUserManagementItems();
				switch(action)
				{
					case 1:
					{
						string newpassword;
						cin.ignore();
						cout << "New password: ";
						getline(cin, newpassword);
						cout << endl;
						cout << user_accounts.changePassword(username, userpw, newpassword) << endl;
						cout << user_accounts.checkPassword(username, newpassword) << endl;		
						break;			
					}
					case 2:
					{
						user_accounts.removeUser(username, userpw);
						logout = true;
						user_accounts.saveUserInfo();
						break;						
					}
					default:
					{
						cout << "Not a valid choice." <<endl;
						break;						
					}
				}
				cout << endl;
				break;				
			}
			case 7:
			{
				logout = true; // log out
				user->saveRecords();
				break;				
			}
			default:
			{
				cout << "No such a choice. Please try again!" << endl;
				break;				
			}
		}
	}
	user->unloadRecords();
}