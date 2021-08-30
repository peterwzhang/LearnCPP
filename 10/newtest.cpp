#include <iostream>

int main(){
    int* value { new (std::nothrow) int{5} }; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }
    std::cout << *value; // will fail if value is nullptr
}