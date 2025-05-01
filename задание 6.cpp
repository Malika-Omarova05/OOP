/*Начните работу с класса safearay из программы ARROVER3 (глава 8). Сделай- 
те класс шаблоном, чтобы массив мог хранить любые типы данных. В сек- 
ции main() создайте, по крайней мере, два массива разных типов. */
#include <iostream>
#include <cstdlib>

using namespace std;

const int LIMIT = 100;

template <typename mlk>
class SafeArray {
private:
    mlk arr[LIMIT];
    int l;
    int u;
public:
    SafeArray(int lower, int upper) {
        if (upper - lower >= LIMIT || lower >= upper) {
            cout << "\nНекорректные границы массива!";
            exit(1);
        }
        l = lower;
        u = upper;
    }

    mlk& operator[](int index) {
        if (index < l || index > u) {
            cout << "\nОшибочный индекс!";
            exit(1);
        }
        return arr[index - l];
    }

    int size() const {
        return u - l + 1;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    int v, ni;
    cout << "Введите нижнюю границу массива int: ";
    cin >> v;
    cout << "Введите верхнюю границу массива int: ";
    cin >> ni;
    SafeArray<int> intArray(v, ni);
    for (int i = v; i <= ni; i++)
        intArray[i] = i * 10;
    for (int i = v; i <= ni; i++)
        cout << "Элемент intArray[" << i << "] = " << intArray[i] << endl;

    cout << "Введите нижнюю границу массива double: ";
    cin >> v;
    cout << "Введите верхнюю границу массива double: ";
    cin >> ni;
    SafeArray<double> doubleArray(v, ni);
    for (int i = v; i <= ni; i++)
        doubleArray[i] = i * 1.5;
    for (int i = v; i <= ni; i++)
        cout << "Элемент doubleArray[" << i << "] = " << doubleArray[i] << endl;

    cout << "Введите нижнюю границу массива char: ";
    cin >> v;
    cout << "Введите верхнюю границу массива char: ";
    cin >> ni;
    SafeArray<char> charArray(v, ni);
    for (int i = v; i <= ni; i++)
        charArray[i] = 'A' + (i - v);
    for (int i = v; i <= ni; i++)
        cout << "Элемент charArray[" << i << "] = " << charArray[i] << endl;

    return 0;
}
