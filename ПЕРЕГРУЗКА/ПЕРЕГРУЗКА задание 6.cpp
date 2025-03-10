/*Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя перегруженную операцию -, и умножать эти значе- 
ния, используя тип float и перегруженную операцию *. */
#include <iostream>
using namespace std;

class timee {
private:
    int hour;
    int min;
    int sec;
    void adjustTime() {
        if (sec >= 60) {
            min += sec / 60; sec %= 60;
        }
        else if (sec < 0) {
            min -= (abs(sec) / 60) + 1; sec += 60;
        }
        if (min >= 60) {
            hour += min / 60; min %= 60;
        }
        else if (min < 0) {
            hour -= (abs(min) / 60) + 1;  min += 60;
        }
        if (hour >= 24) {
            hour %= 24;
        }
        else if (hour < 0) {
            hour += 24;
        }
    }
public:
    timee() : hour(0), min(0), sec(0) {}
    timee(int h, int m, int s) : hour(h), min(m), sec(s) { adjustTime(); }
    void getdata() {
        cout << "Введите часы -> ";
        cin >> hour;
        cout << "Введите минуты -> ";
        cin >> min;
        cout << "Введите секунды -> ";
        cin >> sec;
        adjustTime();
    }
    void print() const {
        cout << (hour < 10 ? "0" : "") << hour << ":"
            << (min < 10 ? "0" : "") << min << ":"
            << (sec < 10 ? "0" : "") << sec << endl;
    }
    timee operator+(const timee& t) const {
        int totalSec1 = hour * 3600 + min * 60 + sec;
        int totalSec2 = t.hour * 3600 + t.min * 60 + t.sec;
        int totalSum = totalSec1 + totalSec2;

        int h = (totalSum / 3600) % 24;
        int m = (totalSum % 3600) / 60;
        int s = totalSum % 60;

        return timee(h, m, s);
    }
    timee operator-(const timee& t) const {
        int totalSec1 = hour * 3600 + min * 60 + sec;
        int totalSec2 = t.hour * 3600 + t.min * 60 + t.sec;
        int totalDiff = totalSec1 - totalSec2;

        if (totalDiff < 0) {
            totalDiff += 24 * 3600; 
        }

        int h = (totalDiff / 3600) % 24;
        int m = (totalDiff % 3600) / 60;
        int s = totalDiff % 60;

        return timee(h, m, s);
    }
    timee operator*(float factor) const {
        int totalSec = (hour * 3600 + min * 60 + sec) * factor;

        int h = (totalSec / 3600) % 24;
        int m = (totalSec % 3600) / 60;
        int s = totalSec % 60;

        return timee(h, m, s);
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    timee t1, t2;
    cout << "Введите первое время:" << endl;
    t1.getdata();
    cout << "Введите второе время:" << endl;
    t2.getdata();
    cout << "Время 1: ";
    t1.print();
    cout << "Время 2: ";
    t2.print();
    timee t3 = t1 - t2;
    cout << "Результат вычитания: ";
    t3.print();
    timee t5 = t1 + t2;
    cout << "Результат сложения: ";
    t5.print();
    timee t4 = t1 * 2.5;
    cout << "Результат умножения на 2.5: ";
    t4.print();

    return 0;
}
