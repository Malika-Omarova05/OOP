/*Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упраж- 
нение 5) в структуру employee из упражнения 4. Организуйте программу 
таким образом, чтобы пользователь вводил 4 пункта данных о каждом из 
трех сотрудников: его номер, величину зарплаты, его должность и дату 
принятия на работу. Программа должна хранить введенные значения в трех 
переменных типа employee и выводить их содержимое на экран. */
#include <iostream>
#include <string>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct date {
    int day;
    int month;
    int year;
};

struct employee {
    int number;
    double salary;
    etype pos;
    date d;
};

etype posit(char pos) {
    switch (pos) {
    case 'l': return laborer;
    case 's': return secretary;
    case 'm': return manager;
    case 'a': return accountant;
    case 'e': return executive;
    case 'r': return researcher;
    }
}

string posit1(etype position) {
    switch (position) {
    case laborer: return "laborer";
    case secretary: return "secretary";
    case manager: return "manager";
    case accountant: return "accountant";
    case executive: return "executive";
    case researcher: return "researcher";
    default: return "НЕ ПРАИВЛЬНЫЙ ВВОД!";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    employee emp1, emp2, emp3;

    cout << "Введите номер первого сотрудника: ";
    cin >> emp1.number;
    cout << "Введите величину зарплаты первого сотрудника: ";
    cin >> emp1.salary;
    cout << "Введите первую букву должности первого сотрудника (l, s, m, a, e, r): ";
    char pos1;
    cin >> pos1;
    emp1.pos = posit(pos1);
    cout << "Введите дату принятия на работу первого сотрудника (день месяц год): ";
    cin >> emp1.d.day >> emp1.d.month >> emp1.d.year;

    cout << "Введите номер второго сотрудника: ";
    cin >> emp2.number;
    cout << "Введите величину зарплаты второго сотрудника: ";
    cin >> emp2.salary;
    cout << "Введите первую букву должности второго сотрудника (l, s, m, a, e, r): ";
    char pos2;
    cin >> pos2;
    emp2.pos = posit(pos2);
    cout << "Введите дату принятия на работу второго сотрудника (день месяц год): ";
    cin >> emp2.d.day >> emp2.d.month >> emp2.d.year;

    cout << "Введите номер третьего сотрудника: ";
    cin >> emp3.number;
    cout << "Введите величину зарплаты третьего сотрудника: ";
    cin >> emp3.salary;
    cout << "Введите первую букву должности третьего сотрудника (l, s, m, a, e, r): ";
    char pos3;
    cin >> pos3;
    emp3.pos = posit(pos3);
    cout << "Введите дату принятия на работу третьего сотрудника (день месяц год): ";
    cin >> emp3.d.day >> emp3.d.month >> emp3.d.year;

    cout << "\nДанные первого сотрудника:\n";
    cout << "Номер: " << emp1.number << endl;
    cout << "Зарплата: " << emp1.salary << endl;
    cout << "Должность: " << posit1(emp1.pos) << endl;
    cout << "Дата принятия на работу: " << emp1.d.day << "/" << emp1.d.month << "/" << emp1.d.year << endl;

    cout << "\nДанные второго сотрудника:\n";
    cout << "Номер: " << emp2.number << endl;
    cout << "Зарплата: " << emp2.salary << endl;
    cout << "Должность: " << posit1(emp2.pos) << endl;
    cout << "Дата принятия на работу: " << emp2.d.day << "/" << emp2.d.month << "/" << emp2.d.year << endl;

    cout << "\nДанные третьего сотрудника:\n";
    cout << "Номер: " << emp3.number << endl;
    cout << "Зарплата: " << emp3.salary << endl;
    cout << "Должность: " << posit1(emp3.pos) << endl;
    cout << "Дата принятия на работу: " << emp3.d.day << "/" << emp3.d.month << "/" << emp3.d.year << endl;

    return 0;
}
