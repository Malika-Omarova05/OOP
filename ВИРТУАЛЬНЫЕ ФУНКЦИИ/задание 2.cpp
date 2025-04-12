/* Напишите main(), где создавался бы массив указателей на класс publication. 
Это очень похоже на то, что мы делали в текущей главе на примере 
VIRTPERS. В цикле запрашивайте у пользователя данные о конкретной кни- 
ге или кассете, используйте new для создания нового объекта book или 
tape. Сопоставляйте указатель в массиве с объектом. Когда пользователь 
закончит ввод исходных данных, выведите результат для всех введенных 
книг и кассет, используя цикл for и единственное выражение 
pubarr[j]->putdata(); для вывода данных о каждом объекте из массива */
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class publication {
protected:
    string name;
    float price;
public:
    virtual void getdata() {
        cout << "\nВведите заголовок: "; cin >> name;
        cout << "Введите цену: "; cin >> price;
    }
    virtual void putdata() const {
        cout << "\nЗаголовок: " << name;
        cout << "\nЦена: " << price;
    }
    virtual ~publication() {}
};

class book : public publication {
private:
    int pages;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите число страниц: "; cin >> pages;
    }
    void putdata() const override {
        publication::putdata();
        cout << "\nСтраниц: " << pages;
    }
};

class tape : public publication {
private:
    float duration;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите время звучания (в минутах): "; cin >> duration;
    }
    void putdata() const override {
        publication::putdata();
        cout << "\nВремя звучания: " << duration << " минут";
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    const int SIZE = 10; 
    publication* pubarr[SIZE]; 
    int n = 0; 
    char choice;
    do {
        cout << "\nДобавить книгу (b) или кассету (t)? (q для выхода): ";
        cin >> choice;
        switch (choice) {
        case 'b': pubarr[n] = new book; break;
        case 't': pubarr[n] = new tape; break;
        case 'q':cout << "Некорректный ввод! Попробуйте снова."; continue;
        }
        pubarr[n]->getdata();
        n++;
    } while (n < SIZE);

    cout << "\nВведенные данные:\n";
    for (int j = 0; j < n; j++) {
        pubarr[j]->putdata();
        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        delete pubarr[j]; 
    }

    return 0;
}
