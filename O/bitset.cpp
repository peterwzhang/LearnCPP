#include <bitset>
#include <iostream>

int main(){
    std::cout << std::bitset<4> {1101} << '\n';
    std::cout << std::bitset<4> {0b1101} << '\n';
    std::bitset<4> testingSet(1101);
    std::cout << (testingSet << 1) << '\n';
    std::cout << testingSet << '\n';
}