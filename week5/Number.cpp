#include "Number.h"
#include <iostream>
#include <cstring>

Number::Number(){
    this->n=0;
    this->base=0;
    this->v = new int [NUMBER_MAX_LEN];
}
Number::Number(const char * value, int base){
    this->base=base;
    this->n=strlen(value);
    this->v=new int [NUMBER_MAX_LEN];
    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    for(int i=0;i<this->n;i++)
        this->v[this->n-i-1]=(value[i]>='0' && value[i]<='9'?value[i]-'0':value[i]-'A'+10);
}
Number::Number(const Number& oth){
    this->n=oth.n,this->base=oth.base;
    this->v=new int [NUMBER_MAX_LEN];
    for(int i=0;i<this->n;i++) this->v[i]=oth.v[i];
}
Number::Number(Number&& oth){
    this->n=oth.n;
    this->base=oth.base;
    this->v=oth.v;
    oth.v=nullptr;
}
Number::Number(int oth){
    this->base=10;
    this->v=new int [NUMBER_MAX_LEN];
    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    this->n=0;
    while(oth>0) v[this->n++]=oth%this->base,oth/=this->base;
}
Number::~Number(){
    if(this->v){
        delete[] this->v;
        this->v=nullptr;
    }
}
int Number::operator [] (int index){
    return this->v[this->n-index-1];
}

void Number::SwitchBase(int newBase){
    if(newBase==this->base) return;
    long long num=0,p=1;
    for(int i=0;i<this->n;i++)
        num+=this->v[i]*p,p*=this->base;
    this->base=newBase;
    this->n=0;

    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    while(num>0) v[this->n++]=num%this->base,num/=this->base;
}
void Number::Print(){
    for(int i=this->n-1;i>=0;i--)
        std::cout<<(char)(this->v[i]<=9?this->v[i]+'0':this->v[i]-10+'A');
    std::cout<<'\n';
}
int Number::GetDigitsCount(){
    return this->n;
}
int Number::GetBase(){
    return this->base;
}
bool Number::operator < (Number oth){
    oth.SwitchBase(this->base);
    if(this->n<oth.n) return true;
    if(this->n>oth.n) return false;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return this->v[i]<oth.v[i];
    return false;
}
bool Number::operator <= (Number oth){
    oth.SwitchBase(this->base);
    if(this->n<oth.n) return true;
    if(this->n>oth.n) return false;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return this->v[i]<oth.v[i];
    return true;
}
bool Number::operator > (Number oth){
    oth.SwitchBase(this->base);
    if(this->n>oth.n) return true;
    if(this->n<oth.n) return false;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return this->v[i]>oth.v[i];
    return false;
}
bool Number::operator >= (Number oth){
    oth.SwitchBase(this->base);
    if(this->n>oth.n) return true;
    if(this->n<oth.n) return false;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return this->v[i]>oth.v[i];
    return true;
}
bool Number::operator == (Number oth){
    oth.SwitchBase(this->base);
    if(this->n!=oth.n) return false;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return false;
    return true;
}
bool Number::operator != (Number oth){
    oth.SwitchBase(this->base);
    if(this->n!=oth.n) return true;
    for(int i=0;i<this->n;i++) if(this->v[i]!=oth.v[i]) return true;
    return false;
}
Number operator + (Number a, Number b){
    int maxbase=(a.base>b.base?a.base:b.base);
    Number sum;
    a.SwitchBase(maxbase),b.SwitchBase(maxbase);
    for(int i=0;i<NUMBER_MAX_LEN;i++){
        sum.v[i]=a.v[i]+b.v[i];
        if(i) sum.v[i]+=sum.v[i-1]/sum.base,sum.v[i-1]%=sum.base;
    }
    sum.n=NUMBER_MAX_LEN-1;
    sum.base=maxbase;
    while(sum.n>1 && sum.v[sum.n]==0) sum.n--;
    sum.n++;
    return sum;
}
Number operator - (Number a, Number b){
    int maxbase=(a.base>b.base?a.base:b.base);
    Number diff;
    a.SwitchBase(maxbase),b.SwitchBase(maxbase);
    for(int i=0;i<NUMBER_MAX_LEN;i++){
        diff.v[i]=a.v[i]-b.v[i];
        if(i && diff.v[i-1]<0) diff.v[i]--,diff.v[i-1]+=10;
    }
    diff.n=NUMBER_MAX_LEN-1;
    diff.base=maxbase;
    while(diff.n>1 && diff.v[diff.n]==0) diff.n--;
    diff.n++;
    return diff;
}
Number& operator += (Number& a, Number b){
    int maxbase=(a.base>b.base?a.base:b.base);
    a.SwitchBase(maxbase),b.SwitchBase(maxbase);

    a.base=maxbase;
    for(int i=0;i<NUMBER_MAX_LEN;i++){
        a.v[i]+=b.v[i];
        if(i) a.v[i]+=a.v[i-1]/a.base,a.v[i-1]%=a.base;
    }
    a.n=NUMBER_MAX_LEN-1;
    while(a.n>1 && a.v[a.n]==0) a.n--;
    a.n++;
    return a;
}
Number& Number::operator = (int oth){
    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    this->n=0;
    while(oth>0) v[this->n++]=oth%this->base,oth/=this->base;
    return *this;
}
Number& Number::operator = (const Number& oth){

    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    this->n=oth.n,this->base=oth.base;
    for(int i=0;i<this->n;i++) this->v[i]=oth.v[i];
    return *this;
}
Number& Number::operator = (const char* value){
    this->n=strlen(value);
    for(int i=0;i<NUMBER_MAX_LEN;i++) this->v[i]=0;
    for(int i=0;i<this->n;i++)
        this->v[this->n-i-1]=(value[i]>='0' && value[i]<='9'?value[i]-'0':value[i]-'A'+10);
    return *this;
}
Number& Number::operator -- (){
    this->v[--this->n]=0;
    return *this;
}
Number& Number::operator -- (int){
    for(int i=1;i<n;i++) this->v[i-1]=this->v[i];
    this->n--;
    return *this;
}
