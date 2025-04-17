/*В цикле запрашивайте у пользователя данные, состоящие из имени, отчест- 
ва, фамилии и номера работника (типа unsigned long). Затем осуществите 
форматированный вывод в объект ofstream с помощью оператора вставки 
(<<). Не забывайте, что строки данных должны оканчиваться пробелами 
или другими разделителями. Когда пользователь сообщит об окончании 
ввода, закройте объект ofstream, откройте объект ifstream, прочитайте и вы- 
ведите на экран все данные из файла, после чего завершите программу. */
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outfile("workers.txt");
    if (!outfile) {
        cerr << "Ошибка: невозможно создать файл workers.txt";
        return -1;
    }
    cout << "Введите данные работника (Имя Отчество Фамилия Номер):\n";
    cout << "Для завершения ввода введите \"end\" вместо имени.\n";
    string name, oname, fname;
    unsigned long num;
    while (true) {
        cout << "Имя: ";
        cin >> name;
        if (name == "end") { 
            break;
        }
        cout << "Отчество: ";
        cin >> oname;
        cout << "Фамилия: ";
        cin >> fname;
        cout << "Номер работника: ";
        cin >> num;
        outfile << name << " " << oname << " " << fname << " " << num << "\n";
    }
    outfile.close(); 
    ifstream infile("workers.txt");
    if (!infile) {
        cerr << "Ошибка: невозможно открыть файл workers.txt";
        return -1;
    }
    cout << "\nСодержимое файла workers.txt:\n";
    string line;
    while (getline(infile, line)) {
        cout << line << "\n";
    }
    infile.close();
    return 0;
}
