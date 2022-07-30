#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <fstream>
#include "main.h"
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

vector<string> lineData(string filename)
{
    vector<string> data;
    ifstream studentfile(filename);
    if(studentfile.is_open())
    {
        string line;
        while(getline(studentfile, line))
        {
            data.push_back(line);
        }
    }
    return data;
}
vector<string *> loadData(string filename, int no_fields)
{
    vector<string*> data;
    vector<string> lines = lineData(filename);
    for (int i = 0; i < lines.size(); i++)
    {
        string *s = str_to_array(lines[i], no_fields);
        data.push_back(s);
    }
    return data;
}

int main()
{
    Scores *sc = new Scores(1, 'D', 2, 2014, 2013);
    cout << sc->calculate_gpa(sc->getScores());
}