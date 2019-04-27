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
        float saving_goal = validatedFloat("How much do you want to save? $", 1, numeric_limits<float>::max());
        cout << "Please set a deadline for your saving goal\n";
        int month = validatedInt("Month(1-12): ", 1, 12);
        int year = validatedInt("Year: ", 1990, 2030); // 32 bits time_t limit
        user->setSavingGoal(saving_goal+user->getTotalIncome()-user->getTotalExpense(), month, year);
        if(time(nullptr)>user->getDeadline_t())
        {
            cout << "\nCannot set deadline in the past.\n" << "Please enter a valid deadline\n\n";
        }
        else
        {
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