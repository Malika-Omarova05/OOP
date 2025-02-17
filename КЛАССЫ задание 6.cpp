/*Расширьте содержание класса employee из упражнения 4, включив в него класс date и перечисление etype (см. упражнение 6 главы 4). Объект клас- 
са date будет использоваться для хранения даты приема сотрудника на работу. Перечисление будет использовано для хранения статуса сотрудника: 
лаборант, секретарь, менеджер и т. д. Последние два поля данных должны быть закрытыми в определении класса employee, как и номер и оклад сотруд- 
ника. Вам будет необходимо разработать методы getemploy() и putemploy(), предназначенные соответственно для ввода и отображения информации о 
сотруднике. Возможно, при создании методов вам понадобится ветвление switch для работы с перечисляемым типом etype. Напишите функцию main(), 
которая попросит пользователя ввести данные о трех сотрудниках, а затем выведет эти данные на экран. */
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void getdata() {
        cout << "Введите дату принятия на работу:" << endl;
        cout << "Введите день: ";
        cin >> day;
        cout << "Введите месяц: ";
        cin >> month;
        cout << "Введите год: ";
        cin >> year;
    }
    void print() const {
        cout << (day < 10 ? "0" : "") << day << "/"
            << (month < 10 ? "0" : "") << month << "/"
            << year;
    }
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

etype posit(char pos) {
    switch (pos) {
    case 'l': return laborer;
    case 's': return secretary;
    case 'm': return manager;
    case 'a': return accountant;
    case 'e': return executive;
    case 'r': return researcher;
    default: return laborer;
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
    default: return "НЕПРАВИЛЬНЫЙ ВВОД!";
    }
}

class Employee {
private:
    int num;
    float salary;
    Date date;
    etype status;

public:
    Employee() : num(0), salary(0.0), status(laborer) {}
    void getdata1() {
        cout << "Введите номер сотрудника: ";
        cin >> num;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
        date.getdata();
        char ch;
        cout << "Введите первую букву должности (l, s, m, a, e, r): ";
        cin >> ch;
        status = posit(ch);
    }
    void putemploy() const {
        cout << "Номер сотрудника: " << num << endl;
        cout << "Оклад сотрудника: $" << salary << endl;
        cout << "Дата приема на работу: ";
        date.print();
        cout << endl;
        cout << "Статус сотрудника: " << posit1(status) << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Employee emp1, emp2, emp3;
    cout << "Введите данные для первого сотрудника:\n";
    emp1.getdata1();
    cout << "\nВведите данные для второго сотрудника:\n";
    emp2.getdata1();
    cout << "\nВведите данные для третьего сотрудника:\n";
    emp3.getdata1();

    cout << "\nДанные первого сотрудника:\n";
    emp1.putemploy();
    cout << "\nДанные второго сотрудника:\n";
    emp2.putemploy();
    cout << "\nДанные третьего сотрудника:\n";
    emp3.putemploy();

    return 0;
}
