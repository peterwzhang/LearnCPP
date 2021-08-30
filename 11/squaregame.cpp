#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
int generateRandomNum(int min, int max){
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::uniform_int_distribution dist{min, max};
    return dist(mt);
}

std::vector<int> generateNums(int start, int count, int multiplier){
    std::vector<int> numbers(count);
    for (auto& n : numbers){
        n = start * start * multiplier;
        ++start;
    }
    return numbers;
}

void guessNums(std::vector<int> &numbers){
    while (true){
        int num{};
        std::cin >> num;
        auto found = std::find(numbers.begin(), numbers.end(), num);
        if (found != numbers.end()){
            if (numbers.size() - 1 == 0) {
                std::cout << "Nice! You found all numbers, good job!";
                return;
            }
            else {
                std::cout << "Nice! " << numbers.size() - 1 << " number(s) left.\n";
                numbers.erase(found);
            }
        }
        else {
            int closest = *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b){ 
                return std::abs(a - num) < std::abs(b - num);
                });
            if (std::abs(closest - num) <= 4){
                std::cout << num << " is wrong! Try " << closest << " next time.\n";
                return;
            }
            else {
                std::cout << num << " is wrong!\n";
                return;
            }
        }
    }
}

int main(){
    std::cout << "Start where? ";
    int start{};
    std::cin >> start;
    std::cout << "How many? ";
    int count{};
    std::cin >> count;
    int randomMult{generateRandomNum(2, 4)};
    std::vector<int> numbers{ generateNums(start, count, randomMult)};
    std::cout << "I generated " << count << " square numbers." << " Do you know what each number is after multiplying it by " << randomMult << "?\n";
    guessNums(numbers);
    return 0;
}