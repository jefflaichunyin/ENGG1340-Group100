// This file define frequenly use print function

void ClearScreen() { cout << string(100, '\n'); }
void printHeader(User *user)
{
    // cout << "Total Income:\t$" << setw(10) << fixed << user->getTotalIncome();
    // cout << "\tTotal Expense:\t$" << setw(10) << fixed << user->getTotalExpense();
    cout << "Net Income:\t$" << setw(10) <<  setprecision(2) << fixed << user->getTotalIncome() - user->getTotalExpense();
    cout << "\tMonthly Income:\t$" <<  user->getMonthlyIncome();
    cout << "\t\tMonthly Expense:\t$" << user->getMonthlyExpense() << endl;
    if(user->getSavingGoal()==0)
        cout << "Saving Goal:\tNot set yet";
    else
        cout << "Saving Goal:\t$" << setw(10) << fixed << user->getSavingGoal();
    
    cout << "\tDeadline:\t" << user->getDeadline() << endl;

    if(user->getMonthlyGoal()==0)
        cout << "Monthly Goal:\tNot set yet";
    else
        cout << "Monthly Goal:\t$" << setw(10) << fixed << user->getMonthlyGoal();
    cout << "\tMonthly Quota:\t$" << user->getMonthlyQuota() << endl;
}
void printRecordsHeader()
{
    cout << endl;
    cout << left << setw(4) << "ID" << setw(25) << "DATE"
	 << " " << setw(15) << left << "ACCOUNT" << setw(15) << left << "CATEGORY" << setw(16) << left << "AMOUNT" << setw(10) << "TYPE" << setw(10) << "REMARK" << endl;
    cout << string(4+25+15+15+15+10+10, '-') << endl;
}

void printRecords(Records *records)
{
    if(records->countRecord()==0)
    {
        cout <<  string(5, '\t') << "   NO RECORD";
    }
    else
    {
        for (unsigned int i = 0; i < records->countRecord(); i++)
        {
            Record *r = records->getRecord(i);
            cout << left << setw(4) << r->getID() << setw(25) << r->getDate()
                 << " " << setw(15) << left << r->getAccount() << setw(15) << left << r->getCategory()
                 << setw(2) << "$" << setw(10) << right << fixed << setprecision(2) << r->getAmount() << "   " << left << setw(10) << r->getType()
                 << r->getRemark() << endl;
        }
    }
    cout << endl;
}
void printMenu()
{
    cout << endl;
    cout << "1. Add/Edit/Delete Record\t";
    cout << "2. Search Records\t\t";
    cout << "3. Sort Records\n";
    cout << "4. Settings\t\t\t";
    cout << "5. Statistics\t\t\t";
    cout << "6. Logout\n";
    cout << endl;
}

void Pause()
{
    cout << "Press ENTER to continue\n";
    getchar();
}

void Capitalize(string &input)
{
    for(auto &c : input)
        c=toupper(c);
}

int validatedInt(string message, int lower, int upper)
{
    bool VALID = false;
    int i, user_input;
    char TempInput[255];
    bool HAVE_ALPHA, WITHIN_RANGE;
    
    while(!VALID)
    {
        cout << message;
        i = 0;
        HAVE_ALPHA = false;
        do
        {
            TempInput[i] = getchar();
            i++;
        }
        while (TempInput[i - 1] != '\n');
        for(int j=0; j<(i-1); j++)
        {
            if(!isdigit(TempInput[j]))
            {
                HAVE_ALPHA = true;
                break;
            }
        }
        if(HAVE_ALPHA)
        {
            cout << "\n\nYOUR INPUT MUST CONTAIN NUMBER ONLY!\n\n";
        }
        else
        {
            user_input = atoi(TempInput);
            WITHIN_RANGE = (lower <= user_input && user_input <= upper);
            if(WITHIN_RANGE)
                VALID = true;
            else
                cout << "\n\nPLEASE INPUT A VALUE BETWEEN " << lower << " AND " << upper << "!\n\n";
        }   
    }
    return user_input;
}

float validatedFloat(string message, float lower, float upper)
{
    bool VALID = false;
    int i;
    float user_input;
    char TempInput[255];
    bool HAVE_ALPHA, WITHIN_RANGE;
    
    while(!VALID)
    {
        cout << message;
        i = 0;
        HAVE_ALPHA = false;
        do
        {
            TempInput[i] = getchar();
            i++;
        }
        while (TempInput[i - 1] != '\n');
        for(int j=0; j<(i-1); j++)
        {
            if(!isdigit(TempInput[j]))
            {
                HAVE_ALPHA = true;
                break;
            }
        }
        if(HAVE_ALPHA)
        {
            cout << "\n\nYOUR INPUT MUST CONTAIN NUMBER ONLY!\n\n";
        }
        else
        {
            user_input = atof(TempInput);
            WITHIN_RANGE = (lower <= user_input && user_input <= upper);
            if(WITHIN_RANGE)
                VALID = true;
            else
                cout << "\n\nPLEASE INPUT A VALUE BETWEEN " << lower << " AND " << upper << "!\n\n";
        }   
    }
    return user_input;
}

string validatedString(string message, unsigned int min_length, unsigned int max_length)
{
    bool VALID = false;
    string user_input;
    
    while(!VALID)
    {
        cout << message;
        getline(cin, user_input);
        if(min_length <= user_input.size() && user_input.size() <= max_length)
            VALID = true;
        else
        {
            cout << "\n\nYOUR INPUT SHOULD BE WITHIN " << min_length << " AND " << max_length << " CHARACTER(S)\n\n";
        }
            

    }
    return user_input;
}

