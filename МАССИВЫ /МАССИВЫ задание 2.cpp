/*Создайте класс employee, который содержит имя (объект класса string) и номер (типа long) служащего. Включите в него метод getdata(), предназна- 
ченный для получения данных от пользователя и помещения их в объект, и метод putdata(), для вывода данных. Предполагаем, что имя не может иметь 
внутренних пробелов. Напишите функцию main(), использующую этот класс. Вам нужно будет 
создать массив типа employee, а затем предложить пользователю ввести данные до 100 служащих. Наконец, вам нужно будет вывести данные всех 
служащих. */
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class employee {
private:
    string name;
    long number;
public:
    void getdata() {
        cout << "Введите имя сотрудника: ";
        cin >> name;
        cout << "Введите номер сотрудника: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Имя: " << name << ", Номер: " << number << endl;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int max = 100;
    employee employees[max];
    int n;
    link:
    cout << "Сколько сотрудников вы хотите ввести (макс 100)? ";
    cin >> n;
    if (n > max) {
        cout << "Можно ввести не более 100 сотрудников." << endl;
        goto link;
    }
    for (int i = 0; i < n; ++i) {
        cout << "Введите данные для сотрудника #" << (i + 1) << ":" << endl;
        employees[i].getdata();
    }
    cout << "\nДанные всех сотрудников:\n";
    for (int i = 0; i < n; ++i) {
        employees[i].putdata();
    }
    return 0;
}
