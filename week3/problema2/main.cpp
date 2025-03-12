#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
    Canvas canvas(100,50);
    canvas.DrawRect(3,5,13,15,'#');
    canvas.FillRect(4,6,12,14,'.');
    canvas.DrawCircle(20,30,10,'@');
    canvas.FillCircle(20,30,9,'.');
    canvas.DrawLine(10,13,25,45,'%');
    canvas.DrawLine(26,49,27,35,'*');
    canvas.DrawLine(50,50,35,35,'!');
    canvas.Print();
    return 0;
}
