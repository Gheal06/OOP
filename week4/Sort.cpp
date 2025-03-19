#include "Sort.h"
#include <random>
#include <chrono>
#include <cstring>
#include <iostream>
#include <cstdarg>
#include <climits>
void Swap(int& x, int &y){
    int aux=x;
    x=y;
    y=aux;
    aux=x;
}
Sort::Sort(int n, int Min, int Max){
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rnd(Min,Max);
    this->n=n;
    for(int i=0;i<n;i++)
        this->v[i]=rnd(gen);
}
Sort::Sort(int n, int* v){
    this->n=n;
    for(int i=0;i<n;i++)
        this->v[i]=v[i];
}
Sort::Sort(int n, ...){
    va_list args;
    va_start(args,n);
    this->n=n;
    for(int i=0;i<n;i++)
        this->v[i]=va_arg(args,int);
}
Sort::Sort(const char* s){
    this->n=0;
    int l=strlen(s),num=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9') num=(num<<1)+(num<<3)+(s[i]^48);
        else this->v[this->n++]=num,num=0;
    }
    this->v[this->n++]=num;
}
Sort::Sort(const Sort& oth){
    this->n=oth.n;
    for(int i=0;i<this->n;i++)
        this->v[i]=oth.v[i];
}
void Sort::InsertSort(bool ascendent){
    for(int i=1;i<this->n;i++)
        for(int j=i-1;j>=0;j--)
            if((ascendent && this->v[j+1]<this->v[j]) || (!ascendent && this->v[j+1]>this->v[j]))
                Swap(this->v[j+1],this->v[j]);
}
void Sort::__quicksort(int l, int r, long long Seed){
    if(l<0 || r<0 || l>=r) return;
    int pivot=l+Seed%(r-l+1);
    Swap(this->v[pivot],this->v[l]);
    pivot=this->v[l];
    int i=l-1,j=r+1;
    while(1){
        do{
            i++;
        }while(this->v[i]<pivot);
        do{
            j--;
        }while(this->v[j]>pivot);
        if(i>=j) break;
        Swap(this->v[i],this->v[j]);
    }
    __quicksort(l,j,Seed);
    __quicksort(j+1,r,Seed);
}
void Sort::QuickSort(bool ascendent){
    std::mt19937_64 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> rnd(0,LLONG_MAX);
    __quicksort(0,this->n-1,rnd(gen));
    if(!ascendent)
        for(int i=0;i*2+1<n;i++)
            Swap(v[i],v[n-i-1]);
}
void Sort::BubbleSort(bool ascendent){
    for(int i=0;i<this->n;i++)
        for(int j=i+1;j<this->n;j++)
            if((ascendent && this->v[i]>this->v[j]) || (!ascendent && this->v[i]<this->v[j]))
                Swap(v[i],v[j]);
}
void Sort::Print(){
    for(int i=0;i<this->n;i++){
        std::cout<<this->v[i];
        if(i+1<this->n) std::cout<<' ';
    }
}
int Sort::GetElementsCount(){
    return this->n;
}
int Sort::GetElementFromIndex(int index){
    return this->v[index];
}
