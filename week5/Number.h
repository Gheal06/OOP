#define NUMBER_MAX_LEN 16
class Number
{
    int* v;
    int n,base;
public:
    Number();
    Number(const char * value, int base); // where base is between 2 and 16
    Number(int oth);
    ~Number();

    Number(const Number&);
    Number(Number&&);
    int operator [] (int index);
    bool operator < (Number oth);
    bool operator <= (Number oth);
    bool operator > (Number oth);
    bool operator >= (Number oth);
    bool operator == (Number oth);
    bool operator != (Number oth);
    friend Number operator + (Number a, Number b);
    friend Number operator - (Number a, Number b);
    friend Number& operator += (Number& a, Number b);
    Number& operator = (int oth);
    Number& operator = (const Number& oth);
    Number& operator = (const char* oth);
    Number& operator -- ();
    Number& operator -- (int);
    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase(); // returns the current base
};
