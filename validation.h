#include <string>
// Function: validate user integer input
// Input:
//  message:    message to prompt the user to input a value
//  lower:      lower bound of the input value
//  upper:      upper bound of the input value
// Output:
//  int:        validated user input
int validatedInt(std::string message, int lower, int upper);
float validatedFloat(std::string message, float lower, float upper);
// Function: validate user string input
// Input:
//  message:    message to prompt the user to input a value
//  min_length: minimum length of the user input
//  max_length: maximum length of the user input
// Output:
//  string:     validated user input
std::string validatedString(std::string message, unsigned int min_length, unsigned int max_length);