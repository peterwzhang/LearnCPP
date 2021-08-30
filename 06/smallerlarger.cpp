#include <iostream>

int main(){
    std::cout << "Enter a smaller and larger value: ";
    int smaller{}, larger{};
    std::cin >> smaller >> larger;
    if (larger < smaller){
        std::cout << "Swapping the values\n";
        int temp{larger};
        larger =  smaller;
        smaller = temp;
    } // temp dies here
    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';
    return 0;
} // smaller, larger die here