#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    cout<<"Declaration: NumberList nl;\n\n";
    NumberList nl;
    nl.Init();
    cout<<"nl.Init() called\n";
    cout<<"nl.Print(): ";
    nl.Print();
    nl.Add(3);
    nl.Add(2);
    nl.Add(5);
    nl.Add(3);
    cout<<"\nnl.Add(3) called\nnl.Add(2) called\nnl.Add(5) called\nnl.Add(3) called";
    cout<<"\nnl.Print(): ";
    nl.Print();
    nl.Sort();
    cout<<"\nnl.Sort() called";
    cout<<"\nnl.Print(): ";
    nl.Print();
    return 0;
}
