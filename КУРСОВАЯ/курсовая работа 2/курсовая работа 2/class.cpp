#include <iostream>
#include "header.h"
#include <fstream>
#include <string>

using namespace std;

// �������� ������
void SchoolClass::addClass() {
    string className;
    cout << "������� �������� ������ ������: ";
    cin >> className;

    if (class_students.find(className) == class_students.end()) {
        class_students[className] = {}; // ��������� ����� � ������

        // ���������� ����� � ����
        ofstream file("classes.txt", ios::app);
        if (!file.is_open()) {
            cerr << "������: �� ������� ������� ����!" << endl;
            return;
        }
        file << className << endl;
        file.close();

        cout << "����� " << className << " ������� �������� � �������� � �����!" << endl;
    }
    else {
        cout << "������: ����� " << className << " ��� ����������!" << endl;
    }
}

//�������� ������ 
void SchoolClass::removeClass() {
    string className;
    cout << "������� �������� ������, ������� ����� �������: ";
    cin >> className;

    // ���������, ���������� �� ����� � ����� `classes.txt`
    ifstream file("classes.txt");
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
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
        cout << "������: ����� " << className << " �� ������ � �����!" << endl;
        return;
    }

    // �������������� ��� ���������� ������
    ofstream outFile("classes.txt");
    if (!outFile.is_open()) {
        cerr << "������: �� ������� ������� ���� ��� ������!" << endl;
        return;
    }

    for (const string& cls : classList) {
        outFile << cls << endl;
    }
    outFile.close();

    // ������� ����� �� ������
    class_students.erase(className);
    cout << "����� " << className << " ������� ������ �� ������ � �����!" << endl;
}


//���������� ������ ��������
void SchoolClass::addStudent() {
    string classname, surname, name;
    cout << "������� �����,� ������� ������ �������� �������: "; cin >> classname;

    ofstream file(classname + ".txt");
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    cout << "������� ������� �������: "; cin >> surname;
    cout << "������� ��� �������: "; cin >> name;

    ifstream loginFile("studentLogin.txt");
    if (!loginFile.is_open()) {
        cerr << "������: �� ������� ������� ���� studentLogin.txt!" << endl;
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
        cout << "������������ �� ����������!" << endl;
        return;
    }

    ofstream classFile(classname + ".txt", ios::app); 
    if (!classFile.is_open()) {
        cerr << "������: �� ������� ������� ���� " << classname << ".txt!" << endl;
        return;
    }

    classFile << surname << " " << name << endl;
    classFile.close();

    cout << "������ �������� � ����� " << classname << "." << endl;

}

//�������� ��������
void SchoolClass::removeStudent() {
 
    string classname, surname, name;
    cout << "������� �����, �� �������� ������ ������� �������: ";
    cin >> classname;

    ifstream classFile(classname + ".txt");
    if (!classFile.is_open()) {
        cerr << "������: �� ������� ������� ���� " << classname << ".txt!" << endl;
        return;
    }

    cout << "������� ������� �������: ";
    cin >> surname;
    cout << "������� ��� �������: ";
    cin >> name;

    vector<string> students;
    string fileSurname, fileName;
    bool found = false;

    // ������ ���� �������� � ������
    while (classFile >> fileSurname >> fileName) {
        if (fileSurname == surname && fileName == name) {
            found = true; // ���������� ���������� �������
            continue;
        }
        students.push_back(fileSurname + " " + fileName);
    }
    classFile.close();

    if (!found) {
        cout << "������ �� ������ � ������ " << classname << "." << endl;
        return;
    }

    // �������������� ���� ��� ��������� �������
    ofstream outFile(classname + ".txt");
    if (!outFile.is_open()) {
        cerr << "������: �� ������� ������� ���� ��� ����������!" << endl;
        return;
    }

    for (const auto& line : students) {
        outFile << line << endl;
    }
    outFile.close();

    cout << "������ ������� ����� �� ������ " << classname << "." << endl;
}

//����� ���� ������������ �������
void SchoolClass::printClass() {
    ifstream file("classes.txt");
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    string line;
    cout << "������������ ������" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

//����� �������� ������
void SchoolClass::printStudent() {
    string filename;
    cout << "������� �����: ";
    cin >> filename;

    ifstream file(filename+".txt");
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    string name, surname;
    cout << "������� �� " << filename << " ������" << endl;
    while (file>>surname>>name) {
        cout << surname << "  " << name << endl;
    }

    file.close();

}
