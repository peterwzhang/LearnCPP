#include <cmath>
#include <iostream>

double getHeight(){
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    return height;
}

double calculateDistFallen(int seconds, double gravConstant){
    return gravConstant * pow(seconds, 2) / 2;
}

bool printHeight(double curHeight, int s){
    if (curHeight <= 0.0){
            std::cout << "At " << s << " seconds, the ball is on the ground\n";
            return true;
    }
    else{
            std::cout << "At " << s << " seconds, the ball is at height: " << curHeight << " meters\n";
            return false;
    }
}

int main(){
    const double height {getHeight()};
    constexpr double gravity {9.8};
    double curHeight { height };
    for (int i = 0; i <= 5; ++i){
        curHeight = height - calculateDistFallen(i, gravity); 
        if (printHeight(curHeight, i)) break;
    }
    return 0;
}