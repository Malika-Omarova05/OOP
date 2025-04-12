/*Возьмите за основу программу из упражнения 8 главы 8, где было перегружено пять арифметических операций для работы с денежным форма- 
том. Добавьте два оператора, которые не были перегружены в том упражнении: 
long double  * bMoney // умножать число на деньги 
long double  / bMoney // делить число на деньги 
Эти операции требуют наличия дружественных функций, так как справа от оператора находится объект, а слева — обычное число. Убедитесь, что 
main() позволяет пользователю ввести две денежные строки и число с плавающей запятой, а затем корректно выполня*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
using namespace std;

class bMoney {
private:
    long double money; 
public:
    bMoney() : money(0.0) {}
    explicit bMoney(const char* s) {
        money = mstold(s);
    }
    explicit bMoney(long double val) : money(val) {}

    void getmoney() {
        char s[50];
        cout << "Введите денежное значение (например, $1,234,567,890.123): ";
        cin >> s;
        money = mstold(s);
    }

    void putmoney() const {
        cout << "Денежная строка: " << ldtoms(money) << endl;
    }

    bMoney operator+(const bMoney& m) const {
        return bMoney(money + m.money);
    }

    bMoney operator-(const bMoney& m) const {
        return bMoney(money - m.money);
    }

    bMoney operator*(long double val) const {
        return bMoney(money * val);
    }

    long double operator/(const bMoney& m) const {
        if (m.money == 0.0) throw runtime_error("Ошибка: деление на ноль!");
        return money / m.money;
    }

    bMoney operator/(long double val) const {
        if (val == 0.0) throw runtime_error("Ошибка: деление на ноль!");
        return bMoney(money / val);
    }

    explicit operator long double() const {
        return money;
    }
    friend bMoney operator*(long double val, const bMoney& m) {
        return bMoney(val * m.money);
    }
    friend long double operator/(long double val, const bMoney& m) {
        if (m.money == 0.0) throw runtime_error("Ошибка: деление на ноль!");
        return val / m.money;
    }
    friend bMoney operator+(long double val, const bMoney& m) {
        return bMoney(val + m.money);
    }
    friend bMoney operator-(long double val, const bMoney& m) {
        return bMoney(val - m.money);
    }

private:
    long double mstold(const char* moneyStr) const {
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

    string ldtoms(long double value) const {
        ostringstream out;
        out << fixed << setprecision(2) << value;
        string a = out.str();

        string result = "$";
        int count = 0;
        for (size_t i = 0; i < a.length(); i++) {
            if (a[i] == '.') break;
            if (count && (a.length() - i) % 3 == 0) {
                result += ',';
            }
            result += a[i];
        }
        result += a.substr(a.find('.'));
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    bMoney m1, m2, result;
    long double val;

    cout << "\nВведите первое значение bMoney:\n";
    m1.getmoney();
    cout << "Введите второе значение bMoney:\n";
    m2.getmoney();
    cout << "Введите число с плавающей точкой: ";
    cin >> val;

    result = m1 + m2;
    cout << "\nСложение bMoney + bMoney: ";
    result.putmoney();

    result = m1 - m2;
    cout << "Вычитание bMoney - bMoney: ";
    result.putmoney();

    result = m1 * val;
    cout << "Умножение bMoney * long double: ";
    result.putmoney();

    long double divResult = m1 / m2;
    cout << "Деление bMoney / bMoney: " << divResult << endl;

    result = m1 / val;
    cout << "Деление bMoney / long double: ";
    result.putmoney();

    result = val * m1;
    cout << "\nУмножение long double * bMoney: ";
    result.putmoney();

    divResult = val / m1;
    cout << "Деление long double / bMoney: " << divResult << endl;

    result = val + m1;
    cout << "Сложение long double + bMoney: ";
    result.putmoney();

    result = val - m1;
    cout << "Вычитание long double - bMoney: ";
    result.putmoney();

    return 0;
}
