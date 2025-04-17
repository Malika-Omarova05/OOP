/*Начните с упражнения 7 главы 8 «Перегрузка операций» и перегрузите 
операторы извлечения (>>) и вставки (<<) для класса frac в нашем кальку- 
ляторе с четырьмя действиями. Имейте в виду, что операторы могут свя- 
зываться в цепочки, поэтому при выполнении действий с дробями пона- 
добится только одно выражение; cin >> frac1 >> op >> frac2; */
#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
class Fraction {
private:
    int chis;
    int znam; 
    void lowterms() {
        long tnum = labs(chis);
        long tden = labs(znam);
        if (tden == 0) {
            cout << "Недопустимый знаменатель!" << endl;
            exit(1);
        }
        else if (tnum == 0) {
            chis = 0;
            znam = 1;
            return;
        }

        while (tnum != 0) {
            if (tnum < tden) {
                swap(tnum, tden);
            }
            tnum -= tden;
        }
        long gcd = tden;
        chis /= gcd;
        znam /= gcd;
    }
public:
    Fraction() : chis(0), znam(1) {}
    Fraction(int n, int d) : chis(n), znam(d) {
        lowterms();
    }
    Fraction operator+(const Fraction& f) const {
        int num = chis * f.znam + f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction operator-(const Fraction& f) const {
        int num = chis * f.znam - f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction operator*(const Fraction& f) const {
        int num = chis * f.chis;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction operator/(const Fraction& f) const {
        int num = chis * f.znam;
        int den = znam * f.chis;
        return Fraction(num, den);
    }
    bool operator==(const Fraction& f) const {
        return chis == f.chis && znam == f.znam;
    }
    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        in >> f.chis >> slash >> f.znam;
        f.lowterms(); 
        return in;
    }
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.chis << "/" << f.znam;
        return out;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Fraction frac1, frac2, result;
    char operation;
    while (true) {
        cout << "Введите первую дробь: ";
        cin >> frac1;
        cout << "Введите вторую дробь: ";
        cin >> frac2;
        if (frac1 == Fraction(0, 1) && frac2 == Fraction(0, 1)) {
            cout << "Выход из программы." << endl;
            break;
        }
        cout << "Выберите операцию (+, -, *, /, =): ";
        cin >> operation;
        switch (operation) {
        case '+':
            result = frac1 + frac2;
            cout << "Результат: " << result << endl;
            break;
        case '-':
            result = frac1 - frac2;
            cout << "Результат: " << result << endl;
            break;
        case '*':
            result = frac1 * frac2;
            cout << "Результат: " << result << endl;
            break;
        case '/':
            result = frac1 / frac2;
            cout << "Результат: " << result << endl;
            break;
        case '=':
            if (frac1 == frac2)
                cout << "Дроби равны!" << endl;
            else
                cout << "Дроби НЕ равны!" << endl;
            break;
        default:
            cout << "Некорректная операция!" << endl;
        }
    }
    return 0;
}
