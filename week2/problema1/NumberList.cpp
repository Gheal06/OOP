#include "NumberList.h"
#include <iostream>

void NumberList::Init(){
    // count will be 0
    this->count=0;
}
bool NumberList::Add(int x){      // adds X to the numbers list and increase the data member count.
    if(count<10)
        this->numbers[count++]=x;
}
                          // if count is bigger or equal to 10, the function will return false
void NumberList::Sort(){
    for(int i=0;i<this->count;i++)
        for(int j=i+1;j<this->count;j++)
            if(this->numbers[i]>this->numbers[j]){
                this->numbers[j]^=this->numbers[i];
                this->numbers[i]^=this->numbers[j];
                this->numbers[j]^=this->numbers[i];
            }
            // will sort the numbers vector
}
void NumberList::Print(){
    for(int i=0;i<this->count;i++)
        std::cout<<this->numbers[i]<<' ';
}        // will print the current vector


