/*Создайте класс name, включающий в себя данные из упражнения 4 (имя, отчество, фамилия и номер работника). Создайте методы для этого класса, 
осуществляющие файловый ввод/вывод данных указанного класса (с использованием ofstream и ifstream). Используйте форматирование данных 
(операторы << и >>). Функции чтения и записи должны быть независимыми: в них необходимо внести выражения для открытия соответствующего потока,
а также чтения и записи данных. Функция записи может просто добавлять данные в конец файла. Функции чтения потребуется некоторое условие выборки
конкретной записи. Можно вызывать ее с параметром, представляющим собой номер записи. Но как, даже зная, какую запись следует читать, функция
найдет ее? Использование seekg() тут не поможет, так как при форматированном вводе/выводе все записи имеют разные размеры (в зависимости от 
количества символов в строке и разрядности числа). Поэтому придется просто считывать записи подряд, пока не будет найдена нужная. В main() 
вставьте вызовы описанных выше методов, чтобы пользователь мог ввести данные с их последующей записью в файл. Затем программа должна выполнить 
чтение и продемонстрировать результаты этого чтения на экране. */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
class Name {
private:
    string name;
    string oname;
    string fname;
    unsigned long num;
public:
    void getdata() {
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите отчество: ";
        cin >> oname;
        cout << "Введите фамилию: ";
        cin >> fname;
        cout << "Введите номер работника: ";
        cin >> num;
    }
    void openf(const string& filename) const {
        ofstream outfile(filename, ios::app); 
        if (!outfile) {
            cerr << "Ошибка: невозможно открыть файл " << filename << "\n";
            return;
        }
        outfile << name << " " << oname << " " << fname << " " << num << "\n";
        outfile.close();
    }
    static void openfile(const string& f, unsigned long n) {
        ifstream infile(f);
        if (!infile) {
            cerr << "Ошибка: невозможно открыть файл " << f << "\n";
            return;
        }
        string line;
        unsigned long number = 0;
        while (getline(infile, line)) {
            ++number;
            if (number == n) {
                cout << "Запись №" << n << ": " << line << "\n";
                infile.close();
                return;
            }
        }
        cout << "Запись №" << n << " не найдена.\n";
        infile.close();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Name name;
    string filename = "workers.txt";
    char choice;
    do {
        name.getdata();
        name.openf(filename);
        cout << "Продолжить запись данных (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nЧтение конкретной записи:\n";
    unsigned long num1;
    do {
        cout << "Введите номер записи для чтения: ";
        cin >> num1;
        Name::openfile(filename, num1);
        cout << "Продолжить запись данных (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
