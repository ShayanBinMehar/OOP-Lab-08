#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int grades[3];

public:
    Student(const std::string& n) : name(n) {
        for (int i = 0; i < 3; ++i) {
            grades[i] = 0;
        }
    }

    std::string getName() const {
        return name;
    }

    void displayGrades() const {
        std::cout << "Grades for " << name << ": ";
        for (int i = 0; i < 3; ++i) {
            std::cout << grades[i] << " ";
        }
        std::cout << std::endl;
    }

    friend class Teacher;
    friend double calculateAverageGrade(const Student& student);
};

class Teacher {
public:
    void updateGrade(Student& student, int index, int newGrade) {
        if (index >= 0 && index < 3) {
            student.grades[index] = newGrade;
            std::cout << "Grade for " << student.name << " at index " << index << " updated to " << newGrade << std::endl;
        } else {
            std::cout << "Invalid grade index." << std::endl;
        }
    }

    void viewGrades(const Student& student) const {
        student.displayGrades();
    }
};

double calculateAverageGrade(const Student& student) {
    double sum = 0;
    for (int grade : student.grades) {
        sum += grade;
    }
    return sum / 3.0;
}

int main() {

    Student student1("Alice");

    Teacher teacher1;

    student1.displayGrades();

    double initialAverage = calculateAverageGrade(student1);
    std::cout << "Initial Average Grade for " << student1.getName() << ": " << initialAverage << std::endl;
    std::cout << std::endl;

    teacher1.updateGrade(student1, 1, 85);

    student1.displayGrades();

    double newAverage = calculateAverageGrade(student1);
    std::cout << "New Average Grade for " << student1.getName() << ": " << newAverage << std::endl;

    return 0;
}