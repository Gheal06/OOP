#include "RangeRover.h"
RangeRover::RangeRover(){
    this->average_speed[Weather::Sunny]=130;
    this->average_speed[Weather::Rain]=85;
    this->average_speed[Weather::Snow]=60;
    this->fuel_consumption=10;
    this->fuel_capacity=50;
    strcpy(this->brand,"Range Rover");
}
float RangeRover::GetRaceTime(float len, Weather w){
    float t=len/this->average_speed[w]+8/3600.0; // startup time
    if(len*fuel_consumption>this->fuel_capacity*100) return DNF;
    return t;
}




