/*Напишите программу, эмулирующую команду COPY (MS DOS). То есть 
программа должна копировать содержимое одного файла в другой. Долж- 
но использоваться два аргумента командной строки — исходный файл и 
файл назначения. Например: 
С:\>оcopy srcfile.cpp destfile.cpp 
Осуществляйте проверку числа аргументов командной строки и возмож- 
ность открытия указанных пользователем файлов. */
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream file1("file1.txt");
    if (!file1) {
        cerr << "Ошибка: невозможно создать файл file1.txt";
        return -1;
    }
    cout << "Введите текст для записи в файл file1.txt: ";
    string userInput;
    getline(cin, userInput);
    file1 << userInput;
    file1.close();
    ifstream infile("file1.txt");
    if (!infile) {
        cerr << "Ошибка: невозможно открыть файл file1.txt";
        return -1;
    }
    ofstream file2("file2.txt");
    if (!file2) {
        cerr << "Ошибка: невозможно создать файл file2.txt";
        return -1;
    }
    char ch;
    while (infile.get(ch)) {
        file2.put(ch);
    }
    infile.close();
    file2.close();
    cout << "\nСодержимое файла file1.txt:\n";
    ifstream showFile1("file1.txt");
    while (showFile1.get(ch)) {
        cout << ch;
    }
    showFile1.close();
    cout << "\n\nСодержимое файла file2.txt:\n";
    ifstream showFile2("file2.txt");
    while (showFile2.get(ch)) {
        cout << ch;
    }
    showFile2.close();
    return 0;
}
