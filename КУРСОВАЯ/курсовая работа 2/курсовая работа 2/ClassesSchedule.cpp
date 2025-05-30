#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

//�������� ����� 
bool ScheduleManager::fileContains(const string& filename, const string& value) const {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "������: ���� " << filename << " �� ������!" << endl;
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

//�������� ������
bool ScheduleManager::setClass(const string& cls) {
    if (!fileContains("classes.txt", cls)) {
        cerr << "������: ����� " << cls << " �� ������!" << endl;
        return false;
    }
    className = cls;
    return true;
}

//�������� ��������� 
bool ScheduleManager::validateSubject(const string& subject) const {
    string classDigit = className.substr(0, 1);
    string filename = "class_" + classDigit + "_subjects.txt";
    return fileContains(filename, subject);
}

//��� ������
void ScheduleManager::addDay(int day, const vector<string>& lessons) {
    if (day >= 0 && day < 5) {
        schedule.resize(5);
        schedule[day] = lessons;
    }
}

//���������� � ����
void ScheduleManager::saveToFile() const {
    if (className.empty()) {
        cerr << "������: ����� �� ����������!" << endl;
        return;
    }
    string filename = "schedule_" + className + ".txt";
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "������ ��� �������� ����� ����������!" << endl;
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
    cout << "���������� ��� ������ " << className << " ������� ��������� � " << filename << endl;
}

//�������� �� ����� ����������
void ScheduleManager::loadFromFile(const string& cls) {
    string filename = "schedule_" + cls + ".txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "������: ���� ���������� ��� ������ " << cls << " �� ������!" << endl;
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
    cout << "���������� ��� ������ " << cls << " ������� ���������.\n";
}

//������� �������� ���������� 
bool ScheduleManager::deleteClassSchedule() {
    string clsToDelete;
    cout << "������� �������� ������ ��� �������� ����������: ";
    cin >> clsToDelete;

    if (!fileContains("classes.txt", clsToDelete)) {
        cerr << "������: ����� " << clsToDelete << " �� ������ � ������ �������!" << endl;
        return false;
    }

    string filename = "schedule_" + clsToDelete + ".txt";

    // ��������� ������� ����
    ofstream clearFile(filename, ios::trunc);
    if (!clearFile.is_open()) {
        cerr << "������ ��� ������� ����� ����������!" << endl;
        return false;
    }
    clearFile.close();

    // ���� ������� ������� ����������� ����������, ������� � ������
    if (className == clsToDelete) {
        className.clear();
        schedule.clear();
    }

    cout << "���������� ��� ������ " << clsToDelete << " ��������� �������.\n";
    return true;
}

//������������ ����������
void ScheduleBuilder::createNewSchedule() {
    string className;
    cout << "������� �������� ������ (��������, 1a, 2b � �.�.): ";
    cin >> className;

    if (!manager.setClass(className)) {
        return;
    }

    // ������� ��� ����� �� ������ �������� ������
    string filename = "schedule_" + className + ".txt";
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "������ ��� �������� ����� ����������!" << endl;
        return;
    }

    const string days[] = { "�����������", "�������", "�����", "�������", "�������" };

    outFile << "���������� ��� ������ " << className << "\n\n";

    for (int day = 0; day < 5; ++day) {
        cout << "\n" << days[day] << ":\n";
        outFile << days[day] << ":\n";

        int lessonCount;
        cout << "������� ������ � " << days[day] << "? (1-8): ";
        cin >> lessonCount;

        if (lessonCount < 1 || lessonCount > 8) {
            cout << "������������ ���������� ������. ������ ���� �� 1 �� 8." << endl;
            day--;
            continue;
        }

        vector<string> dayLessons;
        for (int lesson = 0; lesson < lessonCount; ++lesson) {
            string subject;
            cout << "������� ������� ��� ����� " << lesson + 1 << ": ";
            cin >> subject;

            if (!manager.validateSubject(subject)) {
                cout << "������: ������� " << subject << " �� ������ � ������ ��������� ��� ����� ������!" << endl;
                lesson--;
                continue;
            }

            dayLessons.push_back(subject);
            outFile << lesson + 1 << ". " << subject << "\n";
        }
        manager.addDay(day, dayLessons);
        outFile << "\n";  // ������ ������ ����� �����
    }
    outFile.close();
    cout << "���������� ������� ��������� � ���� " << filename << endl;
}
//����� ���������� 
void ScheduleManager::printSchedule() const {
    string className;
    cout << "������� �������� ������ ��� ��������� ����������: ";
    cin >> className;
    ifstream file("schedule_" + className + ".txt");
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ���� schedule_" << className << ".txt!" << endl;
        return;
    }

    cout << "\n������ ���������� ��� ������ " << className << ":\n";
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
        cerr << "������: �� ������� ������� ���� schedule_" << className << ".txt!" << endl;
        return;
    }

    cout << "\n������ ���������� ��� ������ " << className << ":\n";
    cout << "=============================================\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    cout << "=============================================\n";

    file.close();
}

