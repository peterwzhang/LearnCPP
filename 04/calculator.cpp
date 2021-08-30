#include <iostream>

double getDouble(){
    std::cout << "Enter a double value: ";
    double value{};
    std::cin >> value;
    return value;
}

char getOperator(){
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

double calculate(double numOne, char op, double numTwo){
    switch (op) {
    case '*':
        return numOne * numTwo;
    case '/':
        return numOne / numTwo;
    case '-':
        return numOne - numTwo;
    default:
    case '+':
        return numOne + numTwo;
    }
}

int main(){

    double valueOne {getDouble()};
    double valueTwo {getDouble()};
    char op {getOperator()};
    std::cout << valueOne << ' ' << op << ' ' << valueTwo << " is " << calculate(valueOne, op, valueTwo) << '\n';

    return 0;
}