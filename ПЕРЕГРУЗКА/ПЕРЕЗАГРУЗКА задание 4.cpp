/*Создайте класс Int, основанный на упражнении 1 из главы 6. Перегрузите четыре целочисленных арифметических операции (+, -, * и /) так, чтобы 
их можно было использовать для операций с объектами класса Int. Если результат какой-либо из операций выходит за границы типа int (в 32- 
битной системе), имеющие значение от 2 14 7 483 648 до -2 147 483 648, то операция должна послать сообщение об ошибке и завершить про- 
грамму. Такие типы данных полезны там, где ошибки могут быть вызваны арифметическим переполнением, которое недопустимо. Подсказка: для 
облегчения проверки переполнения выполняйте вычисления с использованием типа long double. Напишите программу для проверки этого класса. */
#include <iostream>
#include <stdexcept>
#include <climits> 
using namespace std;
class Int {
private:
    int val;
    void checkOverflow(long double result) const {
        if (result > INT_MAX || result < INT_MIN) {
            cerr << "Ошибка: переполнение!" << endl;
            exit(EXIT_FAILURE);
        }
    }
public:
    Int() : val(0) {}
    Int(int x) : val(x) {}
    Int operator+(const Int& other) const {
        long double result = static_cast<long double>(val) + other.val;
        checkOverflow(result);
        return Int(static_cast<int>(result));
    }
    Int operator-(const Int& other) const {
        long double result = static_cast<long double>(val) - other.val;
        checkOverflow(result);
        return Int(static_cast<int>(result));
    }
    Int operator*(const Int& other) const {
        long double result = static_cast<long double>(val) * other.val;
        checkOverflow(result);
        return Int(static_cast<int>(result));
    }
    Int operator/(const Int& other) const {
        if (other.val == 0) {
            cerr << "Ошибка: деление на ноль!" << endl;
            exit(EXIT_FAILURE);
        }
        long double result = static_cast<long double>(val) / other.val;
        checkOverflow(result);
        return Int(result);
    }
    void print() const {
        cout << val << endl;
    }
    void getdata() {
        cout << "Введите число: "; cin >> val;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Int num1, num2; 
    Int result;
    num1.getdata(); num2.getdata();
    try {
        result = num1 + num2;
        cout << "Результат сложения: ";
        result.print();
        result = num1 - num2;
        cout << "Результат вычитания: ";
        result.print();
        result = num1 * num2;
        cout << "Результат умножения: ";
        result.print();
        result = num1 / num2;
        cout << "Результат деления: ";
        result.print();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
