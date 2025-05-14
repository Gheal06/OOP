#include<bits/stdc++.h>
#include "Array.h"


using namespace std;

int main()
{
    Array<int> v(16);
    v+=3;
    v[0]=2;
    for(auto it : v){
        cout<<it<<' ';
    }
    cout<<'\n';
    v.Insert(0,5);
    for(auto it : v){
        cout<<it<<' ';
    }
    cout<<'\n';
    v.Insert(2,v);
    for(auto it : v){
        cout<<it<<' ';
    }
    cout<<'\n';
    v.Delete(0);
    for(auto it : v){
        cout<<it<<' ';
    }
    cout<<'\n';
    v.Sort();
    for(auto it : v){
        cout<<it<<' ';
    }
    cout<<'\n';

    cout<<v.BinarySearch(2)<<' '<<v.BinarySearch(3)<<'\n';
    cout<<v.Find(2)<<' '<<v.Find(3)<<'\n';

    cout<<v.GetSize()<<' '<<v.GetCapacity()<<'\n';
    cout<<v.begin().__ptr()<<' '<<v.end().__ptr()<<'\n';
    return 0;
}

