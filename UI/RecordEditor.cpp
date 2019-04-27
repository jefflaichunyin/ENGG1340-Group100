#include <limits>

void addRecord(Records *user_records)
{
    string type, account, category, remark;
    float amount;
    cout << "Please give the type of the transaction\n\n";
    string message = 
    "1. Expense\n"
    "2. Income\n"
    "3. Transfer\n"
    "Please enter your choice: ";
    int type_i = validatedInt(message, 1, 3);
    if(type_i==1)
        type = "EXPENSE";
    else if(type_i==2)
        type = "INCOME";

    Record *new_record = new Record();
    amount = validatedFloat("Amount: ", 0, numeric_limits<float>::max());
    if(type_i!=3) // income or expense
    {
        account     = validatedString("Account(Bank/Credit Card/Cash...): ", MIN_STRING_LEN, MAX_STRING_LEN);
        category    = validatedString("Category(Meal/Transport/Salary...): ", MIN_STRING_LEN, MAX_STRING_LEN);
        remark      = validatedString("Remark: ", 0, MAX_STRING_LEN);
        
        new_record->setType(type);
        new_record->setAccount(account);
        new_record->setAmount(amount);
        new_record->setCategory(category);
        new_record->setRemark(remark);
        user_records->addRecord(*new_record);
    }
    else // transfer from one account to another accout
    {
        string from = validatedString("From account: ", MIN_STRING_LEN, MAX_STRING_LEN);
        Capitalize(from);
        string to   = validatedString("To   account: ", MIN_STRING_LEN, MAX_STRING_LEN);
        Capitalize(to);
        category    = "TRANSFER";
        // a transfer = expense of a account + income of another account
        // add first record
        new_record->setType("EXPENSE");
        new_record->setAccount(from);
        new_record->setAmount(amount);
        new_record->setCategory(category);
        new_record->setRemark("TO: " + to);
        user_records->addRecord(*new_record);
        // add second record
        new_record->setType("INCOME");
        new_record->setAccount(to);
        new_record->setRemark("FROM: " + from);
        user_records->addRecord(*new_record);
    }
    delete new_record; 
    new_record = nullptr;
    user_records->normalizeID();
}

void changeRecord(Records *user_records)
{
    if(user_records->countRecord()==0)
    {
        cout << "\nThere is no record for you to change\n";
        Pause();
    }
    else
    {
        user_records->normalizeID();
        int id;
        string type, account, category, remark;
        float amount;
        printRecordsHeader();
        printRecords(user_records, 0, user_records->countRecord());
        id = validatedInt("Please enter the ID of the record: ", 1, user_records->countRecord());
        cout << "Please enter new value for each field.\n";
        
        amount = validatedFloat("Amount: ", 0, numeric_limits<float>::max());
        account = validatedString("Account(Bank/Credit Card/Cash...): ", MIN_STRING_LEN, MAX_STRING_LEN);
        category = validatedString("Category(Meal/Transport/Salary...): ", MIN_STRING_LEN, MAX_STRING_LEN);
        remark = validatedString("Remark: ", 0, MAX_STRING_LEN);
        
        Record *new_record = new Record();
        new_record->setType(user_records->getRecord(id - 1)->getType());
        new_record->setAccount(account);
        new_record->setAmount(amount);
        new_record->setCategory(category);
        new_record->setRemark(remark);
        user_records->replaceRecord(id - 1, *new_record);
        delete new_record;        
    }
}

void deleteRecord(Records *user_records)
{
    if(user_records->countRecord()==0)
    {
        cout << "\nThere is no record for you to delete\n";
        Pause();
    }
    else
    {
        user_records->normalizeID();
        int id;
        printRecordsHeader();
        printRecords(user_records, 0, user_records->countRecord());
        id = validatedInt("Please enter the ID of the record your want to delete: ", 1, user_records->countRecord());
        user_records->deleteRecord(id - 1);      
    }
}

void RecordEditor(User *user)
{
    string message = "1. Add a record\n"
                     "2. Edit a record\n"
                     "3. Delete a record\n"
                     "Please enter your choice: ";
    int action = validatedInt(message, 1, 3);
    Records *user_records = user->getUserRecords();
    if(action==1)
        addRecord(user_records);
    else if(action==2)
        changeRecord(user_records);
    else if(action==3)
        deleteRecord(user_records);
    user->saveRecords();
}