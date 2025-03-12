/* Вспомним программу ARROVER3 из главы 8. Сохраним класс safearay таким же и, используя наследование, добавим к нему возможность для пользо- 
вателя определять верхнюю и нижнюю границы массива в конструкторе. Это похоже на упражнение 9 из главы 8, за исключением того, что при- 
менено наследование для создания нового класса (можно назвать его safehilo) взамен модификации исходного класса.*/
// используется перегрузка операции [] 
#include <iostream>
#include <process.h>  
using namespace std;
const int LIMIT = 100;
class safearray {
private:
    int arr[LIMIT];
public:
    int& operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "\nОшибочный индекс!";
            exit(1);
        }
        return arr[n];
    }
};

class safehilo : public safearray {
private:
    int lower; 
    int upper; 
public:
    safehilo(int low, int high) : lower(low), upper(high) {
        if (low < 0 || high >= LIMIT || low > high) {
            cout << "\nОшибочные границы!";
            exit(1);
        }
    }
    int& operator[](int n) {
        if (n < lower || n > upper) {
            cout << "\nИндекс за пределами допустимых границ!";
            exit(1);
        }
        return safearray::operator[](n);
    }
    void show() const {
        cout << "Границы массива: [" << lower << ", " << upper << "]" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int l, u;
    cout << "Введите нижнюю границу: "; cin >> l;
    cout << "Введите верхнюю границу: "; cin >> u;
    safehilo sa(l, u);
    for (int i = l; i <= u; i++) {
        sa[i] = i * 10;
    }
    sa.show();
    for (int i = l; i <= u; i++) {
        cout << "Элемент " << i << " равен " << sa[i] << endl;
    }

    return 0;
}
