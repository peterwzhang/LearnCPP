#include <iostream>
#include <string>

int main(){
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    std::cout << "Double that number is: " + std::to_string(num * 2) << '\n';
    std::cout << "Triple that number is: " + std::to_string(num * 3) << '\n';
    return 0;
}