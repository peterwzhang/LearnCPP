#include <array>
#include <iostream>

void swap(int& a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    std::array<int, 10> array { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    swap(array[0], array[9]);
    for (int num : array){
        std::cout << num << ' ';
    }
}