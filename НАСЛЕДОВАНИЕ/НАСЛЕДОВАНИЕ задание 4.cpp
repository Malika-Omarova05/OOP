/*Предположим, что издатель из упражнений 1 и 3 решил добавить к своей продукции версии книг на компьютерных дисках для тех, кто любит чи- 
тать книги на своих компьютерах. Добавьте класс disk, который, как book и type, является производным класса publication. Класс disk должен вклю- 
чать в себя те же функции, что и в других классах. Полем только этого класса будет тип диска: CD или DVD. Для хранения этих данных вы мо- 
жете ввести тип enum. Пользователь должен выбрать подходящий тип, набрав на клавиаtype с или d. */
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
private:
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
    void putdata() const {
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
class tape :private publication, private sales, private book {
private:
    float min;
public:
    void getdata() {
        book::getdata();
        cout << "Введите время звучания: "; cin >> min;
    }
    void putdata()const {
        book::putdata();
        cout << "Время звучания: " << min << " минут";
    }
};
class disk :private publication, private sales, private tape {
private:
    enum{c, d};
    char x;
public:
    void getdata() {
        tape::getdata();
        cout << "Введите тип диска (с - cd, d - dvd): ";
        cin >> x;
    }
    void putdata() const {
        tape::putdata();
        cout << "\nТип диска:";
        if (x == c) cout << "cd" << endl;
        else cout << "dvd" << endl;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    disk d1, d2;
    cout << "Введите данные для первой книги:";
    d1.getdata();
    cout << "\nВведите данные для второй книги:";
    d2.getdata();
    cout << "\nДанные первой книги: ";
    d1.putdata();
    cout << "\n\nДанные второй книги: ";
    d2.putdata();
    cout << endl;
    return 0;
}
