#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    float GetRaceTime(float,Weather) override;
};



