#include <iostream>
#include <string>
#include "header.h"
#include <locale>
#include <iomanip>
#include <fstream>
#include <sstream>
void Date::getdate(string& gradefile) {
    cout << "������� ����:" << endl;
    cout << "����: "; cin >> day;
    cout << "�����: "; cin >> month;
    cout << "���: "; cin >> year;
    ofstream file("date"+gradefile, ios::app);
    if (!file.is_open()) {
        cerr << "������ �������� �����" << endl;
        return;
    }
    file << day << "." << month << "." << year << " ";
}


void Date::putdate(string& file0) {
    ifstream file(file0);
    if (!file.is_open()) {
        cerr << "������ �������� �����" << " ";
        return;
    }

    string date;
    while (getline(file, date)) { // ��������� ������ ������
        cout << date << endl;
    }
     
    file.close();
}


void Journal::addGrade(string& file0) {
    string predmet; Date t;
    while (true) {
        cout << "������� �������� ��������, �� ������� ������ ��������� ������: ";
        cin >> predmet;

        // ������ ������ ���������
        ifstream file("class_1_subjects.txt");
        if (!file.is_open()) {
            cerr << "������ �������� �����!" << endl;
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
            cout << "������: ������� \"" << predmet << L"\" �� ������ � ������!" << endl;
            continue;
        }
        string gradefile;
        if (predmet == "������") {
            pom = "pismo" + file0;
        }
        else if (predmet == "����������") {
            pom = "mat" + file0;
        }
        else if (predmet == "���-��") {
            pom = "fiz" + file0;
        }
        else if (predmet == "����������_���") {
            pom = "om" + file0;
        }
        else if (predmet == "������") {
            pom = "liter" + file0;
        }
        else if (predmet == "���") {
            pom = "izo" + file0;
        }
        else if (predmet == "������") {
            pom = "muz" + file0;
        }
        else {
            cout << "������������� �������"; return;
        }
        t.getdate(pom);
        int result = system(pom.c_str());

        // ���������, ������� �� ����������� �������
        if (result != 0) {
            cerr << "������: �� ������� ������� ���� � ��������." << endl;
            return;
        }
        return;
    }
}

void Journal::showJournal(string& file0) {
    cout << "������� �������, ������� ������ ���������: ";
    string pr, pom;
    cin >> pr;
    if (pr == "������") {
        pom = "pismo" + file0; 
    }
    else if (pr == "����������") {
        pom = "mat" + file0;
    }
    else if (pr == "���-��") {
        pom = "fiz" + file0;
    }
    else if (pr == "����������_���") {
        pom = "om" + file0; 
    }
    else if (pr == "������") {
        pom = "liter" + file0; 
    }
    else if (pr == "���") {
        pom = "izo" + file0;
    }
    else if (pr == "������") {
        pom = "muz" + file0; 
    }
    else {
        cout << "������������� �������"; return;
    }
    Date d;
    int grade;
    cout << "����:   \t\t";
    string n = "date" + pom;
    d.putdate(n);
    ifstream dataFile(n);
    if (!dataFile.is_open()) {
        cerr << "������: ���� " << n << " �� ������!" << endl;
        return;
    }
    ifstream dataFile1(pom);
    if (!dataFile1.is_open()) {
        cerr << "������: ���� " << pom << " �� ������!" << endl;
        return;
    }
    string line;
    for (int i = 1; i <= 10; i++) {
        cout << i << ". ";
        if (getline(dataFile1,line)) {  // ������ ��� ������
            cout << line << endl;
        }
        else {
            break; // ������������� ����, ���� ������ �����������
        }
    }
    return;
}