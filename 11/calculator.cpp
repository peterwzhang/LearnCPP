#include <ios>
#include <iostream>
#include <limits>
#include <functional>

int getInt(){
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    return num;
}

char getOp(){
    char op{};
    do{
        std::cout << "Enter an operation (+, -, *, /): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');
    return op;
}

int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

int divide(int x, int y){
    return x / y;
}

//using ArithmeticFunction = int (*)(int x, int y); // C like way
using ArithmeticFunction = std::function<int(int, int)>;
ArithmeticFunction getArithmeticFunction(char op){
    switch (op){
        default:
        case '+':
            return &add;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
    }
}


int main(){
    int x{ getInt() };
    char op{ getOp() };
    int y{ getInt() };
    //std::cout << x << ' ' << op << ' ' << y << " is " << getArithmeticFunction(op)(x, y); // call straight through function
    // make variable
    ArithmeticFunction fcn { getArithmeticFunction(op) };
    std::cout << x << ' ' << op << ' ' << y << " is " << fcn(x, y);
    return 0;
}