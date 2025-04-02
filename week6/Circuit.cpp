#include "Circuit.h"
#include <iostream>
Circuit::Circuit(){
    this->n=0;
    this->length=0;
    this->cars=new Car*[101];
}
void Circuit::SetLength(float x){
    this->length=x;
}
void Circuit::SetWeather(Weather w){
    this->weather=w;
}
void Circuit::AddCar(Car* c){
    cars[n++]=c;
}
void Circuit::Race(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cars[i]->GetRaceTime(length,weather)>cars[j]->GetRaceTime(length,weather)){
                Car* aux=cars[j];
                cars[j]=cars[i];
                cars[i]=aux;
            }
        }
    }
}
void Circuit::ShowFinalRanks(){
    std::cout<<"Ranking:\n";
    int rnk=1;
    for(int i=0;i<n;i++){
        if(cars[i]->GetRaceTime(length,weather)!=DNF){
            std::cout<<rnk<<". ";
            rnk++;
            cars[i]->PrintBrandName();
            std::cout<<": "<<cars[i]->GetRaceTime(length,weather)<<"h\n";
        }
    }
}
void Circuit::ShowWhoDidNotFinish(){
    std::cout<<"DNFs:\n";
    int rnk=1;
    for(int i=0;i<n;i++){
        if(cars[i]->GetRaceTime(length,weather)==DNF){
            std::cout<<rnk<<". ";
            rnk++;
            cars[i]->PrintBrandName();
            std::cout<<": "<<"DNF\n";
        }
    }
}
