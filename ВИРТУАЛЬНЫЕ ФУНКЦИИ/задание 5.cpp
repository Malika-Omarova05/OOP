/* Взяв за основу программу из упражнения 1 этой главы, добавьте метод типа bool, называющийся isOveersize(), к классам book и tape. Допустим, 
книга, в которой больше 800 страниц, или кассета со временем проигрывания более 90 минут, будут считаться объектами с превышением разме- 
ра. К этой функции можно обращаться из main(), а результат ее работы выводить в виде строки «Превышение размера!» для соответствующих 
книг и кассет. Допустим, объекты классов book и tape должны быть доступны через указатели на них, хранящиеся в массиве типа publication. 
Что в этом случае вам нужно добавить в базовый класс publication? Вы можете привести примеры компонентов этого базового класса?*/
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
    virtual void putdata() const {
        cout << "\nЗаголовок: " << name;
        cout << "\nЦена: " << price;
    }
    virtual bool isOversize() const = 0;
};

class book : public publication {
private:
    int str;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите число страниц: "; cin >> str;
    }
    void putdata() const override {
        publication::putdata();
        cout << "\nСтраниц: " << str;
        if (isOversize()) {
            cout << " Превышение размера!";
        }
    }
    bool isOversize() const override {
        return str > 800;
    }
};

class tape : public publication {
private:
    float min;
public:
    void getdata() override {
        publication::getdata();
        cout << "Введите время звучания: "; cin >> min;
    }
    void putdata() const override {
        publication::putdata();
        cout << "\nВремя звучания: " << min << " минут";
        if (isOversize()) {
            cout << " Превышение размера!";
        }
    }
    bool isOversize() const override {
        return min > 90;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    publication* arr[2]; 
    book b1;
    tape t1;

    cout << "Введите данные для книги:" << endl;
    arr[0] = &b1;
    arr[0]->getdata();

    cout << "Введите данные для кассеты:" << endl;
    arr[1] = &t1;
    arr[1]->getdata();

    cout << "\nДанные:" << endl;
    for (int i = 0; i < 2; ++i) {
        arr[i]->putdata();
        cout << endl;
    }

    return 0;
}
