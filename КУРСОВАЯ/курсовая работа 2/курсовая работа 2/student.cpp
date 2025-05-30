#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

//загрузка данных
void student::loadS(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }

    string surname, name, login, password;
    while (file >> surname >> name >> login >> password) {
        students[login] = { password, surname + " " + name };
    }
    file.close();
}

//сохранение данных
void student::saveS(const string& filename, const string& surname, const string& name, const string& login, const string& password) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }
    file << surname << " " << name << " " << " " << login << " " << password << endl;
    file.close();
}

//регистрация учеников
void student::registrationS() {
    string surname, name, login, password;
    cout << "Введите фамилию студента: ";
    cin >> surname;
    cout << "Введите имя студента: ";
    cin >> name;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;
    if (students.find(login) == students.end()) {
        cout << "Ошибка: Логин уже существует!" << endl;
        return;
    }

    students[login] = { password, surname + " " + name };
    saveS("studentLogin.txt", surname, name, login, password);
    cout << "Ученик успешно зарегистрирован!" << endl;

}

//авторизация учеников
void student::authorizeS() {
    string login, password;
    Journal j;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    auto it = students.find(login);
    if (it != students.end() && it->second.first == password) {
        cout << "Добро пожаловать, " << it->second.second << "!" << endl;

        ifstream file("student.txt");
        if (!file.is_open()) {
            cerr << "Ошибка: Не удалось открыть файл!" << endl;
            return;
        }

        bool found = false;
        string sname, name, clas, fileName;
        while (file >> sname >> name >> fileName >> password >> clas) {
            if (fileName == login) {  // Проверяем соответствие логина
                found = true;
                break; // Логин найден, завершаем цикл
            }
        }
        file.close();
        string classfile;
        if (found) {
            classfile = clas + ".txt";
        }
        Schedule sch; ScheduleManager sm;
        while (true) {
            int ch;
            cout << "Выберите действие:" << endl
                << "1 - посмотреть расписание" << endl
                << "2 - посмотреть оценки" << endl
                << "0 - назад" << endl;
            cin >> ch;
            switch (ch) {
            case 0:return;
            case 1:  sch.printall(); sm.printSchedule1(clas); break;
            case 2: j.showJournal(classfile); break;
            default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
            }

        }
    }
    else {
        cout << "Ошибка: Неверный логин или пароль!" << endl;
    }
}
