#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
    Math math;
    cout<<math.Add(3,4)<<'\n';
    cout<<math.Add(3,4,5)<<'\n';
    cout<<math.Add(3.5,4.4)<<'\n';
    cout<<math.Add(3.5,4.4,3.5)<<'\n';
    cout<<math.Mul(3,4)<<'\n';
    cout<<math.Mul(3,4,5)<<'\n';
    cout<<math.Mul(3.5,4.4)<<'\n';
    cout<<math.Mul(3.5,4.4,3.5)<<'\n';
    cout<<math.Add(4,1,2,3,4)<<'\n';
    cout<<math.Add("12345","98764");
    return 0;
}
