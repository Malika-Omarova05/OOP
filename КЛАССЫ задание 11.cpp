/*Модифицируйте калькулятор, созданный в упражнении 12 главы 5 так, чтобы вместо структуры fraction использовался одноименный класс. Класс 
должен содержать методы для ввода и вывода данных объектов, а также для выполнения арифметических операций. Кроме того, необходимо вклю- 
чить в состав класса функцию, приводящую дробь к несократимому виду. Функция должна находить наибольший общий делитель числителя и зна- 
менателя и делить числитель и знаменатель на это значение. Код функции, названной lowterms(), приведен ниже: 
void fraction::lowterms() .... } 
Можно вызывать данную функцию в конце каждого метода, выполняющего арифметическую операцию, либо непосредственно перед выводом 
на экран результата. Кроме перечисленных методов, вы можете включить в класс конструктор с двумя аргументами, что также будет полезно.*/
#include <iostream>
#include <cmath>
using namespace std;
class Fraction {
private:
    int chis; 
    int znam; 
    void lowterms() {
        long tnum, tden, temp, gcd;
        tnum = labs(chis);  
        tden = labs(znam);
        if (tden == 0) {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0) {
            chis = 0;
            znam = 1;
            return;
        }
        while (tnum != 0) {
            if (tnum < tden) { 
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden; 
        }
        gcd = tden; 
        chis = chis / gcd;
        znam = znam / gcd;
    }

public:
    Fraction() : chis(0), znam(1) {}
    Fraction(int n, int d) : chis(n), znam(d) {
        lowterms();
    }
    void getFraction() {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        cin >> chis >> slash >> znam;
        lowterms(); 
    }
    void showFraction() const {
        cout << chis << "/" << znam << endl;
    }
    Fraction add(const Fraction& f) const {
        int num = chis * f.znam + f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction subtract(const Fraction& f) const {
        int num = chis * f.znam - f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction multiply(const Fraction& f) const {
        int num = chis * f.chis;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction divide(const Fraction& f) const {
        int num = chis * f.znam;
        int den = znam * f.chis;
        return Fraction(num, den);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    char choice;
    do {
       
        Fraction frac1, frac2;
        cout << "Введите первую дробь:\n";
        frac1.getFraction();
        cout << "Введите вторую дробь:\n";
        frac2.getFraction();

        cout << "Выберите операцию (+, -, *, /): ";
        char operation;
        cin >> operation;

        Fraction result;
        switch (operation) {
        case '+':
            result = frac1.add(frac2);
            break;
        case '-':
            result = frac1.subtract(frac2);
            break;
        case '*':
            result = frac1.multiply(frac2);
            break;
        case '/':
            result = frac1.divide(frac2);
            break;
        default:
            cout << "Неправильный ввод операции!\n";
            continue;
        }

        cout << "Результат операции: ";
        result.showFraction();

        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
