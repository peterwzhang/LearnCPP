#include <iostream>

int getUserInput(){
    std::cout << "Enter a num: ";
    int input{};
    std::cin >> input;
    return input;
}

int doubleNumber(int x){
    return x * 2;
}

int main(){
    int num = getUserInput();
    std::cout << doubleNumber(num) << '\n';
    return 0;
}