#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "main.h"
using namespace std;
Students::Students(int dep_id, char section, int join_year)
{
        vector<string *> student_data = loadData("Student", 7);
        student s;
        for (int i = 0; i < student_data.size(); i++)
        {
            s.name = student_data[i][0];
            s.id = student_data[i][1];
            s.section = student_data[i][2][0];
            s.dep_id = stoi(student_data[i][3]);
            s.join_year = stoi(student_data[i][4]);
            s.sex = student_data[i][5][0];
            s.age = stoi(student_data[i][6]);
            if (s.dep_id == dep_id && section == s.section && s.join_year == join_year)
            {
                student_list.push_back(s);
            }
        }
        cout << "object created successfully";
}

vector<student> Students::getStudents()
{
    return student_list;
}

student Students::getStudent(string id)
{
    for (int i = 0; i < student_list.size(); i++)
    {
        if(id.compare(student_list[i].id) == 0)
        {
            return student_list[i];
            break;
        }
    }
    return {};
}