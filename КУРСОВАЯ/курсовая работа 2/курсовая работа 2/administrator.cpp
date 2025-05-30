#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

bool administrator::authorizationA() {//авторизация админа 
link1:
    cout << "Введите логин: "; cin >> loginA;
    cout << "Введите пароль: "; cin >> passA;
    if (passA == "admin2005" && loginA == "admin") return true;//пароль и логин по умолчанию
    else {
        cout << "Неверный логин или пароль! \nПовторите попытку:\n";
        goto link1;
        return false;
    }
}
void administrator::adminMenu() {//меню для администратора 
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
            << "Выберите действие: " << endl
            << "1 - регистрация пользователей" << endl
            << "2 - формирование списков класса" << endl
            << "3 - регулировка времени расписания" << endl
            << "4 - корректировка школьных предметов" << endl
            << "5 - управление расписанием" << endl
            << "0 - назад" << endl
            << "--------------------------------------------" << endl;
        cin >> ch;
        switch (ch) {
        case 0: return;
        case 1://регистрация пользователей 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "Выберите кого хотите зарегистрировать:" << endl
                    << "1 - учитель" << endl
                    << "2 - ученик" << endl
                    << "3 - родитель" << endl
                    << "0 - назад" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1://учитель
                    t.loadT("teachers.txt");
                    t.registrationT();
                    break;
                case 2://ученик
                    s.loadS("studentLogin.txt");
                    s.registrationS();
                    break;
                case 3://родитель
                    p.loadP("parentLogin.txt");
                    p.registrationP();
                    break;
                default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
                }
            }
            break;
        case 2: //работа со списками классов
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "1 - вывести список всех классов" << endl
                    << "2 - добавить новый класс" << endl
                    << "3 - удалить класс" << endl
                    << "4 - вывести список учеников" << endl
                    << "5 - добавить нового ученика в класс" << endl
                    << "6 - удалить ученика из класса" << endl
                    << "0 - назад" << endl
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
                default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
                }
            }
            break;
        case 3://работа со временем уроков 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "Выберите действие: " << endl
                    << "1 - вывести время всех уроков" << endl
                    << "2 - очистить время уроков" << endl
                    << "3 - ввести новое время уроков" << endl
                    << "0 - назад" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1: sch.printall(); break;
                case 2: sch.clearFile(); break;
                case 3: sch.inputLessons(); break;
                default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
                }
            }
            break;
        case 4://школьные предметы
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "Выберите действие: " << endl
                    << "1 - вывести список всех предметов класса" << endl
                    << "2 - удалить предмет" << endl
                    << "3 - добавить другой предмет" << endl
                    << "0 - назад" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                int grade;
                cout << "Введите номер класса (1-4): ";
                cin >> grade;
                cin.ignore();
                if (grade < 1 || grade > 4) {
                    cout << "Некорректный номер класса. Допустимы значения 1-4.\n";
                    continue;
                }
                string subject;
                switch (ch) {
                case 0: goto link;
                case 1: m.showSubjects(grade); break;
                case 2: 
                    cout << "Введите название предмета для удаления: ";
                    cin>>subject;
                    m.removeSubject(grade, subject);
                    break;
                case 3:
                    cout << "Введите название предмета: ";
                    cin >> subject;
                    m.addSubject(grade, subject);
                    break;
                default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
                }
            }
            break;
        case 5://управление расписанием 
            while (true) {
                cout << "--------------------------------------------" << endl
                    << "Выберите действие:" << endl
                    << "1 - вывод текущего расписания" << endl
                    << "2 - удаление расписание" << endl
                    << "3 - добавить расписание" << endl
                    << "0 - назад" << endl
                    << "--------------------------------------------" << endl;
                cin >> ch;
                switch (ch) {
                case 0: goto link;
                case 1: sch.printall(); sm.printSchedule(); break;
                case 2: sm.deleteClassSchedule(); break;
                case 3: sb.createNewSchedule(); break;
                default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
                }
            }
            break;
        }
        
    }
}
