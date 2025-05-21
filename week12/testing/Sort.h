#ifndef SORT_H
#define SORT_H
template<class T>
class Sort
{
    int n;
    T** Elements;
public:

    Sort(int n);
    Sort(int size, T* other);
    void QuickSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    T*  GetElementFromIndex(int index);

private:
    void __quicksort(int l, int r, long long Seed);
};

#include "Sort.cpp"
#endif
