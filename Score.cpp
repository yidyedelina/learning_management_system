#include <iostream>
#include <string>
#include <vector>
#include "main.h"
struct score{
    string course_code;
    string student_id;
    float mark;
    int semester;
    int academic_year;
};
class Scores
{
    vector<score> score_list;
    // this constructor load data from scores file to score_list depending on the parameter
    Scores(string stud_id, int semester, int academic_year);
    // getScores method just return score_list vector;
    vector<score> getScores()
    {
        return score_list;
    }
    // getScore method filter the data only select the specific student grade in specific subject
    vector<score> getScore(string stud_id, string course_code)
    {
    }
    // setStudentGrade add grade of student into score file
    void setStudentGrade(score *s){

    }
    // this method edit the student mark from score file
    void editStudentGrade(float mark, string stud_id, string course_code){

    }
    //this method change student mark which outof 100 to normal grade [0-4]
    float markToGrade(float mark){

    }
    // this method change student mark which is out of 100 to letter like A, A+,...
    char markToLetter(float mark){

    }
    //this method accept list of score and calculate the gpa from the given list
    float calculate_gpa(score *s){

    }
    // this method return a top 10 student from a department 
    vector<score> getTop10(int dep_id, int sem, int academic_year)
    {

    }
    //
};
