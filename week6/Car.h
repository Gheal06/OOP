#pragma once
#include "Weather.h"
#include "cfloat"
#include "cstring"
#define DNF FLT_MAX
class Car{
protected:
    float fuel_capacity, fuel_consumption, average_speed[3];
    char brand[16];
public:
    void PrintBrandName();
    virtual float GetRaceTime(float, Weather) = 0;
};
