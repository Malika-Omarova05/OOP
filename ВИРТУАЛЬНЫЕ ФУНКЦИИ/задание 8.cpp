/* Помните программу PARSE из главы 10? Попробуйте доработать ее, чтобы она могла вычислять значения математических выражений с рациональны- 
ми числами, например типа float, а не только с одноразрядными числами: 3.14159 / 2.0 + 75.25 * 3.333 + 6.02 
Во-первых, нужно развить стек до такой степени, чтобы он мог хранить и операторы (типа char), и числа (типа float). Но как, спрашивается, можно 
хранить в стеке значения двух разных типов? Ведь стек — это, по сути дела, массив. Надо еще учесть, что типы char и float даже не совпадают по 
размеру! Даже указатели на разные типы данных (char* и float*) компилятор не позволит хранить в одном массиве, несмотря на то, что они одина- 
кового размера. Единственный способ хранить в массиве два разных типа указателей — сделать эти типы наследниками одного и того же базового 
класса. При этом базовому классу даже нет нужды иметь какие-то собственные данные, это может быть абстрактный класс, из которого никакие 
объекты создаваться не будут. Конструкторы могут хранить значения в порожденных классах обычным способом, но должна иметься специальная чистая 
виртуальная функция для того, чтобы извлечь эти значения. Представляем возможный сценарий работы над этим вопросом: 
  class Token                       // Абстрактный базовый класс 
    { 
    public: 
      virtual float getNumber()= 0; // чистая виртуальная 
                                    // функция 
      virtual char getOperator()= 0; 
    }; 
  class Operator : public Token 
    { 
    private: 
      char oper;             // Операторы +, -, *, / 
    public: 
      Operator(char);        // конструктор устанавливает значение 
      char getOperator();    // получить значение 
      float getNumber();     // просто некая функция 
    }; 
  class Number : public Token 
    { 
    private: 
      float fnum;            // число 
    public: 
      Number(float);         // конструктор устанавливает значение 
      float getNumber();     // получить значение 
      char getOperator();    // просто некая функция 
    }; 
  Token* atoken[100];        // содержит типы Operator* и Number* 
 
Виртуальные функции базового класса должны быть реализованы во всех порожденных классах, в противном случае классы становятся абстрактными. Таким 
образом, классу Operand нужна функция getNumber(), несмотря на то, что она фиктивная. Классу Number нужна функция getOperand(), несмотря на то, 
что она тоже фиктивная. Поработайте над этим каркасом, сделайте его реально работающей программой, добавив класс Stack, содержащий объекты класса 
Token, и функцию main(), в которой бы заносились в стек и извлекались из него разные арифметические операторы и числа в формате с плавающей запятой. */
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>
using namespace std;

class Token {
public:
    virtual float getNumber() = 0; 
    virtual char getOperator() = 0; 
    virtual ~Token() {} 
};
class Operator : public Token {
private:
    char oper;
public:
    Operator(char op) : oper(op) {}
    char getOperator() override {
        return oper;
    }
    float getNumber() override {
        throw logic_error("Невозможно получить число из оператора!");
    }
};
class Number : public Token {
private:
    float fnum; 
public:
    Number(float num) : fnum(num) {}
    float getNumber() override {
        return fnum;
    }
    char getOperator() override {
        throw logic_error("Невозможно получить оператор из числа!");
    }
};
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

int main() {
    setlocale(LC_ALL, "rus");

    string expression;
    cout << "Введите выражение (например, 3.14159 / 2.0 + 75.25 * 3.333 + 6.02): ";
    getline(cin, expression);

    stack<Token*> tokens; 
    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue; 

        if (isdigit(expression[i]) || expression[i] == '.') { 
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--; 
            float num = stof(numStr);
            tokens.push(new Number(num)); 
        }
        else if (string("+-*/").find(expression[i]) != string::npos) { 
            tokens.push(new Operator(expression[i]));
        }
        else {
            throw runtime_error("Неверный символ в выражении!");
        }
    }
    stack<float> values; 
    stack<char> operators;
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
        delete token; 
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
