#include <iostream>

double calculate(int numOne, int numTwo, char op){
    switch(op){
        case '*':
            return numOne * numTwo;
        case '/':
            return static_cast<double>(numOne) / numTwo;
        case '%':
            return numOne % numTwo;
        case '+':
            return numOne + numTwo;
        case '-':
            return numOne - numTwo;
        default:
            std::cerr << "Unknown Operator";
            return 0;
    }
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
 
    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;
 
    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;
 
    std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';
 
    return 0;
}