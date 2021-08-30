#include <iostream>

namespace Animals{
    enum Animals{
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        num_Animals
    };
}

int main(){
    int animalFeet[Animals::num_Animals]{2, 4, 4, 4, 2, 0};
    std::cout << "An elephant has " << animalFeet[Animals::elephant] << " legs.\n";
    for (int i = Animals::chicken; i < Animals::num_Animals; ++i){
        std::cout << animalFeet[i] << '\n';
    }
    return 0;
}