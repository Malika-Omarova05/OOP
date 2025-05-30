#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

//�������� ������
void student::loadS(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    string surname, name, login, password;
    while (file >> surname >> name >> login >> password) {
        students[login] = { password, surname + " " + name };
    }
    file.close();
}

//���������� ������
void student::saveS(const string& filename, const string& surname, const string& name, const string& login, const string& password) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }
    file << surname << " " << name << " " << " " << login << " " << password << endl;
    file.close();
}

//����������� ��������
void student::registrationS() {
    string surname, name, login, password;
    cout << "������� ������� ��������: ";
    cin >> surname;
    cout << "������� ��� ��������: ";
    cin >> name;
    cout << "������� �����: ";
    cin >> login;
    cout << "������� ������: ";
    cin >> password;
    if (students.find(login) == students.end()) {
        cout << "������: ����� ��� ����������!" << endl;
        return;
    }

    students[login] = { password, surname + " " + name };
    saveS("studentLogin.txt", surname, name, login, password);
    cout << "������ ������� ���������������!" << endl;

}

//����������� ��������
void student::authorizeS() {
    string login, password;
    Journal j;
    cout << "������� �����: ";
    cin >> login;
    cout << "������� ������: ";
    cin >> password;

    auto it = students.find(login);
    if (it != students.end() && it->second.first == password) {
        cout << "����� ����������, " << it->second.second << "!" << endl;

        ifstream file("student.txt");
        if (!file.is_open()) {
            cerr << "������: �� ������� ������� ����!" << endl;
            return;
        }

        bool found = false;
        string sname, name, clas, fileName;
        while (file >> sname >> name >> fileName >> password >> clas) {
            if (fileName == login) {  // ��������� ������������ ������
                found = true;
                break; // ����� ������, ��������� ����
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
            cout << "�������� ��������:" << endl
                << "1 - ���������� ����������" << endl
                << "2 - ���������� ������" << endl
                << "0 - �����" << endl;
            cin >> ch;
            switch (ch) {
            case 0:return;
            case 1:  sch.printall(); sm.printSchedule1(clas); break;
            case 2: j.showJournal(classfile); break;
            default: cout << "������������ �����. ���������� �����.\n"; break;
            }

        }
    }
    else {
        cout << "������: �������� ����� ��� ������!" << endl;
    }
}
