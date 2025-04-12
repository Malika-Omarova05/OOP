/* Пусть имеется та же издательская компания, которая описана в упражне- 
нии 1 главы 9, которая продает и книги, и аудио версии печатной продук- 
ции. Как и в том упражнении, создайте класс publication, хранящий название 
(фактически, строку) и цену (типа float) публикации. Создайте два порож- 
денных класса: book, в котором происходит изменение счетчика страниц (ти- 
па int), и tape, в котором происходит изменение счетчика записанных на 
кассету минут. Каждый из классов должен иметь метод getdata(), запраши- 
вающий информацию у пользователя, и putdata() для вывода данных на экран. */
#include <iostream> 
#include <string> 
#include <Windows.h>
using namespace std;
class publication {
private:
    string name;
    float price;
public:
    virtual void getdata() {
        cout << "\nВведите заголовок: "; cin >> name;
        cout << "Введите цену: "; cin >> price;
    }
    virtual void putdata()const {
        cout << "\nЗаголовок: " << name;
        cout << "\nЦена: " << price;
    }
};
class book :public publication {
private:
    int str;
public:
    void getdata() {
        cout << "Введите число страниц: "; cin >> str;
    }
    void putdata()const {
        cout << "\nСтраниц: " << str;
    }
};
class tape :public publication {
private:
    float min;
public:
    void getdata() {
        cout << "Введите время звучания: "; cin >> min;
    }
    void putdata()const {
        cout << "\nВремя звучания: " << min << " минут";
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    publication p,* ptr1, *ptr2;
    book b1;
    tape t1;
    cout << "Введите данные для первой книги:";
    p.getdata();
    ptr1 = &b1;
    ptr1->getdata();
    ptr2 = &t1;
    ptr2->getdata();
    cout << "Данные первой книги:\n";
    p.putdata();
    ptr1->putdata();
    ptr2->putdata();
    return 0;
}