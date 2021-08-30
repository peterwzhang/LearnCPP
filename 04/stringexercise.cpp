#include <iostream>
#include <string>

std::string getName(){
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int getAge(){
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;
    return age;
}

double calcAgePerLetter(std::string name, int age){
    return static_cast<double>(age) / name.length();
}

int main(){
    std::string name {getName()};
    int age {getAge()};
    std::cout << "You've lived " << calcAgePerLetter(name, age) << " for each letter in your name.\n";
    return 0;
}