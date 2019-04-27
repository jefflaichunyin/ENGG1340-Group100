// This file define frequenly use print function

// Print out 100 blank line to clear the screen
void ClearScreen() { cout << string(100, '\n'); }

// Print a bar like this
// |========>98% |
void printPercentage(float percentage)
{
    int blocks = int(percentage/10 - 1);
    if(blocks>0)
        cout << "|" << left << string(blocks, '=') << setw(12-blocks) << ">" << right << fixed << left << setprecision(1) << setw(4) << percentage << "|";
    else
        cout << "|" << left << setw(12-blocks) << ">" << right << fixed << left <<setprecision(1) << setw(4) << percentage << "|";
}

// Print the header of the homepage
// e.g.
// Net Income:	$   2120.00	Monthly Income:	$13180.00		Monthly Expense:	$11010.00
// Saving Goal:	Not set yet
// Monthly Goal:	Not set yet	Monthly Quota:	$2120.00
void printHeader(User *user)
{
    // cout << "Total Income:\t$" << setw(10) << fixed << user->getTotalIncome();
    // cout << "\tTotal Expense:\t$" << setw(10) << fixed << user->getTotalExpense();
    cout << "Net Income:\t$" << setw(10) << fixed << setprecision(2) << user->getTotalIncome() - user->getTotalExpense();
    cout << "\tMonthly Income:\t$" <<  user->getMonthlyIncome();
    cout << "\t\tMonthly Expense:\t$" << user->getMonthlyExpense() << endl;
    if(user->getSavingGoal()==0)
        cout << "Saving Goal:\tNot set yet\n";
    else
    {
        cout << "Saving Goal:\t$" << setw(10) << fixed << user->getSavingGoal();
        cout << "\tDeadline:\t" << user->getDeadline();
        float progress = 100*(user->getTotalIncome()-user->getTotalExpense())/user->getSavingGoal();
        cout << "\tProgress:\t";
        printPercentage(progress);
        cout << endl;
    }

    if(user->getMonthlyGoal()==0)
        cout << "Monthly Goal:\tNot set yet";
    else
        cout << "Monthly Goal:\t$" << setw(10) << fixed << right << user->getMonthlyGoal();
    cout << "\tMonthly Quota:\t$" << user->getMonthlyQuota() << endl;
}

// Print the records header
// ID  DATE                      ACCOUNT        CATEGORY       AMOUNT          TYPE      REMARK    
// ----------------------------------------------------------------------------------------------
void printRecordsHeader()
{
    cout << endl;
    cout << left << setw(4) << "ID" << setw(25) << "DATE"
	 << " " << setw(15) << left << "ACCOUNT" << setw(15) << left << "CATEGORY" << setw(16) << left << "AMOUNT" << setw(10) << "TYPE" << setw(10) << "REMARK" << endl;
    cout << string(4+25+15+15+15+10+10, '-') << endl;
}


// Print n-records or lines starting from the number "from"
void printRecords(Records *records, int from, int n)
{
    // Print a record and decrease the remaining lines by one
    if(records->countRecord()==0)
    {
        cout <<  string(5, '\t') << "   NO RECORD";
        n--;
    }
    else if(from < 0)
    {
        cout << "Please go back to the next page\n";
    }
    else if((unsigned int)from > records->countRecord()-1)
    {
        cout << "Please go back to the previous page\n";
    }
    else
    {
        for (unsigned int i = from; i < records->countRecord() && n>0; i++)
        {
            Record *r = records->getRecord(i);
            cout << left << setw(4) << r->getID() << setw(25) << r->getDate()
                 << " " << setw(15) << left << r->getAccount() << setw(15) << left << r->getCategory()
                 << setw(2) << "$" << setw(10) << right << fixed << setprecision(2) << r->getAmount() << "   " << left << setw(10) << r->getType()
                 << r->getRemark() << endl;
            n--;
        }
    }
    while(n-- > 0)
        cout << endl;
}

// Pause the program until the user press enter
void Pause()
{
    cout << "Press ENTER to continue\n";
    getchar();
}

// Capitalize all the letters in a string
void Capitalize(string &input)
{
    for(auto &c : input)
        c=toupper(c);
}

// Ask until user inputed a number between lower and upper
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
        // type check
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
            // range check
            WITHIN_RANGE = (lower <= user_input && user_input <= upper);
            if(WITHIN_RANGE)
                VALID = true;
            else
                cout << "\n\nPLEASE INPUT A VALUE BETWEEN " << lower << " AND " << upper << "!\n\n";
        }   
    }
    return user_input;
}

// Ask until user inputed a number between lower and upper
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
            if(!isdigit(TempInput[j]) && TempInput[j]!='.') // . is allowed in float input
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

// Ask until user inputed a string with length between min_length and max_length
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

