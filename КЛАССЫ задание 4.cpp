/* Создайте класс employee, используя упражнение 4 главы 4. Класс должен включать поле типа int для хранения номера сотрудника и поле типа float 
для хранения величины его оклада. Методы класса должны позволять пользователю вводить и отображать данные класса. Напишите функцию 
main(), которая запросит пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран. */
#include <iostream>
using namespace std;
class Employee {
private:
    int num;
    float salary;
public:
    Employee() : num(0), salary(0.0) {}
    void getData() {
        cout << "Введите номер сотрудника: ";
        cin >> num;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }
    void displayData() const {
        cout << "Номер сотрудника: " << num << endl;
        cout << "Оклад сотрудника: $" << salary << endl;
    }
};

int main() {
    Employee emp1, emp2, emp3;
    cout << "Введите данные для первого сотрудника:\n";
    emp1.getData();
    cout << "Введите данные для второго сотрудника:\n";
    emp2.getData();
    cout << "Введите данные для третьего сотрудника:\n";
    emp3.getData();

    cout << "\nДанные первого сотрудника:\n";
    emp1.displayData();
    cout << "\nДанные второго сотрудника:\n";
    emp2.displayData();
    cout << "\nДанные третьего сотрудника:\n";
    emp3.displayData();

    return 0;
}
