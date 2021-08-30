#include <ios>
#include <iostream>
#include <limits>

void printArray(const int a[], int size){
    for (int i{ 0 }; i < size; ++i){
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int getInt(){
    while (true){
        std::cout << "Enter a number 1-9: ";
        int num{};
        std::cin >> num;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (num >= 1 && num <= 9) return num;
    }
}

void findNum(const int a[], int size, int num){
    for (int i{ 0 }; i < size; ++i){
        if (a[i] == num) {
            std::cout << num;
            return;
        }
    }
    std::cout << "Num not in array";
}

int main(){
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int aSize = static_cast<int>(std::size(array));
    int num{getInt()};
    printArray(array, aSize);
    findNum(array, aSize, num);
    return 0;
}