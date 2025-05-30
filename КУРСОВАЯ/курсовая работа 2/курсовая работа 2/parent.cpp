#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

//загрузка данных
void parent::loadP(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        parents[login] = { password, surname + " " + name + " " + patronymic };
    }
    file.close();
}

//сохранение данных
void parent::saveP(const string& filename, const string& login, const string& password, const string& studentLogin) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }
    file << login << "\t" << password << "\t" << studentLogin << endl;
    file.close();
}

//проверка логина 
bool parent::isStudentLogin(const string& filename, const string& studentLogin) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return false;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        if (login == studentLogin) {
            file.close();
            return true; // Найден логин студента
        }
    }

    file.close();
    return false; // Логина студента нет в файле
}

//регистрация родителя
void parent::registrationP() {
    string login, password, studentLogin;
    cout << "Введите логин ребенка: ";
    cin >> studentLogin;

    // Проверяем, существует ли логин ребенка в файле
    if (!isStudentLogin("studentLogin.txt", studentLogin)) {
        cout << "Ошибка: Указанный логин ребенка не найден в файле!" << endl;
        return;
    }

    cout << "Введите логин родителя: ";
    cin >> login;
    cout << "Введите пароль родителя: ";
    cin >> password;

    if (parents.find(login) != parents.end()) {
        cout << "Ошибка: Логин уже существует!" << endl;
        return;
    }

    parents[login] = { password, ""};
    parent_link[studentLogin] = login; // Привязываем родителя к студенту

    saveP("parentLogin.txt", login, password, studentLogin);
    cout << "Родитель успешно зарегистрирован!" << endl;
}

//авторизация родителей
void parent::authorizeP() {
    string login, password;
    cout << "Введите логин родителя: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    // Проверяем логин и пароль родителя в файле
    ifstream parentFile("parentLogin.txt");
    if (!parentFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл parentLogin.txt!" << endl;
        return;
    }

    bool isAuthorized = false;
    string fileLogin, filePassword, studentLogin;
    while (parentFile >> fileLogin >> filePassword >> studentLogin) {
        if (fileLogin == login && filePassword == password) {
            isAuthorized = true;
            break;
        }
    }
    parentFile.close();

    if (!isAuthorized) {
        cout << "Ошибка: Неверный логин или пароль!" << endl;
        return;
    }

    // Ищем имя ребенка в studentLogin.txt
    ifstream studentFile("studentLogin.txt");
    if (!studentFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл studentLogin.txt!" << endl;
        return;
    }

    string surname, name, studentFileLogin, studentPassword;
    string studentName = "Не найден";
    bool found = false;
    while (studentFile >> surname >> name  >> studentFileLogin >> studentPassword) {
        if (studentFileLogin == studentLogin) {
            studentName = surname + " " + name;
            found = true;
            break;
        }
    }
    ifstream file("student.txt");
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл!" << endl;
        return;
    }
    cout << "Добро пожаловать, родитель (" << studentName << ")!" << endl;
    string sname, name1, clas, fileName, cl;
    while (file >> sname >> name1 >> fileName >> password >> clas) {
        if (fileName == studentLogin) {  // Проверяем соответствие логина
            cl = clas + ".txt";
            break; // Логин найден, завершаем цикл
        }
    }
    studentFile.close();
    file.close();
    ScheduleManager sm;
    Schedule sch;
    Journal j;
    
    int ch;
    while (true) {
        cout << "Выберите действие:" << endl
            << "1 - посмотреть расписание" << endl
            << "2 - посмотреть оценки" << endl
            << "0 - назад" << endl;
        cin >> ch;
        switch (ch) {
        case 0: return;
        case 1: sch.printall(); sm.printSchedule1(cl); break;
        case 2: j.showJournal(cl);
        default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
        }
    }
    return;
}
