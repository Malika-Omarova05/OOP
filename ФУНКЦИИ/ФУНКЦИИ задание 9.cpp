/*Переработайте программу из упражнения 8 так, чтобы функция swap() 
принимала в качестве аргументов значения типа time (см. упражнение 6). */
#include <iostream>
#include <iomanip>
using namespace std;

struct timee {
    int hour;
    int min;
    int sec;
};

void swap(timee& a, timee& b);

int main() {
    setlocale(LC_ALL, "rus");
    timee a, b;
    do {
        cout << "Введите часы: "; cin >> a.hour;
    } while (a.hour > 24 || a.hour < 0);
    do {
        cout << "Введите минуты: "; cin >> a.min;
    } while (a.min > 60 || a.min < 0);
    do {
        cout << "Введите секунды: "; cin >> a.sec;
    } while (a.sec > 60 || a.sec < 0);
    cout << endl;
    do {
        cout << "Введите часы: "; cin >> b.hour;
    } while (b.hour > 24 || b.hour < 0);
    do {
        cout << "Введите минуты: "; cin >> b.min;
    } while (b.min > 60 || b.min < 0);
    do {
        cout << "Введите секунды: "; cin >> b.sec;
    } while (b.sec > 60 || b.sec < 0);
    cout << "ДО:    "
        << setfill('0') << setw(2) << a.hour << ":"
        << setfill('0') << setw(2) << a.min << ":"
        << setfill('0') << setw(2) << a.sec << "\t"
        << setfill('0') << setw(2) << b.hour << ":"
        << setfill('0') << setw(2) << b.min << ":"
        << setfill('0') << setw(2) << b.sec << endl;
    swap(a, b);
    cout << "ПОСЛЕ: "
        << setfill('0') << setw(2) << a.hour << ":"
        << setfill('0') << setw(2) << a.min << ":"
        << setfill('0') << setw(2) << a.sec << "\t"
        << setfill('0') << setw(2) << b.hour << ":"
        << setfill('0') << setw(2) << b.min << ":"
        << setfill('0') << setw(2) << b.sec << endl;

    return 0;
}

void swap(timee& a, timee& b) {
    timee temp = a;
    a = b;
    b = temp;
}
