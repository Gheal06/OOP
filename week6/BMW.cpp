#include "BMW.h"
BMW::BMW(){
    this->average_speed[Weather::Sunny]=150;
    this->average_speed[Weather::Rain]=110;
    this->average_speed[Weather::Snow]=70;
    this->fuel_consumption=15;
    this->fuel_capacity=45;
    strcpy(this->brand,"BMW");
}
float BMW::GetRaceTime(float len, Weather w){
    float t=len/this->average_speed[w]+2/3600.0; // startup time
    if(len*fuel_consumption>this->fuel_capacity*100) return DNF;
    return t;
}

