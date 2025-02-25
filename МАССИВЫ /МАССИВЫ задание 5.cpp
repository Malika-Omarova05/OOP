/* Начните с класса fraction из упражнений 11 и 12 главы 6. Напишите функцию main(), которая получает случайные дробные числа от пользова- 
теля, сохраняет их в массиве типа fraction, вычисляет среднее значение и выводит результат. */
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
class fraction {
private:
    int chis;
    int znam;
public:
    fraction() : chis(0), znam(1) {}
    fraction(int c, int z) : chis(c), znam(z) {
        if (z == 0) {
            cout << "Знаменатель не может быть равен нулю. Установлено значение по умолчанию: 1." << endl;
            znam = 1;
        }
    }
    void getdata() {
        cout << "Введите числитель: ";
        cin >> chis;
        link:
        cout << "Введите знаменатель: ";
        cin >> znam;
        if (znam == 0) {
            cout << "Знаменатель не может быть равен нулю. Установлено значение по умолчанию: 1." << endl;
            goto link;
        }
    }
    void showdata() const {
        cout << chis << "/" << znam;
    }
    void add_dist(fraction f1, fraction f2) {
        chis = f1.chis * f2.znam + f2.chis * f1.znam;
        znam = f1.znam * f2.znam;
    }
    void div_dist(fraction total, int count) {
        chis = total.chis;
        znam = total.znam * count;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX = 100;
    fraction fractions[MAX];
    int n;
    link1:
    cout << "Сколько дробей вы хотите ввести (макс 100)? ";
    cin >> n;
    if (n > MAX) {
        cout << "Можно ввести не более 100 дробей." << endl;
        goto link1;
    }
    for (int i = 0; i < n; i++) {
        cout << "Введите данные для дроби #" << (i + 1) << ":" << endl;
        fractions[i].getdata();
    }
    fraction total;
    for (int i = 0; i < n; i++) {
        fraction temp;
        temp.add_dist(total, fractions[i]);
        total = temp;
    }
    fraction average;
    average.div_dist(total, n);
    cout << "\nСреднее значение дробей: ";
    average.showdata();
    cout << endl;
    return 0;
}
