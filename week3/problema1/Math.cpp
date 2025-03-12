#include "Math.h"
#include <cstring>
#include <algorithm>
#include <cstdarg>
int Math::Add(int a, int b){
    return a+b;
}
int Math::Add(int a,int b,int c){
        return a+b+c;
    }
int Math::Add(double a,double b){
    return a+b;
}
int Math::Add(double a,double b,double c){
    return a+b+c;
}
int Math::Mul(int a,int b){
    return a*b;
}
int Math::Mul(int a,int b,int c){
    return a*b*c;
}
int Math::Mul(double a,double b){
    return a*b;
}
int Math::Mul(double a,double b,double c){
    return a+b+c;
}
int Math::Add(int count,...){
    va_list args;
    va_start(args,count);
    int s=0;
    for(int i=0;i<count;i++)
        s+=va_arg(args,int);
    return s;
}
char* Math::Add(const char * a, const char * b){
    if(a==NULL || b==NULL) return NULL;
    int n=strlen(a),m=strlen(b),l=std::max(n,m)+1;
    char* s = new char [l+1];
    for(int i=0;i<l;i++){
        s[l-i-1]=0;
        if(i<n) s[l-i-1]+=a[n-i-1]-'0';
        if(i<m) s[l-i-1]+=b[m-i-1]-'0';
        if(i){
            s[l-i-1]+=s[l-i]/10;
            s[l-i]%=10;
            s[l-i]+=48;
        }

    }
    if(s[0]){
        s[0]+=48;
    }
    else{
        for(int i=1;i<l;i++) s[i-1]=s[i];
        s[l-1]=0;
    }
    return s;
}
