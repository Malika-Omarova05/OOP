/*Переработайте программу-калькулятор для дробей, описанную в упраж- 
нении 12 главы 3 так, чтобы каждая из дробей хранилась как значение пе- 
ременной типа struct fraction, по аналогии с упражнением 8 этой главы. */
#include <iostream>
using namespace std;
struct fraction {
    int chis;  
    int znam; 
};

int main() {
    setlocale(LC_ALL, "rus");
    fraction f1, f2, result;
    char x;
    cout << "Введите первую дробь (числитель и знаменатель через пробел): ";
    cin >> f1.chis >> f1.znam;

    cout << "Введите операцию (+, -, *, /): ";
    cin >> x;

    cout << "Введите вторую дробь (числитель и знаменатель через пробел): ";
    cin >> f2.chis >> f2.znam;

    if (f1.znam == 0 || f2.znam == 0) {
        cout << "Ошибка: знаменатель не может быть равен нулю." << endl;
        return 1;
    }

    switch (x) {
    case '+':
        result.chis = f1.chis * f2.znam + f2.chis * f1.znam;
        result.znam = f1.znam * f2.znam;
        break;
    case '-':
        result.chis = f1.chis * f2.znam - f2.chis * f1.znam;
        result.znam = f1.znam * f2.znam;
        break;
    case '*':
        result.chis = f1.chis * f2.chis;
        result.znam = f1.znam * f2.znam;
        break;
    case '/':
        result.chis = f1.chis * f2.znam;
        result.znam = f1.znam * f2.chis;
        if (result.znam == 0) {
            cout << "Ошибка: деление на ноль." << endl;
            return 1;
        }
        break;
    default:
        cout << "Ошибка: неизвестная операция." << endl;
        return 1;
    }

    cout << "Результат: " << result.chis << "/" << result.znam << endl;

    return 0;
}
