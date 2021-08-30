#include <iostream>
#include <string>

int main(){
    std::cout << "Enter an integer: ";
    int numOne{};
    std::cin >> numOne;
    std::cout << "Enter another integer: ";
    int numTwo{};
    std::cin >> numTwo;
    std::cout << std::to_string(numOne) + " + " + std::to_string(numTwo) + " is " + std::to_string(numOne + numTwo) + ".\n";
    std::cout << std::to_string(numOne) + " - " + std::to_string(numTwo) + " is " + std::to_string(numOne - numTwo) + ".\n";
    return 0;
}