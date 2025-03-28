/*Создайте класс, который позволит вам использовать 10 отдельных масси- 
вов из упражнения 10 как один одномерный массив, допуская примене- 
ние операций массива. То есть мы можем получить доступ к элементам 
массива, записав в функции main() выражение типа a[j], а методы класса 
могут получить доступ к полям класса, используя двухшаговый подход. 
Перегрузим операцию [] (см. главу 9 «Наследование»), чтобы получить 
нужный нам результат. Заполним массив данными и выведем их. Хотя 
для интерфейса класса использованы операции индексации массива, вам 
следует использовать указатели внутри методов класса. */
#include <iostream>
#include <cstdlib>
using namespace std;

class massiv {
private:
    const int mass = 10; 
    const int size = 10;    
    int** arr;             

public:
    massiv() {
        arr = new int* [mass];
        for (int i = 0; i < mass; i++) {
            *(arr + i) = new int[size];
        }
    }
    void deletee() {
        for (int i = 0; i < mass; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    int& operator[](int index) {
        int arrayIndex = index / size;     
        int elementIndex = index % size;  
        if (arrayIndex >= mass || elementIndex >= size) {
            cout << "Неправильный индекс!" << endl;
        }
        return arr[arrayIndex][elementIndex];
    }
    void random() {
        for (int i = 0; i < mass; i++) {
            for (int j = 0; j < size; j++) {
                *(*(arr + i) + j) = rand() % 100;
            }
        }
    }
    void display() const {
        for (int i = 0; i < mass; i++) {
            for (int j = 0; j < size; j++) {
                cout << "A[" << i << "][" << j << "]=" << *(*(arr + i) + j) << "  ";
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    massiv arr;
    arr.random();
    arr.display();
    link:
    cout << "Введите индекс элемента для получения (от 0 до 99): ";
    int index;
    cin >> index;
    if (index >= 0 && index < 100) {
        cout << "Элемент с индексом " << index << ": " << arr[index] << endl;
    }
    else {
        cout << "Неверный ввод! Повторите!"; goto link;
    }
    return 0;
}
