#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
//����� ������������� 
class administrator {
private:
	string loginA;//����� ������
	string passA;//������ ������
public:
	bool authorizationA();//����������� �������������� 
	void adminMenu();//���� ��� �������������� 
};

//����� �������
class teacher {
private:
	map<string, pair<string, string>> teachers;//����� -> (������, ���)
public:
	void loadT(const string&);//�������� ������
	void registrationT();//����������� ��������
	void saveTeacher(const string&, const string&, const string&, const string&, const string&, const string&);//���������� ������
	void authorizeT(); //����������� �������
};

//����� ������
class student {
private:
	map<string, pair<string, string>>students;// ����� -> (������, ���)
public:
	void loadS(const string&);//�������� ������ ��������
	void registrationS();//����������� ��������
	void saveS(const string&, const string&, const string&, const string&, const string&);//���������� ������ ��������
	void authorizeS();//����������� ��������
};

//����� ��������
class parent {
private:
	map<string, pair<string, string>> parents; // ����� -> (������, ���)
	map<string, string> parent_link; // ����� �������� -> ����� ��������
public:
	void loadP(const string&);//�������� ������ ���������
	void registrationP();//����������� ���������
	void saveP(const string&, const string&, const string&, const string&);//���������� ������ ���������
	void authorizeP();//����������� ���������
	bool isStudentLogin(const string&, const string&);//�������� ������� �������� �� �����
};

//�������� ������
class SchoolClass {
private:
	map<string, vector<string>> class_students; // ����� -> ������ ������� ��������
public:
	void addClass(); //���������� ������ 
	void removeClass();//�������� ������ 
	void addStudent();//���������� ������ ������� � �����
	void removeStudent();//�������� ������� �� ������ 
	void printClass();//������ ������������ �������
	void printStudent();//����� �������� ������ 
};

//����� ��� �������
class Time {
private:
	int hour, minute;
public:
	Time();
	void getTime();//���� �������
	string formatTime() const;//�������������� � ��� ������
	void setTime(int h, int m);//���������� 
	bool operator<(const Time& other) const;//���������
};

//����� ��� ����� �� ������� 
class Schedule {
private:
	map<int, pair<Time, Time>> lessons;//����� ����� -> ����� ������, ����� ����� 
public:
	void inputLessons();//���� ������ � ����� ����� 
	void saveToFile(const string&); //���������� � ����� 
	void loadFromFile(const string&);//�������� �����
	void printall();//����� ���� ������
	void clearFile();//������� ����� �����
};

//����� ��� ��������� 
class SubjectManager {
private:
	const vector<int> grades = { 1, 2, 3, 4 }; // �������������� ������
	string getFilename(int grade) const; // ��������� ����� ����� ��� ������
	bool subjectExists(const vector<string>& subjects, const string& subject) const; // �������� ������������� �������� � ������
public:
	void addSubject(int grade, const string& subject); // �������� ������� ��� ������
	void showSubjects(int grade) const;    // �������� ��� �������� ������
	vector<string> getSubjects(int grade) const; // �������� ������ ��������� ������
	void removeSubject(int grade, const string& subject); // ������� ������� �� ������
};

//����� ���������� 
class ScheduleManager :public Schedule {
private:
	string className;
	vector<vector<string>> schedule;
	bool fileContains(const string& filename, const string& value) const; //�������� �����
public:
	ScheduleManager() = default; //�����������
	bool setClass(const string& cls); //�������� ������� ������
	bool validateSubject(const string& subject) const; //�������� ��������� 
	void addDay(int day, const vector<string>& lessons); //��� ������
	void saveToFile() const; //���������� � ���� 
	void loadFromFile(const string& cls);//�������� �� �����
	bool deleteClassSchedule(); //������� ����� � ����������
	void printSchedule() const;//����� ���������� ������ �� ������� ������������
	void printSchedule1(string&) const;//����� � ������������� �������
};

//����� ��� ������������ ���������� 
class ScheduleBuilder {
private:
	ScheduleManager manager; // ��������������� ����������
public:
	void createNewSchedule(); //��� ������������ ���������� 
};

// ����� ��� ����
class Date {  
private:
	int day;
	int month;
	int year;
public:
	void getdate(string&); // ���� ���� 
	void putdate(string&); // ����� ���� 
};

//����� ������
class Journal {
private:
	int grade; 
	string nameFile;
	string date;
public:
	void addGrade(string&); // �������� ������ �������
	void showJournal(string&); //�������� ��p��� 
};

