/*Создайте класс bMoney. Он должен хранить денежные значения как long double. Используйте метод mstold() для преобразования денежной строки, 
введенной пользователем, в long double, и метод ldtoms() для преобразования числа типа long double  в денежную строку для вывода (см. упражне- 
ния 6 и 10). Вы можете вызывать для ввода и вывода методы getmoney()  и putmoney(). Напишите другой метод класса для сложения двух объектов
типа bMoney и назовите его madd(). Сложение этих объектов легко произвести: просто сложите переменную типа long double  одного объекта с та-
кой же переменной другого объекта. Напишите функцию main(), которая просит пользователя несколько раз ввести денежную строку, а затем вы-
водит сумму значений этих строк. Вот как может выглядеть определение класса.*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib> 
using namespace std;

class bMoney {
private:
    long double money;
public:
    bMoney() : money(0.0) {}
    bMoney(char s[]) {
        money = mstold(s);
    }

    void madd(bMoney m1, bMoney m2) {
        money = m1.money + m2.money;
    }

    void getmoney() {
        char s[50];
        cout << "Введите денежное значение (например, $1,234,567,890.123): ";
        cin >> s;
        money = mstold(s);
    }

    void putmoney() {
        cout << "Денежная строка: " << ldtoms(money) << endl;
    }

    long double mstold(const char* moneyStr) {
        char str[50];
        int j = 0;
        for (int i = 0; moneyStr[i] != '\0'; i++) {
            if ((moneyStr[i] >= '0' && moneyStr[i] <= '9') || moneyStr[i] == '.') {
                str[j++] = moneyStr[i];
            }
        }
        str[j] = '\0';
        return strtold(str, nullptr);
    }

    string ldtoms(long double value) {
        if (value > 9999999999999990.00) {
            return "Заданное число слишком большое!";
        }

        ostringstream out;
        out << fixed << setprecision(2) << value;
        string a = out.str();

        string result = "$";
        bool nul = true;
        int count = 0;

        for (size_t i = 0; i < a.length(); ++i) {
            if (a[i] == '.') {
                nul = false;
            }
            if (nul && a[i] == '0') {
                continue;
            }
            nul = false;
            result += a[i];
            if (i < a.find('.') && !nul) {
                count++;
                if (count == 3 && i < a.find('.') - 1) {
                    result += ',';
                    count = 0;
                }
            }
        }

        return result + '\0';
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    bMoney m1, m2, m3;
    m1.getmoney();
    m2.getmoney();

    m3.madd(m1, m2);

    cout << "Сумма значений: \n";
    m3.putmoney();

    return 0;
}
