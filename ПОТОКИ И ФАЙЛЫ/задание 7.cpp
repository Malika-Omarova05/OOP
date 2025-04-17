/*Другим подходом к добавлению файлового потока к объекту является превращение самого этого потока в статическую компоненту объекта. Для 
чего это делается? Ну, часто бывает проще представить себе поток связанным с классом в целом, а не с отдельными его объектами. К тому же, 
гораздо правильнее открывать поток только один раз для записи и чтения всего, что нужно. Например, мы открываем файл и начинаем последова- 
тельное чтение. Функция чтения всякий раз возвращает данные для следующего объекта. Указатель файла сдвигается при этом автоматически, так 
как между чтениями файл мы не закрываем. Перепишите программы из упражнений 4 и 6 таким образом, чтобы использовать объект fstream в качестве 
статической компоненты класса name. Функционирование программы должно сохраниться. Напишите статическую функцию для открытия потока и еще 
одну — для сбрасывания файлового указателя и установки его на начало файла. Эту же функцию можно использовать для чтения всего файла. */
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
class Name {
private:
    string name;
    string oname;
    string fname;
    unsigned long num;
public:
    static fstream file; 
    void input() {
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите отчество: ";
        cin >> oname;
        cout << "Введите фамилию: ";
        cin >> fname;
        cout << "Введите номер работника: ";
        cin >> num;
    }
    void zapis() const {
        file << name << " " << oname << " " << fname << " " << num << "\n";
    }
    void putdata() const {
        cout << name << " " << oname << " " << fname << " " << num << "\n";
    }
    static void open_file(const string& filename, ios::openmode mode) {
        file.open(filename, mode);
        if (!file) {
            cerr << "Ошибка: невозможно открыть файл " << filename << "\n";
            exit(-1);
        }
    }
    static void reset_file() {
        file.clear();
        file.seekg(0, ios::beg);
    }
    static void cten() {
        reset_file();
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
    }
    static void close() {
        file.close();
    }
};
fstream Name::file;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "workers.txt";
    Name::open_file(filename, ios::in | ios::out | ios::app);
    char choice;
    do {
        Name name;
        name.input();
        name.zapis();
        cout << "Продолжить запись данных (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "\nЧтение всех записей:\n";
    Name::cten();
    Name::close();
    return 0;
}
