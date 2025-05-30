#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

bool administrator::authorizationA() {//����������� ������ 
link1:
    cout << "������� �����: "; cin >> loginA;
    cout << "������� ������: "; cin >> passA;
    if (passA == "admin2005" && loginA == "admin") return true;//������ � ����� �� ���������
    else {
        cout << "�������� ����� ��� ������! \n��������� �������:\n";
        goto link1;
        return false;
    }
}
void administrator::adminMenu() {//���� ��� �������������� 
    int ch;
    teacher t;
    student s;
    parent p;
    SchoolClass cl;
    Schedule sch;
    SubjectManager m;
    ScheduleManager sm;
    ScheduleBuilder sb;
    while (true) {
        link:
        cout << "--------------------------------------------" << endl
            << "�������� ��������: " << endl
            << "1 - ����������� �������������" << endl
            << "2 - ������������ ������� ������" << endl
            << "3 - ����������� ������� ����������" << endl
            << "4 - ������������� �������� ���������" << endl
            << "5 - ���������� �����������" << endl
            << "0 - �����" << endl
            << "--------------------------------------------" << endl;
        cin >> ch;
        switch (ch) {
        case 0: return;
        case 1://����������� ������������� 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "�������� ���� ������ ����������������:" << endl
                    << "1 - �������" << endl
                    << "2 - ������" << endl
                    << "3 - ��������" << endl
                    << "0 - �����" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1://�������
                    t.loadT("teachers.txt");
                    t.registrationT();
                    break;
                case 2://������
                    s.loadS("studentLogin.txt");
                    s.registrationS();
                    break;
                case 3://��������
                    p.loadP("parentLogin.txt");
                    p.registrationP();
                    break;
                default: cout << "������������ �����. ���������� �����.\n"; break;
                }
            }
            break;
        case 2: //������ �� �������� �������
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "1 - ������� ������ ���� �������" << endl
                    << "2 - �������� ����� �����" << endl
                    << "3 - ������� �����" << endl
                    << "4 - ������� ������ ��������" << endl
                    << "5 - �������� ������ ������� � �����" << endl
                    << "6 - ������� ������� �� ������" << endl
                    << "0 - �����" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1: cl.printClass(); break;
                case 2: cl.addClass(); break;
                case 3: cl.removeClass(); break;
                case 4: cl.printStudent(); break;
                case 5: cl.addStudent(); break;
                case 6: cl.removeStudent(); break;
                default: cout << "������������ �����. ���������� �����.\n"; break;
                }
            }
            break;
        case 3://������ �� �������� ������ 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "�������� ��������: " << endl
                    << "1 - ������� ����� ���� ������" << endl
                    << "2 - �������� ����� ������" << endl
                    << "3 - ������ ����� ����� ������" << endl
                    << "0 - �����" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1: sch.printall(); break;
                case 2: sch.clearFile(); break;
                case 3: sch.inputLessons(); break;
                default: cout << "������������ �����. ���������� �����.\n"; break;
                }
            }
            break;
        case 4://�������� ��������
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "�������� ��������: " << endl
                    << "1 - ������� ������ ���� ��������� ������" << endl
                    << "2 - ������� �������" << endl
                    << "3 - �������� ������ �������" << endl
                    << "0 - �����" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                int grade;
                cout << "������� ����� ������ (1-4): ";
                cin >> grade;
                cin.ignore();
                if (grade < 1 || grade > 4) {
                    cout << "������������ ����� ������. ��������� �������� 1-4.\n";
                    continue;
                }
                string subject;
                switch (ch) {
                case 0: goto link;
                case 1: m.showSubjects(grade); break;
                case 2: 
                    cout << "������� �������� �������� ��� ��������: ";
                    cin>>subject;
                    m.removeSubject(grade, subject);
                    break;
                case 3:
                    cout << "������� �������� ��������: ";
                    cin >> subject;
                    m.addSubject(grade, subject);
                    break;
                default: cout << "������������ �����. ���������� �����.\n"; break;
                }
            }
            break;
        case 5://���������� ����������� 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "�������� ��������:" << endl
                    << "1 - ����� �������� ����������" << endl
                    << "2 - �������� ����������" << endl
                    << "3 - �������� ����������" << endl
                    << "0 - �����" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1: sch.printall(); sm.printSchedule(); break;
                case 2: sm.deleteClassSchedule(); break;
                case 3: sb.createNewSchedule(); break;
                default: cout << "������������ �����. ���������� �����.\n"; break;
                }
            }
            break;
        }
        
    }
}
