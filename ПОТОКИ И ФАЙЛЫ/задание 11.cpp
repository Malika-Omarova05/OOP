/* Начните с класса bMoney, который мы последний раз видели в упражнении 5 главы 11.
Перегрузите операторы извлечения и вставки, чтобы можно было осуществлять ввод/вывод 
объектов этого класса. Выполните какой-нибудь ввод/вывод в main(). */
#include <iostream>
#include <string>
#include <iomanip> 
#include <Windows.h>
using namespace std;
class bMoney {
private:
    long double money;
public:
    bMoney() : money(0) {}
    explicit bMoney(long double m) : money(m) {}
    friend istream& operator>>(istream& in, bMoney& obj) {
        string input;
        cout << "Введите денежную сумму (без символов валюты): ";
        in >> input;
        try {
            obj.money = stold(input);
        }
        catch (...) {
            cout << "Ошибка ввода! Убедитесь, что сумма введена корректно.\n";
            in.clear();
            obj.money = 0;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const bMoney& obj) {
        out << fixed << setprecision(2) << obj.money << " руб.";
        return out;
    }
    void setMoney(long double m) {
        money = m;
    }
    long double getMoney() const {
        return money;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bMoney balance1, balance2;
    cout << "Введите первую денежную сумму:" << endl;
    cin >> balance1;
    cout << "Введите вторую денежную сумму:" << endl;
    cin >> balance2;
    cout << "\nПервая сумма: " << balance1 << endl;
    cout << "Вторая сумма: " << balance2 << endl;
    bMoney total;
    total.setMoney(balance1.getMoney() + balance2.getMoney());
    cout << "Общая сумма: " << total << endl;
    return 0;
}
