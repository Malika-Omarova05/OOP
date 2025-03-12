/*Рассмотрим старую Британскую платежную систему фунты-стерлинги пенсы (см. упражнение 10 главы 4 «Структуры»). Пенни в дальнейшем 
делятся на фартинги и полупенни. Фартинг — это 1/4 пенни. Существовали монеты фартинг, полфартинга и пенни. Любые сочетания монет вы- 
ражались через восьмые части пенни: 
1/8 пенни — это полфартинга; 
1/4 пенни — это фартинг; 
3/8 пенни — это фартинг с половиной; 
1/2 пенни — это по\пенни; 
5/8 пенни — это полфартинга плюс по\пенни; 
3/4 пенни — это по\пенни плюс фартинг; 
7/8 пенни — это по\пенни плюс фартинг с половиной. 
Давайте предположим, что мы хотим добавить в класс sterling возможность пользоваться этими дробными частями пенни. Формат ввода/выво- 
да может быть похожим на £1.1.1-1/4 или £9.19.11-7/8, где дефисы отделяют дробные части от пенни. Создайте новый класс sterfrac, 
производный от класса sterling. В нем должна быть возможность выполнения четырех основных арифметических операций со стерлингами, 
включая восьмые части пенни. Поле eighths типа int определяет количество восьмых. Вам нужно будет перегрузить методы класса sterling,
чтобы они могли работать с восьмыми частями. Пользователь должен иметь возможность ввести и вывести дробные части пенни.
Не обязательно использовать класс fraction полностью (см. упражнение 11 главы 6), по вы можете это сделать для большей точности.*/
#include <iostream>
using namespace std;

const int ep = 8;
const int ps = 12;
const int sp = 20;

class sterling {
protected:
    int pounds;
    int shillings;
    int pence;
public:
    sterling() : pounds(0), shillings(0), pence(0) {}
    sterling(int p, int s, int pn) : pounds(p), shillings(s), pence(pn) {}
    void display() const {
        cout << pounds << "." << shillings << "." << pence;
    }
};
class sterfrac : public sterling {
private:
    int eighths; 
public:
    sterfrac() : sterling(), eighths(0) {}
    sterfrac(int p, int s, int pn, int e) : sterling(p, s, pn), eighths(e) {}
    void input() {
        char dash;
        cout << "Фунты: "; cin >> pounds;
        cout << "Шиллинги: "; cin >> shillings;
        cout << "Пенни: "; cin >> pence;
    }
    void display() const {
        sterling::display();
        cout << "-" << eighths << "/" << ep;
    }
    long toEighths() const {
        return ((pounds * sp + shillings) * ps+ pence) * ep + eighths;
    }
    sterfrac operator+(const sterfrac& other) const {
        long a = this->toEighths() + other.toEighths();
        return a1(a);
    }

    sterfrac operator-(const sterfrac& other) const {
        long b = this->toEighths() - other.toEighths();
        return a1(b);
    }

    sterfrac operator*(int multiplier) const {
        long c = this->toEighths() * multiplier;
        return a1(c);
    }

    sterfrac operator/(int divisor) const {
        if (divisor == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return *this;
        }
        long d = this->toEighths() / divisor;
        return a1(d);
    }

    static sterfrac a1(long x) {
        int e = x % ep;
        x /= ep;
        int p = x % ps;
        x /= ps;
        int s = x % sp;
        int pn = x / sp;
        return sterfrac(pn, s, p, e);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    sterfrac sf1, sf2, result;
    cout << "Введите первую сумму: ";
    sf1.input();
    cout << "Введите вторую сумму: ";
    sf2.input();
    result = sf1 + sf2;
    cout << "Сумма: ";
    result.display();
    cout << endl;
    result = sf1 - sf2;
    cout << "Разность: ";
    result.display();
    cout << endl;
    result = sf1 * 2;
    cout << "Умножение на 2: ";
    result.display();
    cout << endl;
    result = sf1 / 2;
    cout << "Деление на 2: ";
    result.display();
    cout << endl;
    return 0;
}
