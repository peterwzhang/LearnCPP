#include <iostream>

int sumTo(int num){
    int sum {0};
    for (int i {1}; i <= num; ++i){
        sum += i;
    }
    return sum;
}

int main(){
    std::cout << sumTo(5) << '\n';
    return 0;
}