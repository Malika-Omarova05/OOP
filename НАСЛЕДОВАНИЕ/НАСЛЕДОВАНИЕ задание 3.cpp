/*Начните с классов book, type и publication из упражнения 1. Добавьте базовый класс sales, в котором содержится массив, состоящий из трех значе- 
ний типа float, куда можно записать общую стоимость проданных книг за последние три месяца. Включите в класс методы getdata() для получения 
значений стоимости от пользователя и putdata() для вывода этих цифр. Измените классы book и type так, чтобы они стали производными обоих 
классов: publications и sales. Объекты классов book и type должны вводить и выводить данные о продажах вместе с другими своими данными. Напи- 
шите функцию main() для создания объектов классов book и type, чтобы протестировать возможности ввода/вывода данных.*/
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
class sales {
private :
    enum { month = 3 };
    float saless[month];
public:
    void getdata() {
        cout << "Введите кол-во продаж: " << endl;
        for (int i = 0; i < month; i++) {
            cout << "За " << 1 + i << "-й месяц продано: ";
            cin >> saless[i];
        }
    }
    void putdata() const{
        cout << "\nПродано:\n";
        for (int i = 0; i < month; i++)
            cout << "За " << 1 + i << "-й месяц продано: " << saless[i] << endl;
    }
};
class book :private publication, private sales {
private:
    int str;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите число страниц: "; cin >> str;
        sales::getdata();
    }
    void putdata()const {
        publication::putdata();
        cout << "\nСтраниц: " << str;
        sales::putdata();
    }
};
class tape :private publication, private sales {
private:
    float min;
public:
    void getdata() {
        cout << "Введите время звучания: "; cin >> min;
    }
    void putdata()const {
        cout << "Время звучания: " << min << " минут";
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
    cout << "\nВведите данные для второй книги:";
    b2.getdata();
    t2.getdata();
    cout << "\nДанные первой книги: ";
    b1.putdata();
    t1.putdata();
    cout << "\n\nДанные второй книги: ";
    b2.putdata();
    t2.putdata();
    cout << endl;
    return 0;
}
