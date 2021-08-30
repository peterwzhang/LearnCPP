#include <iostream>
#include <cstdint>
#include <stdint.h>

int getInput(){
    std::cout << "Enter a number between 0-255: ";
    int num{};
    std::cin >> num;
    if (num < 0 || num > 255) return getInput();
    return num;
}

void printBinary(int num){
    int number {0};
    int place {1};
    while (num != 0){
        number += (num % 2) * place;
        num /= 2;
        place *= 10; 
    }
    std::cout << number;
}
// 4 0 * 1
// 2 0 * 10
// 1 1 * 100
int main(){

    const int num {getInput()};
    printBinary(num);
    return 0;
}