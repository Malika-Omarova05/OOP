/*Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) и уменьшения (--), которые работают в обе- 
их, префиксной и постфиксной, формах записи и возвращают значение.Дополните функцию main(), чтобы протестировать эти операции. */

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
        int secc = hour * 3600 + min * 60 + sec;
        int secc1 = t.hour * 3600 + t.min * 60 + t.sec;
        int sum = secc + secc1;
        int sumHour = (sum / 3600) % 24;
        int sumMin = (sum % 3600) / 60;
        int sumSec = (sum % 3600) % 60;
        return timee(sumHour, sumMin, sumSec);
    }
    timee& operator++() {
        sec++;
        adjustTime();
        return *this;
    }
    timee operator++(int) {
        timee temp = *this;
        sec++;
        adjustTime();
        return temp;
    }
    timee& operator--() {
        sec--;
        adjustTime();
        return *this;
    }
    timee operator--(int) {
        timee temp = *this;
        sec--;
        adjustTime();
        return temp;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    timee tt1, tt2, tt3;
    tt1.getdata();
    cout << "Исходное время: ";
    tt1.print();
    cout << "Применяем ++ (префиксная форма): ";
    ++tt1;
    tt1.print();
    cout << "Применяем ++ (постфиксная форма): ";
    tt1++;
    tt1.print();
    cout << "Применяем -- (префиксная форма): ";
    --tt1;
    tt1.print();
    cout << "Применяем -- (постфиксная форма): ";
    tt1--;
    tt1.print();
    tt2.getdata();
    tt3 = tt1 + tt2;
    tt3.print();

    return 0;
}
