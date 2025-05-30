#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;
//�������� ������
void teacher::loadT(const string& filename) {//�������� ������
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        teachers[login] = { password, surname + " " + name + " " + patronymic };
    }
    file.close();
}

//���������� ������
void teacher::saveTeacher(const string& filename, const string& surname, const string& name, const string& patronymic, const string& login, const string& password) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }
    file << surname << "\t" << name << "\t" << patronymic << "\t" << login << "\t" << password << endl;
    file.close();
}

//����������� �������
void teacher::registrationT() { 
    string surname, name, patronymic, login, password;
    cout << "������� ������� �������: ";
    cin >> surname;
    cout << "������� ��� �������: ";
    cin >> name;
    cout << "������� �������� �������: ";
    cin >> patronymic;
    cout << "������� �����: ";
    cin >> login;
    cout << "������� ������: ";
    cin >> password;

    if (teachers.find(login) != teachers.end()) {
        cout << "������: ����� ��� ����������!" << endl;
        return;
    }

    teachers[login] = { password, surname + " " + name + " " + patronymic };
    saveTeacher("teacherLogin.txt", surname, name, patronymic, login, password);
    cout << "������� ������� ���������������!" << endl;
}

//����������� �������
void teacher::authorizeT() {
    string login, password;

    cout << "������� �����: ";
    cin >> login;
    cout << "������� ������: ";
    cin >> password;

    auto it = teachers.find(login);
    if (it == teachers.end() || it->second.first != password) {
        cout << "������: �������� ����� ��� ������!" << endl;
        return ;
    }

    cout << "����� ����������, " << it->second.second << "!" << endl;

    ifstream loginFile("teacher.txt");
    if (!loginFile.is_open()) {
        cerr << "������: ���� teacher.txt �� ������!" << endl;
        return ;
    }

    map<string, string> loginToFile;
    string fileLogin, filename;

    while (loginFile >> fileLogin >> filename) {
        loginToFile[fileLogin] = filename + ".txt";
    }
    loginFile.close();
    cout << "\n������ ������ ������ :\n";
    auto fileIt = loginToFile.find(login);
    if (fileIt != loginToFile.end()) {
        string fileToRead = fileIt->second;

        ifstream dataFile(fileToRead);
        if (!dataFile.is_open()) {
            cerr << "������: ���� " << fileToRead << " �� ������!" << endl;
            return ;
        }

        string line;
        for (int i = 1; i <= 10; i++) {
            cout << i << ". ";
            if (getline(dataFile, line)) {  // ������ ��� ������
                cout << line << endl;
            }
            else {
                break; // ������������� ����, ���� ������ �����������
            }
        }

        dataFile.close();
        int ch;
        Journal t;
        Schedule sch;
        ScheduleManager sm;
        while (true) {
            cout << "�������� ��������: " << endl
                << "1 - ��������� ������" << endl
                << "2 - ���������� ���������� ������" << endl
                << "3 - ����������� ������" << endl
                << "0 - �����" << endl;
            cin >> ch;
            switch (ch) {
            case 0: return;
            case 1: t.addGrade(fileToRead); break;
            case 2:  sch.printall(); sm.printSchedule(); break;
            case 3: t.showJournal(fileToRead); break;
            default: cout << "������������ �����. ���������� �����.\n"; break;
            }
        }
    }
    else {
        cout << "��� ������� ������ �� ������ ��������� ����" << endl;
    }

    return ;
}
