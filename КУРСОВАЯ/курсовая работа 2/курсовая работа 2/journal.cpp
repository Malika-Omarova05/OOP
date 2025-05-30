#include <iostream>
#include <string>
#include "header.h"
#include <locale>
#include <iomanip>
#include <fstream>
#include <sstream>
void Date::getdate(string& gradefile) {
    cout << "Введите дату:" << endl;
    cout << "День: "; cin >> day;
    cout << "Месяц: "; cin >> month;
    cout << "Год: "; cin >> year;
    ofstream file("date"+gradefile, ios::app);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }
    file << day << "." << month << "." << year << " ";
}


void Date::putdate(string& file0) {
    ifstream file(file0);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла" << " ";
        return;
    }

    string date;
    while (getline(file, date)) { // Считываем каждую строку
        cout << date << endl;
    }
     
    file.close();
}


void Journal::addGrade(string& file0) {
    string predmet; Date t;
    while (true) {
        cout << "Введите название предмета, за который хотите выставить оценку: ";
        cin >> predmet;

        // Читаем список предметов
        ifstream file("class_1_subjects.txt");
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла!" << endl;
            return;
        }

        string word;
        bool found = false;
        string pom;
        while (file >> word) {
            if (word == predmet) {
                found = true;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "Ошибка: предмет \"" << predmet << L"\" не найден в списке!" << endl;
            continue;
        }
        string gradefile;
        if (predmet == "письмо") {
            pom = "pismo" + file0;
        }
        else if (predmet == "математика") {
            pom = "mat" + file0;
        }
        else if (predmet == "физ-ра") {
            pom = "fiz" + file0;
        }
        else if (predmet == "окружающий_мир") {
            pom = "om" + file0;
        }
        else if (predmet == "чтение") {
            pom = "liter" + file0;
        }
        else if (predmet == "ИЗО") {
            pom = "izo" + file0;
        }
        else if (predmet == "музыка") {
            pom = "muz" + file0;
        }
        else {
            cout << "Перепроверьте предмет"; return;
        }
        t.getdate(pom);
        int result = system(pom.c_str());

        // Проверяем, успешно ли выполнилась команда
        if (result != 0) {
            cerr << "Ошибка: не удалось открыть файл в блокноте." << endl;
            return;
        }
        return;
    }
}

void Journal::showJournal(string& file0) {
    cout << "Введите предмет, который хотите проверить: ";
    string pr, pom;
    cin >> pr;
    if (pr == "письмо") {
        pom = "pismo" + file0; 
    }
    else if (pr == "математика") {
        pom = "mat" + file0;
    }
    else if (pr == "физ-ра") {
        pom = "fiz" + file0;
    }
    else if (pr == "окружающий_мир") {
        pom = "om" + file0; 
    }
    else if (pr == "чтение") {
        pom = "liter" + file0; 
    }
    else if (pr == "ИЗО") {
        pom = "izo" + file0;
    }
    else if (pr == "музыка") {
        pom = "muz" + file0; 
    }
    else {
        cout << "Перепроверьте предмет"; return;
    }
    Date d;
    int grade;
    cout << "Дата:   \t\t";
    string n = "date" + pom;
    d.putdate(n);
    ifstream dataFile(n);
    if (!dataFile.is_open()) {
        cerr << "Ошибка: файл " << n << " не найден!" << endl;
        return;
    }
    ifstream dataFile1(pom);
    if (!dataFile1.is_open()) {
        cerr << "Ошибка: файл " << pom << " не найден!" << endl;
        return;
    }
    string line;
    for (int i = 1; i <= 10; i++) {
        cout << i << ". ";
        if (getline(dataFile1,line)) {  // Читаем всю строку
            cout << line << endl;
        }
        else {
            break; // Останавливаем цикл, если строки закончились
        }
    }
    return;
}