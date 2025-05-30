#include <iostream>
#include "header.h"
#include <fstream>
#include <string>

using namespace std;

// создание класса
void SchoolClass::addClass() {
    string className;
    cout << "Введите название нового класса: ";
    cin >> className;

    if (class_students.find(className) == class_students.end()) {
        class_students[className] = {}; // Добавляем класс в память

        // Записываем класс в файл
        ofstream file("classes.txt", ios::app);
        if (!file.is_open()) {
            cerr << "Ошибка: Не удалось открыть файл!" << endl;
            return;
        }
        file << className << endl;
        file.close();

        cout << "Класс " << className << " успешно добавлен и сохранен в файле!" << endl;
    }
    else {
        cout << "Ошибка: Класс " << className << " уже существует!" << endl;
    }
}

//удаление класса 
void SchoolClass::removeClass() {
    string className;
    cout << "Введите название класса, который нужно удалить: ";
    cin >> className;

    // Проверяем, существует ли класс в файле `classes.txt`
    ifstream file("classes.txt");
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }

    vector<string> classList;
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == className) {
            found = true;
        }
        else {
            classList.push_back(line);
        }
    }
    file.close();

    if (!found) {
        cout << "Ошибка: Класс " << className << " не найден в файле!" << endl;
        return;
    }

    // перезаписываем без удаленного класса
    ofstream outFile("classes.txt");
    if (!outFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для записи!" << endl;
        return;
    }

    for (const string& cls : classList) {
        outFile << cls << endl;
    }
    outFile.close();

    // Удаляем класс из памяти
    class_students.erase(className);
    cout << "Класс " << className << " успешно удален из памяти и файла!" << endl;
}


//добавление нового студента
void SchoolClass::addStudent() {
    string classname, surname, name;
    cout << "Введите класс,в который хотите добавить ученика: "; cin >> classname;

    ofstream file(classname + ".txt");
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }

    cout << "Введите фамилию ученика: "; cin >> surname;
    cout << "Введите имя ученика: "; cin >> name;

    ifstream loginFile("studentLogin.txt");
    if (!loginFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл studentLogin.txt!" << endl;
        return;
    }

    string fileSurname, fileName, login, password;
    bool stud = true;

    while (loginFile >> fileSurname >> fileName >> login >> password) {
        if (fileSurname == surname && fileName == name) {
            stud = false;
            break;
        }
    }
    loginFile.close();

    if (stud) {
        cout << "Пользователя не существует!" << endl;
        return;
    }

    ofstream classFile(classname + ".txt", ios::app); 
    if (!classFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << classname << ".txt!" << endl;
        return;
    }

    classFile << surname << " " << name << endl;
    classFile.close();

    cout << "Ученик добавлен в класс " << classname << "." << endl;

}

//удаление студента
void SchoolClass::removeStudent() {
 
    string classname, surname, name;
    cout << "Введите класс, из которого хотите удалить ученика: ";
    cin >> classname;

    ifstream classFile(classname + ".txt");
    if (!classFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << classname << ".txt!" << endl;
        return;
    }

    cout << "Введите фамилию ученика: ";
    cin >> surname;
    cout << "Введите имя ученика: ";
    cin >> name;

    vector<string> students;
    string fileSurname, fileName;
    bool found = false;

    // Чтение всех учеников в память
    while (classFile >> fileSurname >> fileName) {
        if (fileSurname == surname && fileName == name) {
            found = true; // Пропускаем найденного ученика
            continue;
        }
        students.push_back(fileSurname + " " + fileName);
    }
    classFile.close();

    if (!found) {
        cout << "Ученик не найден в классе " << classname << "." << endl;
        return;
    }

    // Перезаписываем файл без удалённого ученика
    ofstream outFile(classname + ".txt");
    if (!outFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для перезаписи!" << endl;
        return;
    }

    for (const auto& line : students) {
        outFile << line << endl;
    }
    outFile.close();

    cout << "Ученик успешно удалён из класса " << classname << "." << endl;
}

//вывод всех существующих классов
void SchoolClass::printClass() {
    ifstream file("classes.txt");
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
        return;
    }

    string line;
    cout << "Существующие классы" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

//вывод учеников класса
void SchoolClass::printStudent() {
    string filename;
    cout << "Введите класс: ";
    cin >> filename;

    ifstream file(filename+".txt");
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл!" << endl;
        return;
    }

    string name, surname;
    cout << "Ученики из " << filename << " класса" << endl;
    while (file>>surname>>name) {
        cout << surname << "  " << name << endl;
    }

    file.close();

}
