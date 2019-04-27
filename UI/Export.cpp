void Export(User *user)
{
    string filepath = validatedString("Please enter a filepath for saving the CSV file: ", 1, 255);
    user->exportRecordsToCSV(filepath);
    Pause();
}