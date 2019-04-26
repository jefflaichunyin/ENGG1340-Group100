#include "validation.h"
#include <cctype>
#include <iostream>
using namespace std;
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

