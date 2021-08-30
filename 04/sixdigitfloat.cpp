#include <iostream>
 
int main()
{
    // By default only 6 sig fig will be printed to console.
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';
 
    return 0;
}