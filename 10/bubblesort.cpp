#include <iostream>
#include <iterator>
#include <utility>

int main(){
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int aSize = static_cast<int>(std::size(array));
    for (int i{0}; i < aSize - 1; ++i){
        bool anySwaps {false};
        for (int j{0}; j < aSize - i - 1; ++j)
        {
            if (array[j] > array[j + 1]){
                std::swap(array[j], array[j+1]);
                anySwaps = true;
            }
        }
        if (!anySwaps){
            std::cout << "Early termination on iteration " << (i+1) << '\n';
            break; 
        }
    }

    for (int index{0}; index < aSize; ++index){
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
    return 0;
}
// 1 2 3 4 5 6 7 8 9