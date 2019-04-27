void changePassword(UserAccounts *user_accounts, User *user)
{
    string oldpassword = validatedString("Please enter the current password: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    string newpassword = validatedString("Please enter the new password: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    string confirm     = validatedString("Please enter the new password again: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    if(user_accounts->checkPassword(user->getUsername(), oldpassword)) // correct
    {
        if(newpassword==confirm)
            user_accounts->changePassword(user->getUsername(), oldpassword, newpassword);
        else
        {
            cout << "The second input of the new password does not match with the first input\n";
        }
    }
    Pause();
    ClearScreen();
    
}
void setGoal(User *user)
{
    bool VALID=false;
    ClearScreen();
    cout << "Saving Goal Setting\n";
    cout << "-------------------\n";
    while(!VALID)
    {
        // not allowed to set a target lower than current net income
        time_t current_t;
        time(&current_t);
        struct tm current_time = *localtime(&current_t);
        float net_income = user->getTotalIncome()-user->getTotalExpense();
        float saving_goal = validatedFloat("How much do you want to save? $", net_income, 10000000000);
        cout << "Please set a deadline for your saving goal\n";
        int month = validatedInt("Month(1-12): ", 1, 12);
        int year = validatedInt("Year: ", 1900, 2030); // 32 bits time_t limit
        if((month+12*year)<=(current_time.tm_mon+1+(current_time.tm_year+1900)*12))
        {
            
            cout << "\nCannot set deadline in the past.\n" << "Please enter a valid deadline\n\n";
            user->setSavingGoal_t(0, 0);
        }
        else
        {
            user->setSavingGoal(saving_goal, month, year);
            VALID = true;
        }
    }
    cout << "Your saving goal is set\n";
    Pause();
}
void deleteAccount(UserAccounts *user_accounts, User *user)
{
    user_accounts->removeUser(user->getUsername(), user->getPassword());
    user_accounts->saveUserInfo();
    Pause();
    ClearScreen();
}

// return true if need to logout after chaging user setting
bool Settings(UserAccounts *user_accounts, User *user)
{
    int action;
    string message=
    "User Setting\n"
    "------------\n"
    "1. Change Password\n"
    "2. Set Saving Goal\n"
    "3. Delete Account\n"
    "4. Return\n"
    "Please choose from 1-4: ";
    action = validatedInt(message, 1, 4);
    if(action==1)
        changePassword(user_accounts, user);
    else if(action==2)
        setGoal(user);
    else if(action==3)
        deleteAccount(user_accounts, user);

    return (action!=2 && action!=4); // no need to logout after setting saving goal
}