#include "Circuit.h"
#include<bits/stdc++.h>

using namespace std;

int main()
{
   Circuit c;
   c.SetLength(300);
   c.SetWeather(Weather::Rain);
   c.AddCar(new Volvo());
   c.AddCar(new BMW());
   c.AddCar(new Seat());
   c.AddCar(new Fiat());
   c.AddCar(new RangeRover());
   c.Race();
   cout<<"\nRace 1:\n\n";
   c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
   c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   cout<<"\nRace 2:\n\n";
   c.SetLength(510);
   c.SetWeather(Weather::Snow);
   c.Race();
   c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
   c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   cout<<"\nRace 3:\n\n";
   c.SetLength(400);
   c.SetWeather(Weather::Sunny);
   c.Race();
   c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
   c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   return 0;
}

