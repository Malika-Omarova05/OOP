/*Напишите шаблон функции, возвращающей среднее арифметическое всех 
элементов массива. Аргументами функции должны быть имя и размер 
массива (типа int). В main() проверьте работу функции с массивами типа 
int, long, double  и char. */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
T avg(T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

template <typename T>
void get(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

template <>
void get<char>(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 'A' + rand() % 26; 
    }
}

template <typename T>
void print(T* arr, int size, char a) {
    for (int i = 0; i < size; i++) {
        cout << a << "[" << i << "]=" << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "rus");

    int intn, doublen, longn, charn;
    cout << "Введите количество переменных для массива int: "; cin >> intn;
    int* arrint = new int[intn];
    get(arrint, intn);

    cout << "Введите количество переменных для массива double: "; cin >> doublen;
    double* arrdouble = new double[doublen];
    get(arrdouble, doublen);

    cout << "Введите количество переменных для массива long: "; cin >> longn;
    long* arrlong = new long[longn];
    get(arrlong, longn);

    cout << "Введите количество переменных для массива char: "; cin >> charn;
    char* arrchar = new char[charn];
    get(arrchar, charn);

    cout << "Массив int I:" << endl; print(arrint, intn, 'I'); cout << "Среднее: " << avg(arrint, intn) << endl;
    cout << "Массив double D:" << endl; print(arrdouble, doublen, 'D'); cout << "Среднее: " << avg(arrdouble, doublen) << endl;
    cout << "Массив long L:" << endl; print(arrlong, longn, 'L'); cout << "Среднее: " << avg(arrlong, longn) << endl;
    cout << "Массив char C:" << endl; print(arrchar, charn, 'C'); cout << "Среднее: " << static_cast<int>(avg(arrchar, charn)) << endl;

    delete[] arrint;
    delete[] arrdouble;
    delete[] arrlong;
    delete[] arrchar;

    return 0;
}
