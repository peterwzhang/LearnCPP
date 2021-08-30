#include <iostream>

int factorial(int n){
    if (n <= 0) return 1;
    else return factorial(n - 1) * n;
}

int sumDigits(int n){
    if (n == 0) return 0;
    else return sumDigits(n / 10) + n % 10;
}

void printBinary(int n){
    if (n == 0) return;
    printBinary(n / 2);
    std::cout << n % 2;
}

// support for negative case
void decToBin(int input)
{
    unsigned int x = static_cast<unsigned int>(input); // a negative number into a unsigned will have same bit representation
    if (x == 0)
        std::cout << 0;
    else if (x == 1)
        std::cout << 1;
    else
    {
        int r = x % 2;
        decToBin(x / 2);
        std::cout << r;
    }
    
}
    int main(){
    std::cout << factorial(7) << '\n';
    std::cout << sumDigits(93427) << '\n';
    printBinary(10);
    decToBin(-15);
    return 0;
}