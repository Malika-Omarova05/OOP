/* Напишите функцию, принимающую в качестве аргументов два значения
типа Distance и возвращающую значение наибольшего из аргументов (не-
обходимую информацию можно найти в примере RETSTRC). */
#include <iostream>
using namespace std;

struct Distance {
    int feet;
    float inches;
};

Distance maxx(Distance, Distance);

int main() {
    setlocale(LC_ALL, "rus");
    Distance d1, d2;
    cout << "Введите футы для первой длины: "; cin >> d1.feet;
    cout << "Введите дюймы для первой длины: "; cin >> d1.inches;
    cout << "\nВведите футы для второй длины: "; cin >> d2.feet;
    cout << "Введите дюймы для второй длины: "; cin >> d2.inches;

    Distance max = maxx(d1, d2);
    cout << "Наибольшая длина: " << max.feet << "\'-" << max.inches << "\"" << endl;

    return 0;
}

Distance maxx(Distance dd1, Distance dd2) {
    float a = dd1.feet * 12 + dd1.inches;
    float b = dd2.feet * 12 + dd2.inches;
    if (a > b) return dd1;
    else return dd2;
}
