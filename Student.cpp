#include <iostream>
#include <vector>
#include <string>
#include "main.h"
using namespace std;
struct student
{
    string name;
    string id;
    char section;
    string dep_id;
    int join_year;
    char sex;
    int age;
};

class Students {
    vector<student> student_list;
    // load specific section student from student file to student_list vector;
    Students(string dep_id, char section, string join_year);
    // get student return student_list 
    vector<student> getStudents(){
        
    }
    student getStudent(string id);
    void addStudent(string id);
};