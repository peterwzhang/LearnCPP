#include "io.h"

int readNumber();

void returnAnswer(int num);

int main(){
    int x {readNumber()};
    int y {readNumber()};
    returnAnswer(x + y);
    return 0;
}