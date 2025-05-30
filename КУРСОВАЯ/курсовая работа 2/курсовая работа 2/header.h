#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
//класс администратор 
class administrator {
private:
	string loginA;//логин админа
	string passA;//пароль админа
public:
	bool authorizationA();//авторизация администратора 
	void adminMenu();//меню для администратора 
};

//класс учитель
class teacher {
private:
	map<string, pair<string, string>> teachers;//Логин -> (Пароль, ФИО)
public:
	void loadT(const string&);//загрузка данных
	void registrationT();//регистрация учителей
	void saveTeacher(const string&, const string&, const string&, const string&, const string&, const string&);//сохранение данных
	void authorizeT(); //авторизация учителя
};

//класс ученик
class student {
private:
	map<string, pair<string, string>>students;// Логин -> (Пароль, ФИО)
public:
	void loadS(const string&);//загрузка данных учеников
	void registrationS();//регистрация учеников
	void saveS(const string&, const string&, const string&, const string&, const string&);//сохранение данных учеников
	void authorizeS();//авторизация учеников
};

//класс родитель
class parent {
private:
	map<string, pair<string, string>> parents; // Логин -> (Пароль, ФИО)
	map<string, string> parent_link; // Логин студента -> Логин родителя
public:
	void loadP(const string&);//загрузка данных родителей
	void registrationP();//регистрация родителей
	void saveP(const string&, const string&, const string&, const string&);//сохранение данных родителей
	void authorizeP();//авторизация родителей
	bool isStudentLogin(const string&, const string&);//проверка логинов учеников из файла
};

//школьные классы
class SchoolClass {
private:
	map<string, vector<string>> class_students; // Класс -> список логинов учеников
public:
	void addClass(); //добавление класса 
	void removeClass();//удаление класса 
	void addStudent();//добавление нового ученика в класс
	void removeStudent();//удаление ученика из класса 
	void printClass();//список существующих классов
	void printStudent();//вывод учеников класса 
};

//класс для времени
class Time {
private:
	int hour, minute;
public:
	Time();
	void getTime();//ввод времени
	string formatTime() const;//преобразование в тип строки
	void setTime(int h, int m);//сохранение 
	bool operator<(const Time& other) const;//сравнение
};

//класс для урока по времени 
class Schedule {
private:
	map<int, pair<Time, Time>> lessons;//номер урока -> время начала, время конца 
public:
	void inputLessons();//ввод начала и конца урока 
	void saveToFile(const string&); //сохранение в файле 
	void loadFromFile(const string&);//загрузка файла
	void printall();//вывод всех времен
	void clearFile();//очистка всего файла
};

//класс для предметов 
class SubjectManager {
private:
	const vector<int> grades = { 1, 2, 3, 4 }; // Поддерживаемые классы
	string getFilename(int grade) const; // генерация имени файла для класса
	bool subjectExists(const vector<string>& subjects, const string& subject) const; // проверка существования предмета в списке
public:
	void addSubject(int grade, const string& subject); // добавить предмет для класса
	void showSubjects(int grade) const;    // показать все предметы класса
	vector<string> getSubjects(int grade) const; // получить список предметов класса
	void removeSubject(int grade, const string& subject); // удалить предмет из класса
};

//класс расписание 
class ScheduleManager :public Schedule {
private:
	string className;
	vector<vector<string>> schedule;
	bool fileContains(const string& filename, const string& value) const; //проверка файла
public:
	ScheduleManager() = default; //конструктор
	bool setClass(const string& cls); //проверка наличие класса
	bool validateSubject(const string& subject) const; //проверка предметов 
	void addDay(int day, const vector<string>& lessons); //дни недели
	void saveToFile() const; //сохранение в файл 
	void loadFromFile(const string& cls);//выгрузка из файла
	bool deleteClassSchedule(); //очистка файла и расписания
	void printSchedule() const;//вывод расписание класса по желанию пользователя
	void printSchedule1(string&) const;//вывод с фиксированным классом
};

//класс для формирования расписания 
class ScheduleBuilder {
private:
	ScheduleManager manager; // вспомогательная переменная
public:
	void createNewSchedule(); //для формирования расписания 
};

// класс для даты
class Date {  
private:
	int day;
	int month;
	int year;
public:
	void getdate(string&); // ввод даты 
	void putdate(string&); // вывод даты 
};

//класс журнал
class Journal {
private:
	int grade; 
	string nameFile;
	string date;
public:
	void addGrade(string&); // Добавить оценку ученику
	void showJournal(string&); //показать жуpнал 
};

