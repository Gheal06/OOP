#include "Student.h"
#include <cstring>

const char* Student::GetName(){
    return this->name;
}
float Student::GetMathGrade(){
    return this->math;
}
float Student::GetEnglishGrade(){
    return this->english;
}
float Student::GetHistoryGrade(){
    return this->history;
}
void Student::SetName(const char* name){
    strncpy(this->name,name,128);
}
void Student::SetMathGrade(float grade){
    this->math=grade;
}
void Student::SetEnglishGrade(float grade){
    this->english=grade;
}
void Student::SetHistoryGrade(float grade){
    this->history=grade;
}
float Student::GetAverageGrade(){
    return (this->math+this->english+this->history)/3.0;
}

int CompareStudentsByName(Student a,Student b){
    int order=strcmp(a.GetName(),b.GetName());
    if(order<0) return -1;
    if(order==0) return 0;
    return 1;
}
int CompareStudentsByMathGrade(Student a,Student b){
    float grade_a=a.GetMathGrade(),grade_b=b.GetMathGrade();
    if(grade_a<grade_b) return -1;
    if(grade_a==grade_b) return 0;
    return 1;
}
int CompareStudentsByEnglishGrade(Student a,Student b){
    float grade_a=a.GetEnglishGrade(),grade_b=b.GetEnglishGrade();
    if(grade_a<grade_b) return -1;
    if(grade_a==grade_b) return 0;
    return 1;
}
int CompareStudentsByHistoryGrade(Student a,Student b){
    float grade_a=a.GetHistoryGrade(),grade_b=b.GetHistoryGrade();
    if(grade_a<grade_b) return -1;
    if(grade_a==grade_b) return 0;
    return 1;
}
int CompareStudentsByAverageGrade(Student a,Student b){
    float grade_a=a.GetAverageGrade(),grade_b=b.GetAverageGrade();
    if(grade_a<grade_b) return -1;
    if(grade_a==grade_b) return 0;
    return 1;
}

