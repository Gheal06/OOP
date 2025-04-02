#pragma once
#include "Weather.h"
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
class Circuit{
    Car** cars;
    bool raced=1;

    int n;
    float length;
    Weather weather;
public:
    Circuit();
    void SetLength(float);
    void SetWeather(Weather);
    void AddCar(Car*);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
