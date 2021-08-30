#include <iostream>

int main(){
    std::cout << "Enter an integer: ";
    int num {};
    std::cin >> num;
    std::cout << num << " is " << ((num % 2 == 0) ? "even" : "odd") << '\n';
    return 0;
}