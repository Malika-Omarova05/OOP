/* Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя не только 
имя человека, но и сведения о его зарплате в виде поля salary типа float. Вам будет необходимо изменить
методы setName() и printName() на setData() и printData(), включив в них возможность ввода и вывода 
значения salary, как это можно сделать с именем. Вам также понадобится метод getSalary(). Используя 
указатели, напишите функцию salsort(), которая сортирует указатели массива persPtr по значениям зарплаты.
Попробуйте вместить всю сортировку в функцию salsort(), не вызывая других функций, как это сделано в 
программе PERSORT. При этом не забывайте, что операция -> имеет больший приоритет, чем операция *, 
и вам нужно будет написать if((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) */ 
#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    float salary;
public:
    void setData(string n, float s) {
        name = n;
        salary = s;
    }
    void printData() const {
        cout << "Имя: " << name << ", Зарплата: " << salary << endl;
    }
    float getSalary() const {
        return salary;
    }
};
void salsort(Person* pp[], int size) {
    for (int j = 0; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                Person* temp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    const int SIZE = 3; 
    Person persons[SIZE];
    Person* persPtr[SIZE];
    persons[0].setData("Иван", 50000.0);
    persons[1].setData("Ольга", 65000.0);
    persons[2].setData("Сергей", 45000.0);
    for (int i = 0; i < SIZE; i++) {
        persPtr[i] = &persons[i];
    }
    cout << "До сортировки:" << endl;
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }
    salsort(persPtr, SIZE);
    cout << "\nПосле сортировки:" << endl;
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    return 0;
}
