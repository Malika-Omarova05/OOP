/*В различных ситуациях иногда требуется работать с двумя числами, объединенными в блок. Например, каждая из координат экрана имеет гори- 
зонтальную составляющую (x) и вертикальную (y). Представьте такой блок чисел в качестве структуры pair, которая содержит две переменные типа int. 
Теперь предположим, что мы хотим иметь возможность хранить переменные типа pair в стеке. То есть мы хотим иметь возможность положить пе- 
ременную типа pair в стек путем вызова метода push() с переменной типа pair в качестве аргумента и вынуть ее из стека путем вызова метода pop(), 
возвращающего переменную типа pair. Начнем с класса Stack2 программы STAKEN из этой главы. Создадим производный от него класс pairStack. В нем 
будут содержаться два метода: перегружаемый метод push() и перегружаемый метод pop(). Метод pairStack::push() должен будет сделать два вы- 
зова метода Stack2::push(), чтобы сохранить оба числа из пары, а метод pairStack::pop() должен будет сделать два вызова метода Stack2::pop().*/
#include <iostream>
using namespace std;
class Stack2 {
private:
    static const int SIZE = 100; 
    int st[SIZE];               
    int top;          
public:
    Stack2() : top(-1) {}   
    void push(int var) { 
        if (top >= SIZE - 1) {
            cout << "Стек переполнен!" << endl;
            return;
        }
        st[++top] = var;
    }
    int pop() {                  
        if (top < 0) {
            cout << "Стек пуст!" << endl;
            return 0;
        }
        return st[top--];
    }
    bool empty() const {      
        return (top == -1);
    }
};
struct Pair {
    int x;
    int y;
};
class pairStack : public Stack2 {
public:
    void push(const Pair& p) {   
        Stack2::push(p.x);      
        Stack2::push(p.y);   
    }
    Pair pop() {                 
        Pair p;
        p.y = Stack2::pop();     
        p.x = Stack2::pop();  
        return p;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    pairStack ps;      
    ps.push({ 10, 20 });
    ps.push({ 30, 40 });
    ps.push({ 50, 60 });
    while (!ps.empty()) {
        Pair p = ps.pop();
        cout << "Извлечена пара: (" << p.x << ", " << p.y << ")" << endl;
    }
    return 0;
}
