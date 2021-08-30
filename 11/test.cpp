// ./gen.exe | ./test.exe
// this puts the cout of gen into the cin of test
#include <iostream>
 
int main(int argc, char *argv[])
{
    int count  = 0;
    while (true){
        if (count == 10) break;
        int num{};
        std::cin >> num;
        std::cout << "You entered " << num <<  '\n';
        count++;
    }
    return 0;
}