/*В примере PLUSAIR мы показали применение версии accumulate() с четырь- 
мя аргументами. Перепишите этот пример, используя версию с тремя ар- 
гументами. */
#include <iostream>
#include <list>
#include <numeric>

using namespace std;

class airtime {
private:
    int hours;
    int minutes;

public:
    airtime() : hours(0), minutes(0) {}
    airtime(int h, int m) : hours(h), minutes(m) {}

    void display() const {
        cout << hours << ':' << minutes;
    }

    void get() {
        char dummy;
        cout << "\nВведите время (формат 12:59): ";
        cin >> hours >> dummy >> minutes;
    }

    airtime operator+(const airtime& right) const {
        int temph = hours + right.hours;
        int tempm = minutes + right.minutes;
        if (tempm >= 60) {
            temph++;
            tempm -= 60;
        }
        return airtime(temph, tempm);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    char answer;
    airtime temp, sum;
    list<airtime> airlist;

    do {
        temp.get();
        airlist.push_back(temp);
        cout << "Продолжить (y/n)? ";
        cin >> answer;
    } while (answer != 'n');

    sum = accumulate(airlist.begin(), airlist.end(), airtime(0, 0));

    cout << "\nСумма = ";
    sum.display();
    cout << endl;

    return 0;
}
