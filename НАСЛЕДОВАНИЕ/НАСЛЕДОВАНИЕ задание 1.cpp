/*Представьте себе издательскую компанию, которая торгует книгами и аудио-записями этих книг. Создайте класс publication, в котором хранятся 
название (строка) и цена (типа float) книги. От этого класса наследуются еще два класса: book, который содержит информацию о количестве страниц 
в книге (типа int), и type, который содержит время записи книги в минутах (тип float). В каждом из этих трех классов должен быть метод getdata(), 
через который можно получать данные от пользователя с клавиатуры, и putdata(), предназначенный для вывода этих данных.Напишите функцию main()
программы для проверки классов book и type. Создайте их объекты в программе и запросите пользователя ввести и вывести данные с использованием 
методов getdata() и putdata().*/
#include <iostream> 
#include <string> 
#include <Windows.h>
using namespace std;
class publication {
private:
    string name;
    float price;
public:
    void getdata() {
        cout << "\nВведите заголовок: "; cin >> name;
        cout << "Введите цену: "; cin >> price;
    }
    void putdata()const {
        cout << "\nЗаголовок: " << name;
        cout << "\nЦена: " << price;
    }
};
class book :private publication {
private:
    int str;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите число страниц: "; cin >> str;
    }
    void putdata()const {
        publication::putdata();
        cout << "\nСтраниц: " << str;
    }
};
class tape :private publication {
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
    book b1, b2;
    tape t1, t2;
    cout << "Введите данные для первой книги:";
    b1.getdata();        
    t1.getdata();
    cout << "Введите данные для второй книги: ";
    b2.getdata();          
    t2.getdata();
    cout << endl;
    cout << "Данные первой книги:\n";
    b1.putdata();
    t1.putdata();
    cout << "\nДанные второй книги:\n";
    b2.putdata();
    t2.putdata();
    return 0;
}
