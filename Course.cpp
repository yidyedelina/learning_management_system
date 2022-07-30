#include <iostream>
#include <vector>
#include <string>
#include "main.h"



Courses::Courses(int dep_id, int batch_year, int semester)
{
    vector<string *> course_data = loadData("Courses", 6);
    course crs;
    for (int i = 0; i < course_data.size(); i++)
    {
        crs.course_code = course_data[i][0];
        crs.course_title = course_data[i][1];
        crs.credit_hour = stoi(course_data[i][2]);
        crs.dep_id = stoi(course_data[i][3]);
        crs.batch_year = stoi(course_data[i][4]);
        crs.semester = stoi(course_data[i][5]);
        if(crs.dep_id == dep_id && crs.semester == semester && crs.batch_year == batch_year)
        {
            course_list.push_back(crs);
        }
    }
}

vector<course> Courses::getCourses(){
    return course_list;
}

course Courses::getCourse(string course_code)
{
    for (int i = 0; i < course_list.size();i++)
    {
        if(course_list[i].course_code.compare(course_code)==0)
        {
            return course_list[i];
        }
    }
    return {};
}
