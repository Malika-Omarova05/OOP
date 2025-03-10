/* Помните структуру sterling? Мы встречались с ней в упражнении 10 главы 2 «Основы программирования на C++», в упражнении 11 главы 5 и 
 в других местах. Преобразуйте ее в класс, имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int). Создайте в
классе следующие функции:
♦ конструктор без аргументов;
♦ конструктор с одним аргументом типа double  (для преобразования от
десятичных фунтов);
♦ конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
♦ метод getSterling() для получения от пользователя значений количества
фунтов, шиллингов и пенсов в формате £9.19.11;
♦ метод putSterling() для вывода значений количества фунтов, шиллин-
гов и пенсов в формате £9.19.11;
♦ метод для сложения (sterling + sterling), используя перегруженную операцию +;
♦ метод вычитания (sterling - sterling), используя перегруженную операцию -;
♦ метод умножения (sterling * double), используя перегруженную операцию *;
♦ метод деления (sterling / sterling), используя перегруженную операцию /;
♦ метод деления (sterling / double), используя перегруженную операцию /;
♦ операцию double  (для преобразования к типу double)
Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, затем шиллинги и т. д. Однако легче
использовать операцию преобразования для преобразования объекта класса sterling к типу double, выполнить вычисления с типами double, а затем
преобразовать обратно к типу sterling. Таким образом, операция + выглядит похожей на эту:
sterling sterling::operator+(sterling s2){ return sterling(double(sterling(pounds, shillings, pense)) + double(s2));}
Так мы создадим две временных переменных типа double, одна происходит от объекта, который вызывает функцию, а другая от аргумента s2.
Эти переменные затем складываются, результат преобразовывается к типу sterling и возвращается.Заметим, что мы использовали другой подход для 
класса sterling, нежели для класса bMoney. В классе sterling мы используем операции преобразования, таким образом отказавшись от возможности 
поиска неправильных операций, но получив простоту при записи перегружаемых математических операций.*/
#include <iostream>
#include <cmath> 
using namespace std;

class Sterling {
private:
    long pounds;    
    int shillings;  
    int pence;      
public:
    // Конструктор без аргументов
    Sterling() : pounds(0), shillings(0), pence(0) {}
    // Конструктор с одним аргументом (десятичные фунты)
    Sterling(double decimalPounds) {
        pounds = static_cast<long>(decimalPounds);
        double fractionalPart = (decimalPounds - pounds) * 20;
        shillings = static_cast<int>(fractionalPart);
        pence = static_cast<int>(round((fractionalPart - shillings) * 12)); 
    }
    // Конструктор с тремя аргументами
    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    void getdata() {
        char ch;
        cout << "Введите футы: "; cin >> pounds;
        cout << "Введите шиллинги: "; cin >> shillings;
        cout << "Введите пенсы: "; cin >> pence;
    }
    void putdata() const {
        cout << pounds << "." << shillings << "." << pence << endl;
    }
    Sterling operator+(const Sterling& s) const {
        return Sterling(double(*this) + double(s));
    }
    Sterling operator-(const Sterling& s) const {
        return Sterling(double(*this) - double(s));
    }
    Sterling operator*(double factor) const {
        return Sterling(double(*this) * factor);
    }
    double operator/(const Sterling& s) const {
        return double(*this) / double(s);
    }
    Sterling operator/(double divisor) const {
        if (divisor == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return Sterling(double(*this) / divisor);
    }
    explicit operator double() const {
        return pounds + (shillings / 20.0) + (pence / 240.0);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Sterling s1, s2, result;
    double factor;
    cout << "Введите первое значение: ";
    s1.getdata();
    cout << "Введите второе значение: ";
    s2.getdata();
    result = s1 + s2;
    cout << "Сложение: ";
    result.putdata();
    result = s1 - s2;
    cout << "Вычитание: ";
    result.putdata();
    cout << "Введите множитель: ";
    cin >> factor;
    result = s1 * factor;
    cout << "Умножение: ";
    result.putdata();
    cout << "Деление (Sterling / Sterling): " << (s1 / s2) << endl;
    cout << "Введите делитель: ";
    cin >> factor;
    result = s1 / factor;
    cout << "Деление: ";
    result.putdata();

    return 0;
}
