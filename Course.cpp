#include <iostream>
#include <vector>
#include <string>
#include "main.h"

struct course {
    string course_code;
    string course_title;
    string credit_hour;
    int batch_year;
    int dep_id;
    int semester;
};

class Courses {
    vector<course> course_list;
    public:
        Courses(int dep_id, int semester, int batch_year);
        vector<course> getCourses();
        course getCourse(string course_code);
};