/*Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо 
метода add_time() можно было использовать операцию + для складывания 
двух значений времени. Напишите программу для проверки класса. */
#include <iostream>
using namespace std;

class timee {
private:
    int hour;
    int min;
    int sec;

public:
    timee() : hour(0), min(0), sec(0) {}
    timee(int h, int m, int s) : hour(h), min(m), sec(s) {}

    void getdata() {
        cout << "Введите часы -> ";
        cin >> hour;
        cout << "Введите минуты -> ";
        cin >> min;
        cout << "Введите секунды -> ";
        cin >> sec;
    }

    void print() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
            << (min < 10 ? "0" : "") << min << ":"
            << (sec < 10 ? "0" : "") << sec << endl;
    }

    timee operator+(timee);
};

timee timee::operator+(timee t) {
    int secc = hour * 3600 + min * 60 + sec;
    int secc1 = t.hour * 3600 + t.min * 60 + t.sec;
    int sum = secc + secc1;

    int sumHour = (sum / 3600) % 24;
    int sumMin = (sum % 3600) / 60;
    int sumSec = (sum % 3600) % 60;

    return timee(sumHour, sumMin, sumSec);
}

int main() {
    setlocale(LC_ALL, "rus");
    timee tt1(11, 59, 59);
    timee tt2;
    cout << "Время 1: ";
    tt1.print();
    cout << "Время 2:\n ";
    tt2.getdata();
    tt2.print();
    cout << "Результат сложения : ";
    timee tt3 = tt1 + tt2;
    tt3.print();
    return 0;
}
