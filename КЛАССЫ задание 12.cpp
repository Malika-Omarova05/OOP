/*Используйте преимущество ООП, заключающееся в том, что однажды созданный класс можно помещать в другие программы. Создайте новую 
программу, которая будет включать класс fraction, созданный в упражнении 11. Программа должна выводить аналог целочисленной таблицы 
умножения для дробей. Пользователь вводит знаменатель, а программа должна подобрать всевозможные целые значения числителя так, чтобы 
значения получаемых дробей находились между 0 и 1. Дроби из получившегося таким образом набора перемножаются друг с другом во всевоз- 
можных комбинациях, в результате чего получается таблица следующеговида (для знаменателя, равного 6): 
   1/6    1/3    1/2    2/3   5/6 
 ----------------------------------------- 
 1/6   1/36   1/18   1/12   1/9   5/36 
 1/3   1/18   1/9    1/6    2/9   5/18 
 1/2   1/12   1/6    1/4    1/3   5/12 
 2/3   1/9    2/9    1/3    4/9   5/9 
 5/6   5/36   5/18   5/12   5/9   25/36*/
#include <iostream>
#include <vector>
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
    void showFraction() const {
        cout << chis << "/" << znam;
    }
    Fraction multiply(const Fraction& f) const {
        int num = chis * f.chis;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int den;
    cout << "Введите знаменатель: ";
    cin >> den;
    vector<Fraction> fractions;
    for (int i = 1; i < den; ++i) {
        fractions.push_back(Fraction(i, den));
    }
    for (const auto& frac : fractions) {
        frac.showFraction();
        cout << "    ";
    }
    cout << endl << "-----------------------------------------" << endl;
    for (const auto& frac1 : fractions) {
        frac1.showFraction();
        cout << "  ";
        for (const auto& frac2 : fractions) {
            Fraction result = frac1.multiply(frac2);
            result.showFraction();
            cout << "  ";
        }
        cout << endl;
    }

    return 0;
}
