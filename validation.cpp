#include "validation.h"
#include <cctype>
using namespace std;
int validateIntRange(string message, int lower, int upper)
{
    bool VALID = false;
    int user_input;
    while(!VALID)
    {
        cout << message << endl;
        cin >> user_input;
        if(lower <= user_input && user_input <= upper)
            VALID = true;
        else
            cout << "Please input a value between " << lower << " and " << upper << endl;
    }
    return user_input;
}

string validateStringLength(string message, int min_length, int max_length)
{
    bool VALID = false;
    string user_input;
    while(!VALID)
    {
        cout << message << endl;
        getline(cin, user_input);
        if(min_length <= user_input.size() && user_input.size() <= max_length)
            VALID = true;
        else
            cout << "You input should be within " << min_length << " and " << max_length << "character(s)\n";
    }
    return user_input;
}