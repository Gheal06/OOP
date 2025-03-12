#pragma once

class Student{
    private:
        float math, english, history;
        char name[129];
    public:
        const char* GetName();
        float GetMathGrade();
        float GetEnglishGrade();
        float GetHistoryGrade();

        void SetName(const char*);
        void SetMathGrade(float);
        void SetEnglishGrade(float);
        void SetHistoryGrade(float);
        float GetAverageGrade();
};

int CompareStudentsByName(Student,Student);
int CompareStudentsByMathGrade(Student,Student);
int CompareStudentsByEnglishGrade(Student,Student);
int CompareStudentsByHistoryGrade(Student,Student);
int CompareStudentsByAverageGrade(Student,Student);
