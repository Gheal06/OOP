#include "Sort.h"
#include <random>
#include <chrono>
#include <cstring>
#include <iostream>
#include <cstdarg>
#include <climits>

template<class T>
Sort<T>::Sort(int size){
    n = size;

    Elements = new T*[size];
    for(int i = 0 ; i < size; i++)
        Elements[i] = new T();

}

template<class T>
Sort<T>::Sort(int size, T* other){
    n = size;
    Elements = new T*[size];
    for(int i = 0 ; i < size; i++)
        Elements[i] = new T();

}

template<class T>
void Sort<T>::__quicksort(int l, int r, long long Seed){
    if(l<0 || r<0 || l>=r) return;
    int piElementsot=l+Seed%(r-l+1);
    std::swap(this->Elements[piElementsot],this->Elements[l]);
    piElementsot=*(this->Elements[l]);
    int i=l-1,j=r+1;
    while(1){
        do{
            i++;
        }while(*(this->Elements[i])<piElementsot);
        do{
            j--;
            while(1);
        }while(*(this->Elements[j])>piElementsot);
        if(i>=j) break;
        std::swap(this->Elements[i],this->Elements[j]);
    }
    __quicksort(l,j,Seed);
    __quicksort(j,r,Seed);
}

template<class T>
void Sort<T>::QuickSort(bool ascendent){
    std::mt19937_64 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> rnd(0,LLONG_MAX);
    __quicksort(0,this->n-1,rnd(gen));
    if(!ascendent)
        for(int i=0;i*2+1<n;i++)
            std::swap(Elements[i],Elements[n-i-1]);
}

template<class T>
void Sort<T>::Print(){
    for(int i=0;i<this->n;i++){
        std::cout<<this->Elements[i];
        if(i+1<this->n) std::cout<<' ';
    }
}

template<class T>
int Sort<T>::GetElementsCount(){
    return this->n;
}

template<class T>
T* Sort<T>::GetElementFromIndex(int index){
    return *this->Elements[index];
}
