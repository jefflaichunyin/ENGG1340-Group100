#include <cstdio>
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
	    cout <<left<< setw(4)<< r->getID() << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() << setw(2)<<"$"<<setw(10)<<left<< r->getAmount() << endl;

	}
    cout << endl;
}

void getRecordDetails(Record * &r)
{
	string account,category;
	float amount;
	//cin.ignore();
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

void DeleteUserRecord(User *user)
{
	int id;
	printRecord(user->getUserRecords());
	cout << "Please enter the ID of the record: ";
	cin >> id;
	cout << endl;

	user->getUserRecords()->deleteRecord(id-1); // e.g. 2nd record will become 1st record after deletion
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

bool InputValidation(char checkdigit)
{
	if(checkdigit>48 && checkdigit<58)
	return true;
	else
	{
		return false;
	}
	
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
				char RecordType[20];
				int i=0;
				cin.ignore();
				// have to print all the account
				// type!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				cout << "1. income\n";
				cout << "2. expense\n";
				cout << "3. transfer\n";
				//allow user to input more than one characters
				//but only count the first character
				cout << "Your choice: ";
				do{
					RecordType[i]=getchar();
					i++;
				}while (i<20 && RecordType[i-1]!='\n');
				
				cout << endl;

				//avoid invalid input crash the programme
				if(InputValidation(RecordType[0])){  //input validation
					if(int(RecordType[0])-48 == 1){
					
					Record *r = new Record(); //delete after use
					getRecordDetails(r);  //no *r
					r->setType("income");
					user->getUserRecords()->addRecord(*r);

					delete r;
					}
					else if(int(RecordType[0])-48 == 2)
					{
						Record *r = new Record(); //delete after use
						getRecordDetails(r);  //no *r
						r->setType("expense");
						user->getUserRecords()->addRecord(*r);

					}
					else if(int(RecordType[0])-48 ==3)
					{
						cout << "not yet\n";
					}
					else 
					cout << "Invalid input. Please try again.1\n";
					}
				else
				{
					cout <<"Invalid input. Please try again\n";
				}
				
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
				int SortField;
				bool SortOrder;
				int InputOrder;

				cout << "1. Date\n";
				cout << "2. Amount\n";
				cout << "3. Category\n";
				cout << "4. Account\n";
				cout << "Sort by: ";
				cin >> SortField;
				cout << endl;
				cout << "1. Ascending order\n";
				cout << "2. Descending order\n";
				cin >> InputOrder;
				cout << endl;
				
				if(InputOrder==1)
				SortOrder=true;
				else if (InputOrder==2)
				SortOrder=false;
				switch(SortField){
					case 1:
					user->getUserRecords()->sortRecords(DATE, SortOrder);
					break;
					case 2:
					user->getUserRecords()->sortRecords(AMOUNT, SortOrder);		
					break;
					case 3:
					user->getUserRecords()->sortRecords(CATEGORY, SortOrder);
					break;
					case 4:
					user->getUserRecords()->sortRecords(ACCOUNT, SortOrder);;
					break;
					case 5:
					user->getUserRecords()->sortRecords(ID, SortOrder);
					break;
					default:
					cout << "Invalid input!\n";
					break;	
				}
				//check invalid input
				/*else
				{
					cout << "Please input a valid number\n";
					cout << endl;
				}*/
				
				break;				
			}
			case 5:
			{	
				if(user->getUserRecords()->countRecord()==0)
					cout << "No record at the moment, please add some records first.\n";
				else{
					user->getUserRecords()->sortRecords(ID, true);
					DeleteUserRecord(user);					
				}				
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