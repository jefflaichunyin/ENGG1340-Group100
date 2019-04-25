#include <cstdio>
using namespace std;

void ClearScreen() 
{ 
	std::cout << std::string(100, '\n'); 
}

void printRecord(Records *userRecords)
{
    
	cout <<left<< setw(4)<< "ID" <<setw(25)<< "DATE" << " " << setw(18)<< left <<"ACCOUNT" <<setw(18)<< left<< "CATEGORY" << setw(15)<<left<< "AMOUNT" <<setw(8) << "TYPE"<< endl;
	cout <<"---------------------------------------------------------------------------------------------"<< endl;
	for (unsigned int i = 0; i < userRecords->countRecord(); i++)
	{
	    Record *r = userRecords->getRecord(i);
	    cout <<left<< setw(4)<< r->getID() << setw(25) << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() << setw(2)<<"$"<<setw(13)<<left<< fixed <<setprecision(2)<< r->getAmount() << setw(8) << r->getType() << endl;

	}
    cout << endl;
}

void SortorSearchMenu()
{
	cout << "1. Date\n";
	cout << "2. Amount\n";
	cout << "3. Category\n";
	cout << "4. Account\n";
	cout << "5. ID\n";
	cout << "6. Type\n";
}

bool InputValidation(int &userinput)
{
	char TempInput[20];
	char checkdigit;
	int i=0;
	cout << "Your choice: ";
	do{
		TempInput[i]=getchar();
		i++;
	}while (i<20 && TempInput[i-1]!='\n');				
	cout << endl;
	checkdigit=TempInput[0];
	if(checkdigit>48 && checkdigit<58)
	{
		userinput=int(checkdigit)-48;
		return true;
	}
	else
	{
		cout << "Invalid input.\n";
		cout << endl;
		return false;
	}
	
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
	Record *new_record = new Record();
	cout << "Please enter the ID of the record: ";
	cin >> id;

	new_record->setType(user->getUserRecords()->getRecord(id-1)->getType());
	cout << endl;
	cin.ignore();
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
	ClearScreen();
	int userpreference=0;
	cout << "1. Change password\n";
	cout << "2. Show monthly report\n";
	cout << "3. Set saving budget\n";
	cout << "4. Delete user account permanently\n";
	cout << endl;
	InputValidation(userpreference);
	return userpreference;
}

int printrecordmenu()
{
	int record=0;
	cout << "1. Add record\n";
	cout << "2. Edit record\n";
	cout << "3. Delete record\n";
	cout << "4. Exit\n";
	cout << endl;
	InputValidation(record);
	return record;
	
}

void getSavingDetails(User *user)
{
	user->getUserRecords();
	float amount;
	int month, year;
	string datetemp;
	cout << "Your saving target: ";
	cin >> amount;
	cout << endl;
	cout << "Deadline \n";
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
	cout << endl;

	user->setSavingGoal(amount,month,year);
    cout << "\ndeadline: " << user->getDeadline() << endl;
    cout << "monthly goal: " << user->getMonthlyGoal() << endl;
    cout << "monthly quota: " << user->getMonthlyQuota() << endl;

}

void printAccountMonthlyReport(User *user)
{
	ClearScreen();
	cout << "User name: " << user->getUsername() << endl;
	cout << endl;
    cout << "Monthly income / Total income : " << user->getMonthlyIncome() << " / " << user->getTotalIncome() << endl;
    cout << "Monthly expense / Total expense : " << user->getMonthlyExpense() << " / " << user->getTotalExpense()<< endl;
    cout << "Monthly total: " << user->getTotalIncome() - user->getTotalExpense() << endl;
	cout << endl; 

	cout <<left<< setw(4)<< "ID" <<setw(25)<< "DATE" << " " << setw(18)<< left <<"ACCOUNT" <<setw(18)<< left<< "CATEGORY" << setw(15)<<left<< "INCOME"<< setw(15)<<left<< "EXPENSE" <<endl;
	cout <<"---------------------------------------------------------------------------------------------"<< endl;
	for (unsigned int i = 0; i < user->getUserRecords()->countRecord(); i++)
	{
	    Record *r = user->getUserRecords()->getRecord(i);
		if(r->getType()=="INCOME")
		{
	    cout <<left<< setw(4)<< r->getID() << setw(25) << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() << setw(2)<<"$"<<setw(13)<<left<< fixed <<setprecision(2)<< r->getAmount() <<setw(15)<<" "<< endl;
		}
		else
		{
	    cout <<left<< setw(4)<< r->getID() << setw(25) << r->getDate() << " " << setw(18)<< left <<r->getAccount() <<setw(18)<< left<< r->getCategory() <<setw(15)<<" "<< setw(2)<<"$"<<setw(13)<<left<< fixed <<setprecision(2)<< r->getAmount() << endl;
		}
		cout << endl;
	}
		cout <<"---------------------------------------------------------------------------------------------"<< endl;
		cout << setw(66) << "Total " <<setw(2)<<"$"<< setw(13)<<left<< fixed <<setprecision(2)<<user->getMonthlyIncome() <<setw(2)<<"$"<< setw(13) <<left<< fixed <<setprecision(2)<< user->getMonthlyExpense()<<endl;
    cout << endl;
	
	/*cout << "INCOME: \n";
 	printRecord(user->getUserRecords()->searchRecords(TYPE,"INCOME"));
	cout << "- - -\n";
	cout << endl; 

	cout << "EXPENSE: \n";
 	printRecord(user->getUserRecords()->searchRecords(TYPE,"EXPENSE"));
	cout << "- - -\n";
	cout << endl;*/

	cout << "Total balance: " << user->getTotalIncome() - user->getTotalExpense() <<endl;

	cout << "\n(Click once to resume)\n";
}

void showStatistics(User *user)
{
	int stat;
	user->getUserRecords();
	string StatisticCategory;
	cout << "1. Income\n";
	cout << "2. Expense\n";
	cout << endl;
	if(InputValidation(stat))
	{
	//cin.ignore();
    cout << "Total income: $" << user->getTotalIncome() << endl;
    cout << "Total expense: $" << user->getTotalExpense() << endl;
    cout << "Grand total: $" << user->getTotalIncome() - user->getTotalExpense() << endl << endl;

	cout << "Category: ";
	getline(cin,StatisticCategory);
	if (stat==1)
	{
		cout << StatisticCategory <<" / Monthly total income : " << fixed<<setprecision(2)<<user->getCategoryIncome(StatisticCategory) / user->getMonthlyIncome() *100  << "\%" <<endl;
		cout << endl;
	}
	else
	{
		cout << StatisticCategory <<" / Monthly total expense : " <<fixed<<setprecision(2)<<user->getCategoryExpense(StatisticCategory) / user->getMonthlyExpense() *100 << "\%" <<endl;
		cout << endl;
	}
	
	}
	else
	{
		cout << "Please try again.\n";
	}
	
}

void Menu1(void)
{
    cout << "1. Modify record\t";
    //cout << "2. Edit record\t\t";
    cout << "2. Search record\t";
    cout << "3. Sort record\n";
    //cout << "5. Delete record\t";
    cout << "4. Manage user account\t";
    cout << "5. Statistics\t\t";
	cout << "6. Log out\n";
    cout << endl;
   
}

void RecordsEditor(UserAccounts &user_accounts, string &username, string &userpw)
{
	int userinput;
	bool logout = false;
	int mainMenuChoice=0;
	User *user = user_accounts.getUser(username);
	user->loadRecords();
	while (!logout)
	{
		printRecord(user->getUserRecords());
		Menu1();
		if(InputValidation(mainMenuChoice))
		{
		switch (mainMenuChoice)
		{ // see what the users want to do after log in
			
			case 1:
			{
				switch(printrecordmenu())
				{
					case 1:
					//cin.ignore();
				// have to print all the account
				// type!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					ClearScreen();
					cout << "1. income\n";
					cout << "2. expense\n";
				//cout << "3. transfer\n";
				//allow user to input more than one characters
				//but only count the first character

				//avoid invalid input crash the programme
					if(InputValidation(userinput)){  //input validation
						if(userinput==1){
					
						Record *r = new Record(); //delete after use
						getRecordDetails(r);  //no *r
						r->setType("income");
						user->getUserRecords()->addRecord(*r);

						delete r;
						}
						else if(userinput==2)
						{
							Record *r = new Record(); //delete after use
							getRecordDetails(r);  //no *r
							r->setType("expense");
							user->getUserRecords()->addRecord(*r);

						}
					/*else if(int(TempInput[0])-48 ==3)
					{
						cout << "Original account: \n";
						TransferRecord();
					}*/
						else 
						cout << "Invalid input.\n";
						}
					else
					{
						cout <<"Invalid input. Please try again\n";
					}
					break;
					case 2:
					{
					if(user->getUserRecords()->countRecord()==0)
						cout << "No record at the moment, please add some records first.\n";
					else
					{
						user->getUserRecords()->sortRecords(ID, true);
						EditUserRecord(user);
					}
						
					break;				
					}
					case 3:
					{	
						if(user->getUserRecords()->countRecord()==0)
							cout << "No record at the moment, please add some records first.\n";
						else
						{
							user->getUserRecords()->sortRecords(ID, true);
							DeleteUserRecord(user);					
						}				
						break;			
					}
					case 4:
					{
						break;
					}
					default:
					cout << "Invalid input.\n";
					cout << endl;
					break;
				}
				break;		
			}
			case 2:			
			{
				int SearchField;
				string SearchRequirement;
				Records *result = new Records;
				SortorSearchMenu();
			if(InputValidation(SearchField)){
				//cin.ignore();
				cout << "Requirement: ";
				getline(cin,SearchRequirement);
				switch(SearchField)
				{
					case 1:
					result = user->getUserRecords()->searchRecords(DATE,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;					
					break;
					case 2:
					result = user->getUserRecords()->searchRecords(AMOUNT,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;					
					break;			
					case 3:
					result = user->getUserRecords()->searchRecords(CATEGORY,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;
					break;
					case 4:
					result = user->getUserRecords()->searchRecords(ACCOUNT,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;					
					break;
					case 5:
					result = user->getUserRecords()->searchRecords(ID,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;					
					break;
					case 6:
					result = user->getUserRecords()->searchRecords(TYPE,SearchRequirement);
					cout << "Search result: \n";
   					printRecord(result);
					cout << "- - -\n";
    				delete result; // size of result may be large, must delete everytime
    				result = nullptr;					
					break;
					default:
					cout << "Invalid input!\n";
					break;
				}
			}
				break;				
			}

			case 3:			
			{
				int SortField;
				bool SortOrder;
				int InputOrder;
				bool SortInput,OrderInput;

				SortorSearchMenu();
				SortInput=InputValidation(SortField);
				cout << endl;
				cout << "1. Ascending order\n";
				cout << "2. Descending order\n";
				cout << "Order: ";
				OrderInput=InputValidation(InputOrder);
				cout << endl;
				
			if(SortInput && OrderInput)
			{
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
					case 6:
					user->getUserRecords()->sortRecords(TYPE, SortOrder);
					break;
					default:
					cout << "No this choice!\n";
					break;	
				}
			}
			else
			{
				cout << "Can't sort record. Here is invalid input.\n";
			}
			
				break;				
			}

			case 4:			
			{
				int action;
				action = printUserManagementItems();
				switch(action)
				{
					case 1:
					{
						string newpassword;
						string currentpassword;
						//cin.ignore();
						cout << "Current password: ";
						getline(cin,currentpassword);
						cout << endl;
						if(user_accounts.checkPassword(username, currentpassword))
						{
							cout << "Account will be logged out after changing password.\n";
							cout << endl;
							cout << "New password: ";
							getline(cin, newpassword);
							cout << endl;
							cout << user_accounts.changePassword(username, userpw, newpassword) << endl;
							cout << user_accounts.checkPassword(username, newpassword) << endl;
							logout = true;		
						}		
						else
						{
							cout << "Current password is incorrect.\n";
						}
						break;			
					}		
					case 2:			
					//monthly report
					printAccountMonthlyReport(user);
					break;					
					case 3:
					{
						getSavingDetails(user);
						break;			
					}
					case 4:
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

			case 5:			
			{
				showStatistics(user);
				break;
			}

			case 6:
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
		if(mainMenuChoice!=6)
			cin.ignore();
		}

	}
	user->unloadRecords();
}