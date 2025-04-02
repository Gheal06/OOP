#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    float GetRaceTime(float,Weather) override;
};
