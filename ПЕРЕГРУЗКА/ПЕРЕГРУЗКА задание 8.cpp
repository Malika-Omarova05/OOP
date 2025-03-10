/*Модифицируйте класс bMoney из упражнения 12 главы 7 «Массивы и строки», включив арифметические операции, выполненные с помощью пере- 
груженных операций: bMoney = bMoney + bMoney bMoney = bMoney - bMoney bМоnеу = bMoney * long double  (цена за единицу времени, затраченного на изделие) 
long double = bMoney / bMoney (общая цена, деленная на цену за изделие) bMoney = bMoney / long double (общая цена, деленная на количество изделий) 
Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их аргументы разные. Помним, что легче выполнять 
арифметические операции с объектами класса bMoney, выполняя те же операции с его long double  данными.Убедитесь, что программа main() запросит ввод 
пользователем двух денежных строк и числа с плавающей точкой. Затем она выполнит все пять операций и выведет результаты. Это должно происходить в цикле, 
так, чтобы пользователь мог ввести еще числа, если это понадобится. Некоторые операции с деньгами не имеют смысла: bMoney*bMoney не представляет ничего 
реального, так как нет такой вещи, как денежный квадрат; вы не можете прибавить bMoney к long double  (что же будет, если рубли сложить с изделиями?). 
Чтобы сделать это невозможным, скомпилируйте такие неправильные операции, не включая операции преобразования для bMoney в long double  или long double  
в bMoney. Если вы это сделаете и запишете затем выражение типа: bmon2 = bmon1 + widgets; // это не имеет смысла то компилятор будет автоматически 
преобразовывать widgets в bMoney и выполнять сложение. Без них компилятор будет отмечать такие преобразования как ошибки, что позволит легче найти 
концептуальные ошибки. Также сделайте конструкторы преобразований явными. Вот некоторые другие вероятные операции с деньгами, которые мы еще 
не умеем выполнять с помощью перегруженных операций, так как они требуют объекта справа от знака операции, а не слева: 
long double  * bMoney // Пока не можем это сделать: bMoney возможен только справа 
long double  / bMoney // Пока не можем это сделать: bMoney возможен только справа 
Мы рассмотрим выход из этой ситуации при изучении дружественных функций в главе 11. */
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
    while (true) {
        cout << "\nВведите два значения bMoney и число с плавающей точкой:\n";
        m1.getmoney();
        m2.getmoney();
        cout << "Введите число с плавающей точкой: ";
        cin >> val;
        result = m1 + m2;
        cout << "Сложение: ";
        result.putmoney();
        result = m1 - m2;
        cout << "Вычитание: ";
        result.putmoney();
        result = m1 * val;
        cout << "Умножение: ";
        result.putmoney();
        cout << "Деление (bMoney / bMoney): " << (m1 / m2) << endl;
        result = m1 / val;
        cout << "Деление (bMoney / long double): ";
        result.putmoney();
        char choice;
        cout << "\nХотите продолжить? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
    }
    return 0;
}
