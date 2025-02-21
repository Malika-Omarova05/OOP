/*Напишите программу, вычисляющую среднее значение до 100 интервалов, 
введенных пользователем. Создайте массив объектов класса Distance, как 
это было сделано в примере ENGLARAY этой главы. Для вычисления сред- 
него значения вы можете позаимствовать метод add_dist() из примера 
ENGLCON главы 6. Вам также понадобится метод, который выделяет целую 
часть из значения Distance. Вот одна из возможностей:*/
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}
    void getdata() {
        cout << "Введите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }
    void showdata() const {
        cout << feet << "\' - " << inches << "\"";
    }
    void add_dist(Distance, Distance);
    void div_dist(Distance, int);
};

void Distance::add_dist(Distance d2, Distance d3) {
    inches = d2.inches + d3.inches;
    feet = d2.feet + d3.feet;
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
}
void Distance::div_dist(Distance d2, int divisor) {
    float fltfeet = d2.feet + d2.inches / 12.0;
    float temp = fltfeet / divisor;
    feet = int(temp);
    inches = (temp - feet) * 12.0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX = 100;
    Distance dist[MAX];
    int n;
    link:
    cout << "Сколько интервалов вы хотите ввести (макс 100)? ";
    cin >> n;
    if (n > MAX) {
        cout << "Можно ввести не более 100 интервалов." << endl;
        goto link;
    }
    for (int i = 0; i < n; i++) {
        cout << "Введите данные для интервала #" << (i + 1) << ":" << endl;
        dist[i].getdata();
    }
    Distance total(0, 0.0);
    for (int i = 0; i < n; i++) {
        Distance temp;
        temp.add_dist(total, dist[i]);
        total = temp;
    }
    Distance average;
    average.div_dist(total, n);
    cout << "\nСреднее значение интервалов: ";
    average.showdata();
    cout << endl;
    return 0;
}
