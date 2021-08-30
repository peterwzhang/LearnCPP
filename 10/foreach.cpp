#include <iostream>
#include <string_view>

int main(){
    constexpr std::string_view names[]{"Alex", "Betty", "Caroline", "Davis", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string name{};
    std::cin >> name;
    bool found{ false };
    for (const auto n : names){
        if (n == name) {
            found = true;
            break;
        }
    }
    if (found) std::cout << name << " was found.";
    else std::cout << name << " was not found.";
    return 0;
}