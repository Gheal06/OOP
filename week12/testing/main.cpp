#include <iostream>
#include "Sort.h"
using namespace std;
int v[10001]={8,5,9,1,2,7,10,6,4,3};
int main(){
    Sort<int> s(10,v);
    s.QuickSort(1);
    s.Print();
    cout<<'\n'<<s.GetElementsCount();
    cout<<'\n'<<*s.GetElementFromIndex(0);
}