/* Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 главы 6 так, чтобы он использовал перегру- 
женные операции сложения, вычитания, умножения и деления. (Вспомните правила арифметики с дробями в упражнении 12 главы 3 «Циклы и 
ветвления».) Также перегрузите операции сравнения == и != и используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения 
двух частей дроби. Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее аргумента, уменьшенное до несократи- 
мой дроби. Это будет полезным в арифметических функциях, которые могут быть выполнены сразу после получения ответа. */
#include <iostream>
#include <cmath>
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
    void getdata() {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        cin >> chis >> slash >> znam;
        lowterms();
    }
    void print() const {
        cout << chis << "/" << znam << endl;
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
};

int main() {
    setlocale(LC_ALL, "rus");

    Fraction frac1, frac2;
    char operation;

    while (true) {
        cout << "Введите первую дробь: " << endl;
        frac1.getdata();
        cout << "Введите вторую дробь: " << endl;
        frac2.getdata();

        if (frac1 == Fraction(0, 1) && frac2 == Fraction(0, 1)) {
            cout << "Выход из программы." << endl;
            break;
        }

        cout << "Выберите операцию (+, -, *, /, =(сравнение дробей): ";
        cin >> operation;

        Fraction result;
        switch (operation) {
        case '+':
            result = frac1 + frac2;
            break;
        case '-':
            result = frac1 - frac2;
            break;
        case '*':
            result = frac1 * frac2;
            break;
        case '/':
            result = frac1 / frac2;
            break;
        case '=':
            if (frac1 == frac2) cout << "Дроби равны!";
            else cout << "Дроби НЕ равны!";
            break;
        default:
            cout << "Некорректная операция!" << endl;
            continue;
        }

        cout << "Результат: ";
        result.print();
    }

    return 0;
}
