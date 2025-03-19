#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    Sort s(10,1,100);
    cout<<"Randomly initialized from Sort::Sort(10,1,100):\n";
    s.Print();
    cout<<"\nSorted in ascending order using bubble sort:\n";
    s.BubbleSort(true);
    s.Print();
    cout<<"\nSorted in descending order using bubble sort:\n";
    s.BubbleSort(false);
    s.Print();
    int n=8;
    int v[8]={7,8,1,6,4,4,3,2};
    cout<<"\nInitialized from Sort::Sort(n,v), n=8, v={7,8,1,6,4,4,3,2}:\n";
    s=Sort(n,v);
    s.Print();
    cout<<"\nSorted in ascending order using insertion sort:\n";
    s.InsertSort(true);
    s.Print();
    cout<<"\nSorted in descending order using insertion sort:\n";
    s.InsertSort(false);
    s.Print();
    cout<<"\nInitialized from Sort::Sort(8,6,1,4,1,1,6,4,5):\n";
    s=Sort(8,6,1,4,1,1,6,4,5);
    s.Print();
    cout<<"\nSorted in ascending order using quicksort:\n";
    s.QuickSort(true);
    s.Print();
    cout<<"\nSorted in descending order using quicksort:\n";
    s.QuickSort(false);
    s.Print();
    cout<<"\nInitialized from Sort::Sort("<<'"'<<"24,130,67,90,24"<<'"'<<"):\n";
    s=Sort("24,130,67,90,24");
    s.Print();
    cout<<"\nSize of s: "<<s.GetElementsCount()<<'\n';
    cout<<"Third element: "<<s.GetElementFromIndex(2)<<'\n';
    Sort s2(s);
    cout<<"\ns2 initialized from s:\n";
    s2.Print();
    return 0;
}
