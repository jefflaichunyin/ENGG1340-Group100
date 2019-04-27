// This function find if a category is unique in a set of record
bool uniqueCategory(vector<string> categories, string candidate)
{
    bool UNIQUE=true;
    for(auto &c:categories)
    {
        if(c==candidate)
        {
            UNIQUE = false;
            break;
        }
    }
    return UNIQUE;
}

void IncomeStat(User *user)
{
    float total_income = user->getTotalIncome();
    Records *income_records = user->getUserRecords()->searchRecords(Field(TYPE), "INCOME");
    vector<string> categrories;
    for(unsigned int i=0; i<income_records->countRecord(); i++)
    {
        if(uniqueCategory(categrories, income_records->getRecord(i)->getCategory()))
            categrories.push_back(income_records->getRecord(i)->getCategory());
    }
    cout << setw(15) << "Category" << setw(10) << " Sum" << setw(10) << "Percentage" << endl << string(35,'-') << endl;
    for(auto& category:categrories)
    {
        float sum=0;
        Records *categorical_records = income_records->searchRecords(Field(CATEGORY), category);
        for(unsigned int i=0; i<categorical_records->countRecord(); i++)
        {
            sum += categorical_records->getRecord(i)->getAmount();
        }
        cout << setw(15) << category << setw(10) << right << sum << setw(10) << right << sum/total_income << endl;
    }
    Pause();
}

void ExpenseStat()
{

}
void Stat(User *user)
{
    Records *filtered_records = nullptr;
    float total = 0;
    vector<string> categrories;
    string message =
    "View Statistics of ...\n"
    "1. Income\n"
    "2. Expense\n"
    "3. Return\n"
    "Please enter your choice: ";
    int type;
    while(true)
    {
        type = validatedInt(message, 1,3);
        cout << endl << endl;
        if(type == 1)
        {
            total = user->getTotalIncome();
            filtered_records = user->getUserRecords()->searchRecords(Field(TYPE), "INCOME"); // search for all income records
            cout << "Total Income: " << total << endl;
        }
        else if(type ==2)
        {
            total = user->getTotalExpense();
            filtered_records = user->getUserRecords()->searchRecords(Field(TYPE), "EXPENSE"); // search for all expense records
            cout << "Total Expense: " << total << endl;
        }
        if(type == 3) // return
        {
            break;
        }
        else // type ==1 or type==2
        {
            if(filtered_records->countRecord()==0) // no income / expense records
            {
                if(type==1)
                    cout << "Cannot find any income record\n";
                else 
                    cout << "Cannot find any expense record\n";
            }
            else
            {
                for(unsigned int i=0; i<filtered_records->countRecord(); i++)
                {
                    if(uniqueCategory(categrories, filtered_records->getRecord(i)->getCategory()))
                        categrories.push_back(filtered_records->getRecord(i)->getCategory());
                }
                cout << left << setw(15) << "Category" << setw(10) << " Sum" << setw(12) << right << "Percentage" << endl << string(40,'-') << endl;
                for(auto& category:categrories)
                {
                    float sum=0;
                    Records *categorical_records = filtered_records->searchRecords(Field(CATEGORY), category);
                    for(unsigned int i=0; i<categorical_records->countRecord(); i++)
                    {
                        sum += categorical_records->getRecord(i)->getAmount();
                    }
                    cout << setw(15) << left << category << "$" << setw(10)  << right << sum << setw(10) << right << sum/total*100 << "%" << endl;
                }        
            }
            Pause();
            ClearScreen();        
        }        
    }
}