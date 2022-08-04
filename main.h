#ifndef _MAIN_H
#define _MAIN_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
string *str_to_array(string s, int n);
int validateId(string s);
struct student
{
    string name;
    string id;
    char section;
    int dep_id;
    int join_year;
    char sex;
    int age;
};
struct studentGpa
{
    string studId;
    float gpa;
};
class Students
{
    vector<student> student_list;

public:
    Students(int dep_id, char section, int join_year);
    vector<student> getStudents();
    student getStudent(string id);
    void addStudent(string id);
};
struct course
{
    string course_code;
    string course_title;
    int credit_hour;
    int batch_year;
    int dep_id;
    int semester;
};

class Courses
{
    vector<course> course_list;

public:
    Courses(int dep_id, int batch_year, int semester);
    vector<course> getCourses();
    course getCourse(string course_code);
};
struct score
{
    string course_code;
    string student_id;
    float mark;
    int semester;
    int academic_year;
    int dep_id;
    char section;
    int batch_year;
};

class Scores
{
    Courses *course_ref;
    vector<score> score_list;

public:
    Scores(int dep_id, char section, int semester, int academic_year, int batch_year);
    vector<score> getScores();
    vector<score> getScore(string stud_id);
    void setStudentGrade(score s);
    void editStudentGrade(float mark, string stud_id, string course_code);
    float markToGrade(float mark);
    string markToLetter(float mark);
    float calculateGpa(vector<score> sc);
    vector<studentGpa> getTop10();
    vector<string> getStudentId();
    vector<studentGpa> calculateClassGpa(vector<score> sc);
    unordered_set<string> vectorToSet(vector<string> vec);
};

vector<string *> loadData(string filename, int no_fields);
vector<string> lineData(string filename);
void addData(string filename, string data);
void writeData(string filename, string data);
#endif