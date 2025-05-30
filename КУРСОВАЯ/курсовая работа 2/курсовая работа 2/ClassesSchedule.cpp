#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

//проверка файла 
bool ScheduleManager::fileContains(const string& filename, const string& value) const {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Ошибка: файл " << filename << " не найден!" << endl;
        return false;
    }

    while (getline(file, line)) {
        if (line == value) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//проверка класса
bool ScheduleManager::setClass(const string& cls) {
    if (!fileContains("classes.txt", cls)) {
        cerr << "Ошибка: класс " << cls << " не найден!" << endl;
        return false;
    }
    className = cls;
    return true;
}

//проверка предметов 
bool ScheduleManager::validateSubject(const string& subject) const {
    string classDigit = className.substr(0, 1);
    string filename = "class_" + classDigit + "_subjects.txt";
    return fileContains(filename, subject);
}

//дни недели
void ScheduleManager::addDay(int day, const vector<string>& lessons) {
    if (day >= 0 && day < 5) {
        schedule.resize(5);
        schedule[day] = lessons;
    }
}

//сохранение в файл
void ScheduleManager::saveToFile() const {
    if (className.empty()) {
        cerr << "Ошибка: класс не установлен!" << endl;
        return;
    }
    string filename = "schedule_" + className + ".txt";
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка при создании файла расписания!" << endl;
        return;
    }
    const string days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
    for (int day = 0; day < 5; ++day) {
        file << days[day] << ":\n";
        for (int lesson = 0; lesson < schedule[day].size(); ++lesson) {
            file << lesson + 1 << ". " << schedule[day][lesson] << "\n";
        }
        file << "\n";
    }
    file.close();
    cout << "Расписание для класса " << className << " успешно сохранено в " << filename << endl;
}

//выгрузка из файла расписание
void ScheduleManager::loadFromFile(const string& cls) {
    string filename = "schedule_" + cls + ".txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: файл расписания для класса " << cls << " не найден!" << endl;
        return;
    }

    className = cls;
    schedule.clear();
    schedule.resize(5);

    string line;
    int currentDay = -1;

    const string days[] = { "Monday:", "Tuesday:", "Wednesday:", "Thursday:", "Friday:" };

    while (getline(file, line)) {
        for (int i = 0; i < 5; ++i) {
            if (line == days[i]) {
                currentDay = i;
                break;
            }
        }
        if (currentDay != -1 && !line.empty() && isdigit(line[0])) {
            size_t dotPos = line.find('.');
            if (dotPos != string::npos) {
                string subject = line.substr(dotPos + 2);
                schedule[currentDay].push_back(subject);
            }
        }
    }

    file.close();
    cout << "Расписание для класса " << cls << " успешно загружено.\n";
}

//очистка текущего расписания 
bool ScheduleManager::deleteClassSchedule() {
    string clsToDelete;
    cout << "Введите название класса для удаления расписания: ";
    cin >> clsToDelete;

    if (!fileContains("classes.txt", clsToDelete)) {
        cerr << "Ошибка: класс " << clsToDelete << " не найден в списке классов!" << endl;
        return false;
    }

    string filename = "schedule_" + clsToDelete + ".txt";

    // Полностью очищаем файл
    ofstream clearFile(filename, ios::trunc);
    if (!clearFile.is_open()) {
        cerr << "Ошибка при очистке файла расписания!" << endl;
        return false;
    }
    clearFile.close();

    // Если удаляем текущее загруженное расписание, очищаем и память
    if (className == clsToDelete) {
        className.clear();
        schedule.clear();
    }

    cout << "Расписание для класса " << clsToDelete << " полностью очищено.\n";
    return true;
}

//формировнаие расписания
void ScheduleBuilder::createNewSchedule() {
    string className;
    cout << "Введите название класса (например, 1a, 2b и т.д.): ";
    cin >> className;

    if (!manager.setClass(className)) {
        return;
    }

    // Создаем имя файла на основе названия класса
    string filename = "schedule_" + className + ".txt";
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Ошибка при создании файла расписания!" << endl;
        return;
    }

    const string days[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница" };

    outFile << "Расписание для класса " << className << "\n\n";

    for (int day = 0; day < 5; ++day) {
        cout << "\n" << days[day] << ":\n";
        outFile << days[day] << ":\n";

        int lessonCount;
        cout << "Сколько уроков в " << days[day] << "? (1-8): ";
        cin >> lessonCount;

        if (lessonCount < 1 || lessonCount > 8) {
            cout << "Недопустимое количество уроков. Должно быть от 1 до 8." << endl;
            day--;
            continue;
        }

        vector<string> dayLessons;
        for (int lesson = 0; lesson < lessonCount; ++lesson) {
            string subject;
            cout << "Введите предмет для урока " << lesson + 1 << ": ";
            cin >> subject;

            if (!manager.validateSubject(subject)) {
                cout << "Ошибка: предмет " << subject << " не найден в списке предметов для этого класса!" << endl;
                lesson--;
                continue;
            }

            dayLessons.push_back(subject);
            outFile << lesson + 1 << ". " << subject << "\n";
        }
        manager.addDay(day, dayLessons);
        outFile << "\n";  // Пустая строка между днями
    }
    outFile.close();
    cout << "Расписание успешно сохранено в файл " << filename << endl;
}
//вывод расписания 
void ScheduleManager::printSchedule() const {
    string className;
    cout << "Введите название класса для просмотра расписания: ";
    cin >> className;
    ifstream file("schedule_" + className + ".txt");
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл schedule_" << className << ".txt!" << endl;
        return;
    }

    cout << "\nПолное расписание для класса " << className << ":\n";
    cout << "=============================================\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "=============================================\n";

    file.close();
}
void ScheduleManager::printSchedule1(string & className) const {
    ifstream file("schedule_" + className + ".txt");
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл schedule_" << className << ".txt!" << endl;
        return;
    }

    cout << "\nПолное расписание для класса " << className << ":\n";
    cout << "=============================================\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "=============================================\n";

    file.close();
}

