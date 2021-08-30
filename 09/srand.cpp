#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
 
int main()
{
    std::srand(5323); // set initial seed value to 5323
 
    // Due to a flaw in some compilers, we need to call std::rand() once here to get "better" random numbers.
    std::rand();
 
    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';
 
        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
	}
 
    return 0;
}