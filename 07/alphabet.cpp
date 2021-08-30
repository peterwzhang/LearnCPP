#include <iostream>

void printAlphabet(){
    int startIndex {'a'};
    while (startIndex <= 'z'){
        std::cout << static_cast<char>(startIndex) << ' ';
        startIndex++;
    }
    return;
}

int main(){
    printAlphabet();
    return 0;
}