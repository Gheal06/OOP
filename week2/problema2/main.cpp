#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    Student a,b;
    a.SetName("Ionescu Andrei");
    b.SetName("Popescu Ana");
    a.SetEnglishGrade(5);
    a.SetMathGrade(9);
    a.SetHistoryGrade(7);
    b.SetEnglishGrade(10);
    b.SetMathGrade(8);
    b.SetHistoryGrade(7);

    cout<<"Student a:\n\n";
    cout<<"a.GetName(): "<<a.GetName()<<'\n';
    cout<<"a.GetEnglishGrade(): "<<a.GetEnglishGrade()<<'\n';
    cout<<"a.GetMathGrade(): "<<a.GetMathGrade()<<'\n';
    cout<<"a.GetHistoryGrade(): "<<a.GetHistoryGrade()<<'\n';
    cout<<"a.GetAverageGrade(): "<<a.GetAverageGrade()<<'\n';

    cout<<"\nStudent b:\n\n";
    cout<<"b.GetName(): "<<b.GetName()<<'\n';
    cout<<"b.GetEnglishGrade(): "<<b.GetEnglishGrade()<<'\n';
    cout<<"b.GetMathGrade(): "<<b.GetMathGrade()<<'\n';
    cout<<"b.GetHistoryGrade(): "<<b.GetHistoryGrade()<<'\n';
    cout<<"b.GetAverageGrade(): "<<b.GetAverageGrade()<<'\n';

    cout<<"\nComparisons:\n\n";
    cout<<"By average grade: "<<CompareStudentsByAverageGrade(a,b)<<'\n';
    cout<<"By english grade: "<<CompareStudentsByEnglishGrade(a,b)<<'\n';
    cout<<"By math grade: "<<CompareStudentsByMathGrade(a,b)<<'\n';
    cout<<"By history grade: "<<CompareStudentsByHistoryGrade(a,b)<<'\n';
    cout<<"By name: "<<CompareStudentsByName(a,b)<<'\n';
    return 0;
}
