void SearchRecords(Records *user_records)
{
    if(user_records->countRecord()==0)
    {
        cout << "\nThere is no record for you to search\n";
    }
    else
    {
        string message = 
        "Please select which field you would like to search\n"
        "1. ID\n"
        "2. Date\n"
        "3. Account\n"
        "4. Category\n"
        "5. Amount\n"
        "6. Type\n"
        "7. Remark\n"
        "Search by: ";
        int field = validatedInt(message, 1, 7);
        string keyword = validatedString("Please enter a keyword: ", 1, MAX_STRING_LEN);
        Capitalize(keyword);
        Records *result = user_records->searchRecords((Field)(field-1), keyword);
        if(result->countRecord()==0)
            cout << "No result\n";
        else
        {
            cout << "These are the records containing " << keyword << endl;
            printRecordsHeader();
            printRecords(result, 0, result->countRecord());
        }
        delete result;      // size maybe large & no longer useful -> delete
        result = nullptr;
    }
    Pause();
}

void SortRecords(Records *user_records)
{
    if(user_records->countRecord()<2)
    {
        cout << "\nThere is not enough records to do the sorting\n";
    }
    else
    {
        string message = 
        "Please select which field you would like to sort\n"
        "1. ID\n"
        "2. Date\n"
        "3. Account\n"
        "4. Category\n"
        "5. Amount\n"
        "6. Remark\n"
        "Search by: ";
        int field = validatedInt(message, 1, 6);
        message =
        "1. Ascending\n"
        "2. Descending\n"
        "In order: ";
        int order = validatedInt(message, 1, 2);
        user_records->sortRecords((Field)(field - 1) , (order==1)?true:false);
    }
    ClearScreen();
}