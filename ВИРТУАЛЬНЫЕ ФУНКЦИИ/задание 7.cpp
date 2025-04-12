/* Как и в предыдущем упражнении, возьмите за основу программу из упражнения 8 главы 8. На этот раз от вас требуется добавить функцию, округ- 
ляющую значение bMoney до ближайшего доллара: mo2 = round(mo1); Как известно, значения, не превышающие $0.49, округляются вниз, а чис- 
ла от $0.50 и более округляются вверх. Можно использовать библиотечную функцию modfl(). Она разбивает переменную типа long double  на це- 
лую и дробную части. Если дробная часть меньше 0.50, функция просто возвращает целую часть числа. В противном случае возвращается увели- 
ченная на 1 целая часть. В main() проверьте работоспособность функции путем передачи в нее последовательно значений, одни из которых меньше 
$0.49, другие - больше $0.50. */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <cmath> 
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
    bMoney round() const {
        long double intPart, fracPart;
        fracPart = modfl(money, &intPart); 
        if (fracPart >= 0.50) {
            intPart += 1.0; 
        }
        return bMoney(intPart);
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
    bMoney m1, okr;
    cout << "Введите значение bMoney:\n";
    m1.getmoney();
    okr = m1.round();
    cout << "\nОкругленное значение: ";
    okr.putmoney();

    return 0;
}
