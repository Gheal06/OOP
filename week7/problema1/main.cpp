#include<bits/stdc++.h>

using namespace std;
long double operator ""_Kelvin(long double x){
    return x-273.15;
}
long double operator ""_Fahrenheit(long double x){
    return (x-32)/1.8;
}
long double operator ""_Kelvin(unsigned long long x){
    return x-273.15;
}
long double operator ""_Fahrenheit(unsigned long long x){
    return (x-32)/1.8;
}
int main() {
    float a = 300_Kelvin;
    cout<<"a="<<a<<'\n';
    float b = 120_Fahrenheit;

    cout<<"b="<<b<<'\n';
    return 0;
}

