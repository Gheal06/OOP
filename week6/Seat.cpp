#include "Seat.h"
Seat::Seat(){
    this->average_speed[Weather::Sunny]=110;
    this->average_speed[Weather::Rain]=80;
    this->average_speed[Weather::Snow]=40;
    this->fuel_consumption=7;
    this->fuel_capacity=35;
    strcpy(this->brand,"Seat");
}
float Seat::GetRaceTime(float len, Weather w){
    float t=len/this->average_speed[w]+6/3600.0; // startup time
    if(t*this->fuel_consumption>this->fuel_capacity) return DNF;
    return t;
}


