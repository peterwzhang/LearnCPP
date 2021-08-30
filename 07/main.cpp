#include <iostream>
#include "constants.h"
 
double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };
 
    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}
 
double calculateAndPrintHeight(double initialHeight, int time)
{
    double height {calculateHeight(initialHeight, time)};
    std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";
    return height;
}

void fallUntilGround(double initialHeight){
    for (int sec = 0; calculateAndPrintHeight(initialHeight, sec) > 0; ++sec){}
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
	
    fallUntilGround(initialHeight);
	
    return 0;
}