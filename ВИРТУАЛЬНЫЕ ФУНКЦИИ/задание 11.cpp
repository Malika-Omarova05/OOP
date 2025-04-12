#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>
using namespace std;

// Базовый класс Token
class Token {
public:
    virtual float getNumber() = 0; // Чистая виртуальная функция
    virtual char getOperator() = 0; // Чистая виртуальная функция
    virtual ~Token() {} // Виртуальный деструктор
};

// Класс для операторов
class Operator : public Token {
private:
    char oper; // Оператор (+, -, *, /)
public:
    Operator(char op) : oper(op) {}
    char getOperator() override {
        return oper;
    }
    float getNumber() override {
        throw logic_error("Невозможно получить число из оператора!");
    }
};

// Класс для чисел
class Number : public Token {
private:
    float fnum; // Число
public:
    Number(float num) : fnum(num) {}
    float getNumber() override {
        return fnum;
    }
    char getOperator() override {
        throw logic_error("Невозможно получить оператор из числа!");
    }
};

// Функция для выполнения арифметической операции
float evaluate(float a, float b, char oper) {
    switch (oper) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0.0) throw runtime_error("Ошибка: деление на ноль!");
        return a / b;
    default:
        throw runtime_error("Неизвестный оператор!");
    }
}

// Основная программа
int main() {
    setlocale(LC_ALL, "rus");

    string expression;
    cout << "Введите выражение (например, 3.14 / 2.0 + 75.25 * 3.333 + 6.02): ";
    getline(cin, expression);

    stack<Token*> tokens; // Стек для токенов

    // Парсинг строки
    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue; // Пропуск пробелов

        if (isdigit(expression[i]) || expression[i] == '.') { // Обработка числа
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--; // Отступить назад, чтобы избежать перепрыгивания
            float num = stof(numStr);
            Number* ptrN = new Number(num);
            tokens.push(ptrN); // Добавить число в стек
        }
        else if (string("+-*/").find(expression[i]) != string::npos) { // Обработка оператора
            Operator* ptrO = new Operator(expression[i]);
            tokens.push(ptrO); // Добавить оператор в стек
        }
        else {
            throw runtime_error("Неверный символ в выражении!");
        }
    }

    // Вычисления
    stack<float> values; // Стек для чисел
    stack<char> operators; // Стек для операторов

    while (!tokens.empty()) {
        Token* token = tokens.top();
        tokens.pop();

        Number* numToken = dynamic_cast<Number*>(token);
        if (numToken) {
            values.push(numToken->getNumber());
        }
        else {
            Operator* opToken = dynamic_cast<Operator*>(token);
            if (opToken) {
                operators.push(opToken->getOperator());
            }
        }
        delete token; // Удаление динамически созданного объекта
    }

    while (!operators.empty()) {
        if (values.size() < 2) {
            throw runtime_error("Недостаточно операндов для операции!");
        }

        float b = values.top(); values.pop();
        float a = values.top(); values.pop();
        char op = operators.top(); operators.pop();

        float result = evaluate(a, b, op);
        values.push(result);
    }

    if (values.size() != 1) {
        throw runtime_error("Неверное выражение!");
    }

    cout << "Результат выражения: " << values.top() << endl;
    return 0;
}
