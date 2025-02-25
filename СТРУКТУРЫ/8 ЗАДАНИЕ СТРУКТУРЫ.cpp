/*Вернитесь к упражнению 9 главы 2 «Основы программирования на C++». 
В этом упражнении требуется написать программу, которая хранит значе- 
ния двух дробей в виде числителя и знаменателя, а затем складывает эти 
дроби согласно арифметическому правилу. Измените эту программу так, 
чтобы значения дробей хранились в струкtype fraction, состоящей из двух 
полей типа int, предназначенных для хранения числителя и знаменателя. 
Все значения дробей должны храниться в переменных типа fraction. */
#include <iostream>
using namespace std;
struct fraction {
    int chis;  
    int znam; 
};

int main() {
    setlocale(LC_ALL, "rus");
    fraction f1, f2, sum;
    cout << "Введите числитель и знаменатель первой дроби: ";
    cin >> f1.chis >> f1.znam;
    cout << "Введите числитель и знаменатель второй дроби: ";
    cin >> f2.chis >> f2.znam;
    if (f1.znam == 0 || f2.znam == 0) {
        cout << "Ошибка: знаменатель не может быть равен нулю." << endl;
        return 1;
    }
    if (f1.znam == f2.znam) {
        sum.chis = f1.chis + f2.chis;
        sum.znam = f1.znam;
    }
    else {
        sum.chis = f1.chis * f2.znam + f2.chis * f1.znam;
        sum.znam = f1.znam * f2.znam;
    }
    cout << "Сумма дробей: " << sum.chis << "/" << sum.znam << endl;
    return 0;
}
