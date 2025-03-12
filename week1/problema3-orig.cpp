#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int tr = 2; tr < n / ......; tr++) // 1, nu poate fi inlocuit cu 2, deoarece atunci 4 ar fi considerat prim
        if ((n % ...... ) == 0) // tr
            return ......; // false
    return true; // programul nu merge pentru n=0 si n=1
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> ......; // n
    if (isPrime(n))
        std::cout << n << " is prime !";
    else 
        std::cout << n << " is NOT prime !";
    return 0;
}