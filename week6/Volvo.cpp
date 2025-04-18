#include "Volvo.h"
Volvo::Volvo(){
    this->average_speed[Weather::Sunny]=130;
    this->average_speed[Weather::Rain]=90;
    this->average_speed[Weather::Snow]=50;
    this->fuel_consumption=8;
    this->fuel_capacity=43;
    strcpy(this->brand,"Volvo");
}
float Volvo::GetRaceTime(float len, Weather w){
    float t=len/this->average_speed[w]+10/3600.0; // startup time
    if(len*fuel_consumption>this->fuel_capacity*100) return DNF;
    return t;
}
