#include "RecordEditor.cpp"
#include "SearchSortRecords.cpp"
#include "Settings.cpp"
#include "Stat.cpp"
void Homepage(User *user)
{

    Records *user_records = user->getUserRecords();
    cout << "Welcome " << user->getUsername() << endl << endl;
    if(user->loadRecords()==false)
    {
        cout << "Record file not found\n";
    }
    int user_input;
    while(true)
    {
        if(user_records->countRecord()>0)
        {
            cout << "Sorting records\n";
            user_records->sortRecords(ID, true);
        }
            
        printHeader(user);
        printRecordsHeader();
        printRecords(user_records);
        printMenu();
        user_input = validatedInt("Please choose from 1-6: ", 1, 6);
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
            break;

        ClearScreen();
    }
    user->saveRecords();
    user->unloadRecords();
}