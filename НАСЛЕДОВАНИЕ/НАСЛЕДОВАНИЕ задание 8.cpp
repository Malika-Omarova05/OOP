/* В некоторых компьютерных языках, таких, как Visual Basic, есть операции, с помощью которых можно выделить часть строки и присвоить ее 
другой строке. (В стандартном классе string предложены различные под ходы.) Используя наследование, добавьте такую возможность в класс 
Pstring из упражнения 2. В новом производном классе Pstring2 разместите три новых функции:
left(), mid() и right(). 
s2.left(s1, n) // в строку s2 помещаются n самых левых, символов строки s1 
s2.mid(s1, s, n) // в строку s2 помещаются n символов из строки, начиная с символа номер s 
s2.right(s1, n)  // в строку s2 помещаются n самых правых, символов строки s1 
Вы можете использовать цикл for для копирования символ за символом подходящих частей строки s1 во временный объект класса Pstring2, кото- 
рый затем их возвратит. Для получения лучшего результата используйте в этих функциях возврат по ссылке, чтобы они могли быть использованы 
с левой стороны знака «равно» для изменения части существующей строки. */
#include <iostream>
#include <string>
using namespace std;
class Pstring : public string {
public:
    Pstring() : string() {}
    Pstring(const char* str) : string(str) {}
    Pstring(const string& str) : string(str) {}
};
class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {}
    Pstring2(const char* str) : Pstring(str) {}
    Pstring2(const string& str) : Pstring(str) {}
    Pstring2& left(const Pstring& s, size_t n) {
        this->assign(s.substr(0, n)); 
        return *this;
    }
    Pstring2& mid(const Pstring& s, size_t start, size_t n) {
        this->assign(s.substr(start, n)); 
        return *this;
    }
    Pstring2& right(const Pstring& s, size_t n) {
        if (n > s.length()) n = s.length();
        this->assign(s.substr(s.length() - n, n)); 
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Pstring s1("Пример строки"); 
    cout << "Строка: " << s1 << endl;
    Pstring2 s2; 
    s2.left(s1, 7);
    cout << "Левая часть строки: " << s2 << endl;
    s2.mid(s1, 8, 6); 
    cout << "Середина строки: " << s2 << endl;
    s2.right(s1, 6); 
    cout << "Правая часть строки: " << s2 << endl;
    return 0;
}
