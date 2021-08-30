#include "add.h"
#include <iostream>
// g++ -o main -Iinclude main.cpp add.cpp
int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}