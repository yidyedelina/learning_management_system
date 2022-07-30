#include <iostream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;
/**
 * @file utils.cpp
 * this file contain a re usable function that we need to build our cli app
 *
 */

/**
 * @brief str_to_array - convert comma separated string to an array of individual string 
 * 
 * @param s - a comma separated string
 * @param n - a number of words separated by comma
 * @return string* return an array of words
 */
string* str_to_array(string s, int n)
{
    string* token = new string[n];
    stringstream string_stream(s);
    int i = 0;
    while(string_stream.good())
    {
        string a;
        getline(string_stream, a, ',');
        token[i] = a;
        i++;
    }
    return token;
}
/**
 * @brief validateId - check whether the given ID is a valid id sytaxically 
 * 
 * @param s an ID we need to validate
 * @return int retunr 1 if the id match to aastu standard return 0 if not
 */
int  validateId(string s)
{
    regex b("^(ets)[0-9]{4}(/[0-1][0-4])$");
    return regex_match(s, b);
}
