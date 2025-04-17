/*Добавьте к упражнению 9 проверку на наличие ошибок в операторе извлечения (>>). Но при этом, видимо, потребуется запрашивать сначала 
первую дробь, затем оператор, затем вторую дробь. Одним выражением, как в упражнении 9, уже будет не обойтись. Вывод сообщений об ошиб- 
ках сделает работу с программой более понятной.
Введите первую дробь: 5/0
Знаменатель не может быть нулевым!
Введите первую дробь заново: 5/1
Введите оператор (+, -, *, /): +
Введите вторую дробь: одна треть
Ошибка ввода
Введите вторую дробь заново: 1/3
Ответ:  .....................  16/3
Продолжить (y/n)? n 
Как показывает этот пример, необходимо следить за флагами ошибок iosи за тем, чтобы знаменатель не был равен нулю. Если возникает ошибка,
пользователю должно быть предложено ввести данные еще раз. */
#include <iostream>
#include <cmath>
#include <limits> 
using namespace std;
class Fraction {
private:
    int chis; 
    int znam; 
    void lowterms() {
        long tnum = labs(chis);
        long tden = labs(znam);
        if (tden == 0) {
            cout << "Знаменатель не может быть нулевым!" << endl;
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
    Fraction(int a, int b) : chis(a), znam(b) {}
    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        while (true) {
            cout << "Введите дробь в формате числитель/знаменатель: ";
            in >> f.chis >> slash >> f.znam;

            if (!in || slash != '/' || f.znam == 0) {
                cout << "Ошибка ввода! Убедитесь, что знаменатель не равен нулю и формат корректный.\n";
                in.clear(); 
                in.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            else {
                f.lowterms(); 
                break;
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.chis << "/" << f.znam;
        return out;
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
    Fraction frac1, frac2, result;
    char operation;
    do {
        cout << "Введите первую дробь: ";
        cin >> frac1;
        cout << "Введите оператор (+, -, *, /): ";
        cin >> operation;
        while (!cin || (operation != '+' && operation != '-' && operation != '*' && operation != '/')) {
            cout << "Ошибка ввода! Убедитесь, что оператор один из (+, -, *, /).\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Введите оператор заново: ";
            cin >> operation;
        }
        cout << "Введите вторую дробь: ";
        cin >> frac2;
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
        }
        cout << "Ответ: " << result << endl;
        cout << "Продолжить (y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;

    } while (true);

    return 0;
}
