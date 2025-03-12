/*В программе EMPMULT этой главы существует только один тип должно- 
сти менеджера. В любой серьезной компании кроме менеджеров сущест- 
вуют еще и управляющие. Создадим производный от класса manager класс 
executive. (Мы предполагаем, что управляющий — это главный менеджер.) 
Добавочными данными этого класса будут размер годовой премии и ко- 
личество его акций в компании. Добавьте подходящие методы для этих 
данных, позволяющие их вводить и выводить. */
#include <iostream>
#include <windows.h>
using namespace std;
const int LEN = 80;
class student {
private:
    char school[LEN];
    char degree[LEN];
public:
    void getedu() {
        cout << "  Введите название учебного заведения: ";
        cin >> school;
        cout << "  Введите степень высшего образования\n";
        cout << "  (неполное высшее, бакалавр, магистр, кандидат наук): ";
        cin >> degree;
    }
    void putedu() const {
        cout << "\n  Учебное заведение: " << school;
        cout << "\n  Степень: " << degree;
    }
};
class employee {
private:
    char name[LEN];
    unsigned long number;
public:
    void getdata() {
        cout << "\n  Введите фамилию: ";
        cin >> name;
        cout << "  Введите номер: ";
        cin >> number;
    }
    void putdata() const {
        cout << "\n  Фамилия: " << name;
        cout << "\n  Номер: " << number;
    }
};
class manager : private employee, private student {
private:
    char title[LEN];
    double dues;
public:
    void getdata() {
        employee::getdata();
        cout << "  Введите должность: ";
        cin >> title;
        cout << "  Введите сумму взносов в гольф-клуб: ";
        cin >> dues;
        student::getedu();
    }
    void putdata() const {
        employee::putdata();
        cout << "\n  Должность: " << title;
        cout << "\n  Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};
class executive : public manager {
private:
    double bonus; 
    int ak;  
public:
    void getdata() {
        manager::getdata();
        cout << "  Введите годовую премию: ";
        cin >> bonus;
        cout << "  Введите количество акций: ";
        cin >> ak;
    }
    void putdata() const {
        manager::putdata();
        cout << "\n  Годовая премия: " << bonus;
        cout << "\n  Количество акций: " << ak;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    executive e1;
    cout << "\nВвод информации об управляющем";
    e1.getdata();
    cout << "\nИнформация об управляющем";
    e1.putdata();
    cout << endl;
    return 0;
}
