/*Напишите программу, возвращающую размер файла, указанного в команд- 
ной строке: C:\>filesize program.ext. */
#include <fstream>             
#include <iostream> 
#include <string>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream file("file.txt");
    if (!file) {
        cerr << "\nОшибка: невозможно создать файл file.txt";
        return -1;
    }
    cout << "Введите текст для записи в файл file.txt: ";
    string userInput;
    getline(cin, userInput);
    file << userInput;
    file.close();
    ifstream infile("file.txt", ios::binary);
    if (!infile) {
        cerr << "\nОшибка: невозможно открыть файл file.txt";
        return -1;
    }
    infile.seekg(0, ios::end); 
    cout << "\nРазмер файла file.txt: " << infile.tellg() << " байт\n";
    infile.close();
    return 0;
}
