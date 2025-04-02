#include "Fiat.h"
Fiat::Fiat(){
    this->average_speed[Weather::Sunny]=80;
    this->average_speed[Weather::Rain]=50;
    this->average_speed[Weather::Snow]=40;
    this->fuel_consumption=6;
    this->fuel_capacity=34;
    strcpy(this->brand,"Fiat");
}
float Fiat::GetRaceTime(float len, Weather w){
    float t=len/this->average_speed[w]+6/3600.0; // startup time
    if(len*fuel_consumption>this->fuel_capacity*100) return DNF;
    return t;
}



