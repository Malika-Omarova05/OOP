/*Напишите программу, объединяющую в себе классы bMoney из упражнения 8 и sterling из упражнения 11. Напишите операцию преобразования 
для преобразования между классами bMoney и sterling, предполагая, что один фунт (£1.0.0) равен пятидесяти долларам ($50.00). Это приблизи- 
тельный курс обмена для XIX века, когда Британская империя еще использовала меру фунты-шиллинги-пенсы. Напишите программу main(), 
которая позволит пользователю вводить суммы в каждой из валют и преобразовывать их в другую валюту с выводом результата. Минимизируйте 
количество изменений в существующих классах bMoney и sterling. */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
class Sterling;
class bMoney {
private:
    long double money; 
public:
    bMoney() : money(0.0) {}
    explicit bMoney(long double m) : money(m) {}
    void getmoney() {
        cout << "Введите денежную сумму в долларах: $";
        cin >> money;
    }
    void putmoney() const {
        cout << "Денежная сумма в долларах: $" << fixed << setprecision(2) << money << endl;
    }
    operator Sterling() const;
    long double value() const {
        return money;
    }
};
class Sterling {
private:
    long pounds;
    int shillings;
    int pence;

public:
    Sterling() : pounds(0), shillings(0), pence(0) {}
    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}
    explicit Sterling(double decimalPounds) {
        pounds = static_cast<long>(decimalPounds);
        double fractionalPart = (decimalPounds - pounds) * 20; 
        shillings = static_cast<int>(fractionalPart);
        pence = static_cast<int>(round((fractionalPart - shillings) * 12)); 
    }
    void getdata() {
        char ch;
        cout << "Введите сумму в фунтах в формате £9.19.11: ";
        cin >> ch >> pounds >> ch >> shillings >> ch >> pence;
    }
    void putdata() const {
        cout << "Сумма в фунтах: £" << pounds << "." << shillings << "." << pence << endl;
    }
    operator bMoney() const {
        double decimalPounds = pounds + shillings / 20.0 + pence / 240.0;
        return bMoney(decimalPounds * 50.0); 
    }
};
bMoney::operator Sterling() const {
    double decimalPounds = money / 50.0;
    return Sterling(decimalPounds);
}
int main() {
    setlocale(LC_ALL, "rus");
    bMoney dollars;
    Sterling pounds;
    char choice;
    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Преобразование из долларов в фунты\n";
        cout << "2. Преобразование из фунтов в доллары\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == '1') {
            dollars.getmoney();
            pounds = dollars; 
            cout << "\nЭквивалент в фунтах:\n";
            pounds.putdata();
        }
        else if (choice == '2') {
            pounds.getdata();
            dollars = pounds;
            cout << "\nЭквивалент в долларах:\n";
            dollars.putmoney();
        }
        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

        cout << "\nХотите продолжить? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

