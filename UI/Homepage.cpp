#include "RecordEditor.cpp"
#include "SearchSortRecords.cpp"
#include "Settings.cpp"
#include "Stat.cpp"

#define RECORD_HEIGHT 10
void printMenu()
{
    cout << endl;
    cout << "1. Add/Edit/Delete Record\t";
    cout << "2. Search Records\t\t";
    cout << "3. Sort Records\n";
    cout << "4. Settings\t\t\t";
    cout << "5. Statistics\t\t\t\n";
    cout << "6. Previous Page\t\t";
    cout << "7. Next Page\t\t\t";
    cout << "8. Logout\n";
    cout << endl;
}

void Homepage(User *user)
{
    int first_record = 0, user_input;
    Records *user_records = user->getUserRecords();
    cout << "Welcome " << user->getUsername() << endl << endl;
    if(user->loadRecords()==false)
    {
        cout << "Record file not found\n";
    }
    if(user_records->countRecord()>0)
    {
        user_records->sortRecords(ID, true);
    }

    while(true)
    {
        // Deadline of saving goal have passed already
        if(time(nullptr)>user->getDeadline_t())
        {
            cout << "\nThe deadline of the saving goal has already passed, please set a new goal.\n";
            user->setSavingGoal_t(0, 0); // reset old saving goal
        }
        if((user->getTotalIncome()-user->getTotalExpense())>user->getSavingGoal())
        {
            cout << "Congrats! Your meet your saving goal, please set a new goal.\n";
            user->setSavingGoal_t(0, 0); // reset old saving goal
        }

            
        printHeader(user);
        printRecordsHeader();
        printRecords(user_records, first_record, RECORD_HEIGHT);
        printMenu();
        user_input = validatedInt("Please choose from 1-8: ", 1, 8);
        if(user_input==1)
            RecordEditor(user);
        else if(user_input==2)
            SearchRecords(user_records);
        else if(user_input==3)
            SortRecords(user_records);
        else if(user_input==4)
        {
            if(Settings(&user_accounts,user))
                break; // logout immediately
        }
        else if(user_input==5)
            Stat(user);
        else if(user_input==6)
            first_record -= RECORD_HEIGHT;
        else if(user_input==7)
            first_record += RECORD_HEIGHT;
        else if(user_input==8)
            break;

        ClearScreen();
    }
    user->saveRecords();
    user->unloadRecords();
}