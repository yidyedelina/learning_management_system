#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <fstream>
#include <unordered_set>
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
/**
 * @brief function change string to an vector of string using comma as a delimeter
 * 
 * @param filename 
 * @return vector<string> 
 */
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
/**
 * @brief the function load the data from a file and break down them into number of field and store them in vectore
 * 
 * @param filename 
 * @param no_fields 
 * @return vector<string *> a collection of fields
 */
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
/**
 * @brief add a data at the last line of a given file
 * 
 * @param filename 
 * @param data 
 */

void addData(string filename, string data)
{
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    file_out << data << endl;
    file_out.close();
    cout << "File added successfully" << endl;
}
/**
 * @brief a function override the data any file we give it to 
 * 
 * @param filename: the name of the file we need to write
 * @param data: the data 
 */
void writeData(string filename, string data)
{
    ofstream file_out;

    file_out.open(filename);
    file_out << data << endl;
    file_out.close();
    cout << "File added successfully" << endl;
}
int main()
{
    Scores *sc = new Scores(1, 'D', 2, 2014, 2013);
    score s = sc->getScores()[0];
    s.mark = 98;
    sc->setStudentGrade(s);
    vector<studentGpa> st = sc->getTop10();
}