#include <iostream>

struct Fraction{
    int numerator;
    int denominator;
};

Fraction readFraction(){
    std::cout << "Enter a numerator and denominator\n";
    int numerator {0}, denominator {0};
    std::cin >> numerator >> denominator;
    return Fraction {numerator, denominator};
}

double multiply(Fraction f1, Fraction f2){
    return (static_cast<double>(f1.numerator) * f2.numerator) / (f1.denominator * f2.denominator);
}

int main(){
    Fraction f1 {readFraction()};
    Fraction f2 {readFraction()};
    std::cout << "After multiplying: " << multiply(f1, f2) << '\n';
    return 0;
}