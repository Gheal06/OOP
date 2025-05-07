#include<bits/stdc++.h>
#include "Map.h"


using namespace std;

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%lu, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%lu, Key=%d, Value=%s\n", index, key, value);
    }

    m.Set(40,"amongus");
    m.Delete(30);
    for (auto[key, value, index] : m)
    {
        printf("Index:%lu, Key=%d, Value=%s\n", index, key, value);
    }
    Map<int, const char *> m2;
    m2[20]="test";
    cout<<m.Includes(m2)<<'\n';
    m2[30]="test 2";
    cout<<m.Includes(m2)<<'\n';

    m.Clear();
    for (auto[key, value, index] : m)
    {
        printf("Index:%lu, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}

