#include "GradeBook.h"
#include <iostream>
#include <numeric>

GradeBook::GradeBook(const std::string& name) : studentName(name) {}

void GradeBook::addGrade(int grade) {
    grades.push_back(grade);
}

void GradeBook::displayGrades() const {
    std::cout << "ќценки студента " << studentName << ": ";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

double GradeBook::calculateAverage() const {
    if (grades.empty()) {
        return 0.0;
    }
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    return sum / grades.size();
}
