#include <iostream>
#include "GradeBook.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");

    string name;
    cout << "Введите имя студента: ";
    getline(cin, name);

    GradeBook gradeBook(name);

    char choice;
    do {
        int grade;
        cout << "Введите оценку для студента (0 для завершения): ";
        cin >> grade;
        if (grade == 0) {
            break;
        }
        gradeBook.addGrade(grade);

        cout << "Хотите добавить еще одну оценку? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    gradeBook.displayGrades();
    cout << "Средний балл: " << gradeBook.calculateAverage() << endl;

    return 0;
}
