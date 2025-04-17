/*К программе EMPL_IO из этой главы добавьте возможность поиска работ- 
ника в списке, хранящемся в файле, по номеру. При нахождении совпа- 
дения нужно вывести данные об этом работнике на экран. Пользователь 
должен иметь возможность запустить функцию поиска нажатием клави- 
ши 'f'. У пользователя спрашивается номер работника. Подумайте над во- 
просом, какой должна быть эта функция — статической, виртуальной или 
какой-то еще? Поиск и вывод на экран не должны пересекаться с данны- 
ми в памяти.*/
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;
const int LEN = 32;
const int MAXEM = 100; 
enum employee_type { tmanager, tscientist, tlaborer };
class employee {
private:
    char name[LEN];
    unsigned long number; 
    static int n; 
    static employee* arrap[MAXEM]; 
public:
    virtual void getdata() {
        cin.ignore(10, '\n');
        cout << "Введите фамилию: ";
        cin >> name;
        cout << "Введите номер: ";
        cin >> number;
    }
    virtual void putdata() const {
        cout << "\nФамилия: " << name;
        cout << "\nНомер: " << number;
    }
    virtual employee_type get_type() = 0; 
    static void add();
    static void display();
    static void write();
    static void read();
    static void search(); 
};
int employee::n = 0;
employee* employee::arrap[MAXEM];
class manager : public employee {
private:
    char title[LEN];
    double dues;
public:
    void getdata() override {
        employee::getdata();
        cout << "Введите титул: ";
        cin >> title;
        cout << "Введите налоги: ";
        cin >> dues;
    }
    void putdata() const override {
        employee::putdata();
        cout << "\nТитул: " << title;
        cout << "\nНалоги гольф-клуба: " << dues;
    }
    employee_type get_type() override {
        return tmanager;
    }
};
class scientist : public employee {
private:
    int pubs;
public:
    void getdata() override {
        employee::getdata();
        cout << "Введите число публикаций: ";
        cin >> pubs;
    }
    void putdata() const override {
        employee::putdata();
        cout << "\nЧисло публикаций: " << pubs;
    }
    employee_type get_type() override {
        return tscientist;
    }
};
class laborer : public employee {
public:
    employee_type get_type() override {
        return tlaborer;
    }
};
void employee::add() {
    char ch;
    cout << "'m' для добавления менеджера\n"
        << "'s' для добавления ученого\n"
        << "'l' для добавления рабочего\n"
        << "Ваш выбор: ";
    cin >> ch;
    switch (ch) {
    case 'm': arrap[n] = new manager; break;
    case 's': arrap[n] = new scientist; break;
    case 'l': arrap[n] = new laborer; break;
    default:
        cout << "Неизвестный тип работника!\n";
        return;
    }
    arrap[n++]->getdata();
}
void employee::display() {
    for (int j = 0; j < n; j++) {
        cout << (j + 1) << ". ";
        switch (arrap[j]->get_type()) {
        case tmanager: cout << "Менеджер"; break;
        case tscientist: cout << "Ученый"; break;
        case tlaborer: cout << "Рабочий"; break;
        }
        arrap[j]->putdata();
        cout << endl;
    }
}

void employee::write() {
    ofstream ouf("EMPLOY.DAT", ios::binary | ios::trunc);
    if (!ouf) {
        cout << "Ошибка открытия файла для записи!";
        return;
    }
    for (int j = 0; j < n; j++) {
        employee_type etype = arrap[j]->get_type();
        ouf.write((char*)&etype, sizeof(etype));
        switch (etype) {
        case tmanager: ouf.write((char*)arrap[j], sizeof(manager)); break;
        case tscientist: ouf.write((char*)arrap[j], sizeof(scientist)); break;
        case tlaborer: ouf.write((char*)arrap[j], sizeof(laborer)); break;
        }
    }
    cout << "Данные записаны в файл.\n";
}
void employee::read() {
    ifstream inf("EMPLOY.DAT", ios::binary);
    if (!inf) {
        cout << "Ошибка открытия файла для чтения!";
        return;
    }
    n = 0; 
    while (true) {
        employee_type etype;
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof()) break;
        switch (etype) {
        case tmanager: arrap[n] = new manager; break;
        case tscientist: arrap[n] = new scientist; break;
        case tlaborer: arrap[n] = new laborer; break;
        default:
            cout << "Неизвестный тип в файле!";
            return;
        }
        inf.read((char*)arrap[n], sizeof(*arrap[n]));
        if (!inf) {
            cout << "Ошибка чтения данных!";
            return;
        }
        n++;
    }
    cout << "Данные прочитаны из файла.\n";
}
void employee::search() {
    unsigned long search_number;
    cout << "Введите номер работника для поиска: ";
    cin >> search_number;
    ifstream inf("EMPLOY.DAT", ios::binary);
    if (!inf) {
        cout << "Ошибка открытия файла!";
        return;
    }
    while (true) {
        employee_type etype;
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof()) break;

        employee* emp = nullptr;
        switch (etype) {
        case tmanager: emp = new manager; break;
        case tscientist: emp = new scientist; break;
        case tlaborer: emp = new laborer; break;
        default:
            cout << "Неизвестный тип в файле!";
            return;
        }
        inf.read((char*)emp, sizeof(*emp));
        if (!inf) {
            cout << "Ошибка чтения данных!";
            delete emp;
            return;
        }
        if (emp->number == search_number) {
            cout << "Найден работник:\n";
            emp->putdata();
            delete emp;
            return;
        }
        delete emp;
    }

    cout << "Работник с указанным номером не найден.\n";
}
int main() {
    setlocale(LC_ALL, "rus");
    char ch;
    while (true) {
        cout << "'a' - Добавить работника\n";
        cout << "'d' - Вывести всех работников\n";
        cout << "'w' - Записать в файл\n";
        cout << "'r' - Прочитать из файла\n";
        cout << "'f' - Найти работника\n";
        cout << "'x' - Выход\n";
        cout << "Ваш выбор: ";
        cin >> ch;
        switch (ch) {
        case 'a': employee::add(); break;
        case 'd': employee::display(); break;
        case 'w': employee::write(); break;
        case 'r': employee::read(); break;
        case 'f': employee::search(); break;
        case 'x': return 0;
        default: cout << "Неизвестная команда!\n";
        }
    }
}
