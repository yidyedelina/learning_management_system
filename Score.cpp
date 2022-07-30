#include <iostream>
#include <string>
#include <vector>
#include "main.h"
unordered_map<string, float> grade_reference = {{"A+", 4}, {"A", 4}, {"A-", 3.75}, {"B+", 3.5}, {"B", 3}, {"B-", 2.75}, {"C+", 2.5}, {"C", 2}, {"C-", 1.75}, {"D", 1}, {"F", 0}};
Scores::Scores(int dep_id,char section,int semester, int academic_year, int batch_year)
{
    vector<string *> score_data = loadData("Score", 8);
    score sc;
    course_ref = new Courses(dep_id, academic_year - batch_year + 1, semester);
    for (int i = 0; i < score_data.size(); i++)
    {
        sc.course_code = score_data[i][0];
        sc.student_id = score_data[i][1];
        sc.mark = stof(score_data[i][2]);
        sc.semester = stoi(score_data[i][3]);
        sc.academic_year = stoi(score_data[i][4]);
        sc.dep_id = stoi(score_data[i][5]);
        sc.section = score_data[i][6][0];
        sc.batch_year = stoi(score_data[i][7]);
        if(sc.dep_id == dep_id && sc.section == section && sc.semester == semester && sc.academic_year == academic_year && sc.batch_year == batch_year)
        {
            score_list.push_back(sc);
        }
    }
}
vector<score> Scores::getScores(){
    return score_list;
}
vector<score> Scores::getScore(string stud_id)
{
    vector<score> std_score;
    for (int i = 0; i < score_list.size(); i++)
    {
        if(score_list[i].student_id.compare(stud_id) == 0)
        {
            std_score.push_back(score_list[i]);
        }
    }
    return std_score;
}
string Scores::markToLetter(float mark)
{
    if (mark >= 90)
        return "A+";
    else if(mark >= 85)
        return "A";
    else if(mark >= 80)
        return "A-";
    else if(mark >= 75)
        return "B+";
    else if(mark >= 70)
        return "B";
    else if(mark >= 65)
        return "B-";
    else if(mark >= 60)
        return "C+";
    else if(mark >= 50)
        return "C";
    else if(mark >= 45)
        return "C-";
    else if(mark >= 40)
        return "D";
    return "F";
}

float Scores::calculate_gpa(vector<score> sc)
{
    float weight = 0;
    float cr_sum = 0;
    for (int i = 0; i < sc.size(); i++)
    {
        course cr = course_ref->getCourse(sc[i].course_code);
        int credit_hour = cr.credit_hour;
        string std_grade = markToLetter(sc[i].mark);
        weight += grade_reference[std_grade] * credit_hour;
        cr_sum += credit_hour;
    }
    return weight/cr_sum;
}