#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
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

float Scores::calculateGpa(vector<score> sc)
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
vector<studentGpa> Scores::calculateClassGpa(vector<score> sc)
{
    vector<string> duplicateStudentId = getStudentId();
    unordered_set<string> uniqueStudentId = vectorToSet(duplicateStudentId);
    vector<studentGpa> gpaList;
    studentGpa student;
    for (unordered_set<string>::iterator itr = uniqueStudentId.begin(); itr != uniqueStudentId.end(); itr++)
    {
        string studentId = (*itr);
        vector<score> studentScore = getScore(studentId);
        float gpa = calculateGpa(studentScore);
        student.gpa = gpa;
        student.studId = studentId;
        gpaList.push_back(student);
    }
    return gpaList;
}
vector<string> Scores::getStudentId()
{
    vector<string> s;
    for (int i = 0; i < score_list.size(); i++)
    {
        s.push_back(score_list[i].student_id);
    }
    return s;
}
bool compare(studentGpa s, studentGpa t)
{
    return (s.gpa > t.gpa);
}
vector<studentGpa> Scores::getTop10()
{
    vector<studentGpa> calculatedGrade = calculateClassGpa(score_list);
    sort(calculatedGrade.begin(), calculatedGrade.end(), compare);
    int i = 0;
    for (vector<studentGpa>::iterator itr = calculatedGrade.begin(); itr != calculatedGrade.end();itr++)
    {
        cout << (*itr).gpa << endl;
        i++;
        if(i == 10)
        {
            break;
        }
    }
    return calculatedGrade;
}
unordered_set<string> Scores::vectorToSet(vector<string> vec)
{
    unordered_set<string> set;
    for (int i = 0; i < vec.size(); i++)
    {
        set.insert(vec[i]);
    }
    return set;
}

//TODO: validating before inserting the data if it exist
void Scores::setStudentGrade(score s)
{
    string data = s.course_code + "," + s.student_id + "," + to_string(s.mark) + "," + to_string(s.semester) + "," + to_string(s.academic_year) + "," + to_string(s.dep_id) + "," + s.section + "," + to_string(s.batch_year);
    addData("Score", data);
}
//TODO:
/**
 * copy all the data to temp container
 * filter the container to the set we want edit
 * rewrite the file into Score file
 * append the edited file at the end
 */
void Scores::editStudentGrade(float mark, string stud_id, string course_code)
{

}
//TODO:
/**
 * load data from score table
 * and change them to vector<score> list
 * and return the vector
 */