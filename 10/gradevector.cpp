#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student{
    std::string name{};
    int grade{};
};

void inputStudent(std::vector<Student> &students, size_t index){
    std::string name{};
    int grade{};
    std::cin >> name >> grade;
    students[index] = { name, grade };
}

void printStudent(Student &s){
    std::cout << s.name << " got a grade of " << s.grade << '\n';
}

bool compareGrades(const Student &s1, const Student &s2){
    return s1.grade > s2.grade;
}

int main(){
    std::cout << "How many students? ";
    int numStudents{};
    std::cin >> numStudents;
    std::vector<Student> students(numStudents);

    for (auto i = 0; i < numStudents; ++i){
        inputStudent(students, i);
    }

    std::sort(students.begin(), students.end(), compareGrades);

    std::for_each(students.begin(), students.end(), printStudent);



    return 0;
}