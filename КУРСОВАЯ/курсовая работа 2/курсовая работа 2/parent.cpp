#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

//�������� ������
void parent::loadP(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        parents[login] = { password, surname + " " + name + " " + patronymic };
    }
    file.close();
}

//���������� ������
void parent::saveP(const string& filename, const string& login, const string& password, const string& studentLogin) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }
    file << login << "\t" << password << "\t" << studentLogin << endl;
    file.close();
}

//�������� ������ 
bool parent::isStudentLogin(const string& filename, const string& studentLogin) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return false;
    }

    string surname, name, patronymic, login, password;
    while (file >> surname >> name >> patronymic >> login >> password) {
        if (login == studentLogin) {
            file.close();
            return true; // ������ ����� ��������
        }
    }

    file.close();
    return false; // ������ �������� ��� � �����
}

//����������� ��������
void parent::registrationP() {
    string login, password, studentLogin;
    cout << "������� ����� �������: ";
    cin >> studentLogin;

    // ���������, ���������� �� ����� ������� � �����
    if (!isStudentLogin("studentLogin.txt", studentLogin)) {
        cout << "������: ��������� ����� ������� �� ������ � �����!" << endl;
        return;
    }

    cout << "������� ����� ��������: ";
    cin >> login;
    cout << "������� ������ ��������: ";
    cin >> password;

    if (parents.find(login) != parents.end()) {
        cout << "������: ����� ��� ����������!" << endl;
        return;
    }

    parents[login] = { password, ""};
    parent_link[studentLogin] = login; // ����������� �������� � ��������

    saveP("parentLogin.txt", login, password, studentLogin);
    cout << "�������� ������� ���������������!" << endl;
}

//����������� ���������
void parent::authorizeP() {
    string login, password;
    cout << "������� ����� ��������: ";
    cin >> login;
    cout << "������� ������: ";
    cin >> password;

    // ��������� ����� � ������ �������� � �����
    ifstream parentFile("parentLogin.txt");
    if (!parentFile.is_open()) {
        cerr << "������: �� ������� ������� ���� parentLogin.txt!" << endl;
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
        cout << "������: �������� ����� ��� ������!" << endl;
        return;
    }

    // ���� ��� ������� � studentLogin.txt
    ifstream studentFile("studentLogin.txt");
    if (!studentFile.is_open()) {
        cerr << "������: �� ������� ������� ���� studentLogin.txt!" << endl;
        return;
    }

    string surname, name, studentFileLogin, studentPassword;
    string studentName = "�� ������";
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
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }
    cout << "����� ����������, �������� (" << studentName << ")!" << endl;
    string sname, name1, clas, fileName, cl;
    while (file >> sname >> name1 >> fileName >> password >> clas) {
        if (fileName == studentLogin) {  // ��������� ������������ ������
            cl = clas + ".txt";
            break; // ����� ������, ��������� ����
        }
    }
    studentFile.close();
    file.close();
    ScheduleManager sm;
    Schedule sch;
    Journal j;
    
    int ch;
    while (true) {
        cout << "�������� ��������:" << endl
            << "1 - ���������� ����������" << endl
            << "2 - ���������� ������" << endl
            << "0 - �����" << endl;
        cin >> ch;
        switch (ch) {
        case 0: return;
        case 1: sch.printall(); sm.printSchedule1(cl); break;
        case 2: j.showJournal(cl);
        default: cout << "������������ �����. ���������� �����.\n"; break;
        }
    }
    return;
}
