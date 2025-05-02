/*За основу возьмите класс frac и калькулятор с четырьмя функциями из 
упражнения 7 главы 8. Сделайте этот класс шаблоном, чтобы его можно 
было реализовывать с использованием различных типов данных в качест- 
ве делимого и делителя. Конечно, это должны быть целочисленные типы, 
что строго ограничивает вас в их выборе (char, short, int и long). Можно, 
впрочем, определить и свой целочисленный класс, никто не запрещает. 
В main() реализуйте класс frac<char> и используйте его при разработке 
калькулятора с четырьмя функциями. Этому классу требуется меньше па- 
мяти, чем frac<int>, но с его помощью невозможно выполнять деление 
больших чисел. */
#include <iostream>
using namespace std;
template <class mlk>
class frac {
private:
    mlk chis, znam;
public:
    frac() : chis(0), znam(1) {}
    frac(mlk num, mlk den) {
        if (den == 0) {
            cout << "Ошибка: знаменатель не может быть 0!" << endl;
            exit(1);
        }
        chis = num;
        znam = den;
    }
    void getdata() {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        cin >> chis >> slash >> znam;
        if (znam == 0) {
            cout << "Ошибка: знаменатель не может быть 0!" << endl;
            exit(1);
        }
    }
    void putdata() const {
        cout << "Дробь: " << chis << "/" << znam << endl;
    }
    frac operator+(const frac& f) const {
        return frac(chis * f.znam + f.chis * znam, znam * f.znam);
    }
    frac operator-(const frac& f) const {
        return frac(chis * f.znam - f.chis * znam, znam * f.znam);
    }
    frac operator*(const frac& f) const {
        return frac(chis * f.chis, znam * f.znam);
    }
    frac operator/(const frac& f) const {
        if (f.chis == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return frac(chis * f.znam, znam * f.chis);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    char op;
    cout << "Тип данных int:" << endl;
    frac<int> int1, int2, resi;
    int1.getdata(); int2.getdata();
link1:
    cout << "Выберите операцию (+, -, *, /): ";
    cin >> op;
    switch (op) {
    case'+': resi = int1 + int2; break;
    case'-': resi = int1 - int2; break;
    case'*': resi = int1 * int2; break;
    case'/': resi = int1 / int2; break;
    default: cout << "Неверный ввод операции!\nПовторите ввод" << endl;
       goto link1;
    }
    resi.putdata();

    cout << "Тип данных char:" << endl;
    frac<char> char1, char2, resc;
    char1.getdata(); char2.getdata();
link2:
    cout << "Выберите операцию (+, -, *, /): ";
    cin >> op;
    switch (op) {
    case'+': resc = char1 + char2; break;
    case'-': resc = char1 - char2; break;
    case'*': resc = char1 * char2; break;
    case'/': resc = char1 / char2; break;
    default: cout << "Неверный ввод операции!\nПовторите ввод" << endl;
        goto link2;
    }
    resc.putdata();

    cout << "Тип данных long:" << endl;
    frac<long> long1, long2, resl;
    long1.getdata(); long2.getdata();
link3:
    cout << "Выберите операцию (+, -, *, /): ";
    cin >> op;
    switch (op) {
    case'+': resl = long1 + long2; break;
    case'-': resl = long1 - long2; break;
    case'*': resl = long1 * long2; break;
    case'/': resl = long1 / long2; break;
    default: cout << "Неверный ввод операции!\nПовторите ввод" << endl;
        goto link3;
    }
    resl.putdata();

    return 0;
}
