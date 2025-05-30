#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;
//загрузка данных
void teacher::loadT(const string& filename) {//загрузка данных
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        teachers[login] = { password, surname + " " + name + " " + patronymic };
    }
    file.close();
}

//сохранение данных
void teacher::saveTeacher(const string& filename, const string& surname, const string& name, const string& patronymic, const string& login, const string& password) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }
    file << surname << "\t" << name << "\t" << patronymic << "\t" << login << "\t" << password << endl;
    file.close();
}

//регистрация учителя
void teacher::registrationT() { 
    string surname, name, patronymic, login, password;
    cout << "Введите фамилию учителя: ";
    cin >> surname;
    cout << "Введите имя учителя: ";
    cin >> name;
    cout << "Введите отчество учителя: ";
    cin >> patronymic;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    if (teachers.find(login) != teachers.end()) {
        cout << "Ошибка: Логин уже существует!" << endl;
        return;
    }

    teachers[login] = { password, surname + " " + name + " " + patronymic };
    saveTeacher("teacherLogin.txt", surname, name, patronymic, login, password);
    cout << "Учитель успешно зарегистрирован!" << endl;
}

//авторизация учителя
void teacher::authorizeT() {
    string login, password;

    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    auto it = teachers.find(login);
    if (it == teachers.end() || it->second.first != password) {
        cout << "Ошибка: Неверный логин или пароль!" << endl;
        return ;
    }

    cout << "Добро пожаловать, " << it->second.second << "!" << endl;

    ifstream loginFile("teacher.txt");
    if (!loginFile.is_open()) {
        cerr << "Ошибка: файл teacher.txt не найден!" << endl;
        return ;
    }

    map<string, string> loginToFile;
    string fileLogin, filename;

    while (loginFile >> fileLogin >> filename) {
        loginToFile[fileLogin] = filename + ".txt";
    }
    loginFile.close();
    cout << "\nСписок вашего класса :\n";
    auto fileIt = loginToFile.find(login);
    if (fileIt != loginToFile.end()) {
        string fileToRead = fileIt->second;

        ifstream dataFile(fileToRead);
        if (!dataFile.is_open()) {
            cerr << "Ошибка: файл " << fileToRead << " не найден!" << endl;
            return ;
        }

        string line;
        for (int i = 1; i <= 10; i++) {
            cout << i << ". ";
            if (getline(dataFile, line)) {  // Читаем всю строку
                cout << line << endl;
            }
            else {
                break; // Останавливаем цикл, если строки закончились
            }
        }

        dataFile.close();
        int ch;
        Journal t;
        Schedule sch;
        ScheduleManager sm;
        while (true) {
            cout << "Выберите действие: " << endl
                << "1 - поставить оценку" << endl
                << "2 - посмотреть расписание класса" << endl
                << "3 - просмотреть оценки" << endl
                << "0 - назад" << endl;
            cin >> ch;
            switch (ch) {
            case 0: return;
            case 1: t.addGrade(fileToRead); break;
            case 2:  sch.printall(); sm.printSchedule(); break;
            case 3: t.showJournal(fileToRead); break;
            default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
            }
        }
    }
    else {
        cout << "Для данного логина не найден связанный файл" << endl;
    }

    return ;
}
