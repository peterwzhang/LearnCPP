#include <iostream>

// assumes the c-style string is null terminated
void printCString(char* word){
    for (char* index {word}; *index != '\0'; ++index){
        std::cout << *index;
    }
    std::cout << '\n';
}

int main(){
    char word[]{"Hello, World!"};
    printCString(word);
    return 0;
}