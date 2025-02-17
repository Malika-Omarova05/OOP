/* На основе структуры fraction из упражнения 8 главы 4 создайте класс fraction. Данные класса должны быть представлены двумя полями: числи- 
телем и знаменателем. Методы класса должны получать от пользователя значения числителя и знаменателя дроби в форме 3/5 и выводить значе- 
ние дроби в этом же формате. Кроме того, должен быть разработан метод,складывающий значения двух дробей. Напишите функцию main(), которая 
циклически запрашивает у пользователя ввод пары дробей, затем складывает их и выводит результат на экран. После каждой такой операции про- 
грамма должна спрашивать пользователя, следует ли продолжать цикл. */
#include <iostream>
using namespace std;
class Fraction {
private:
    int chis;   
    int znam;
public:
    Fraction() : chis(0), znam(1) {}
    Fraction(int n, int d) : chis(n), znam(d) {}
    void getFraction() {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        cin >> chis >> slash >> znam;
    }
    void showFraction() const {
        cout << chis << "/" << znam << endl;
    }
    Fraction add(const Fraction& f) const {
        int num = chis * f.znam + f.chis * znam;
        int den = znam * f.znam;
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
        Fraction result = frac1.add(frac2);
        cout << "Результат сложения: ";
        result.showFraction();
        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
