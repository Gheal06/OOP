#include "Car.h"

class BMW : public Car {
public:
    BMW();
    float GetRaceTime(float,Weather) override;
};

