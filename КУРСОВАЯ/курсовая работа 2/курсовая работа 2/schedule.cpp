#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "header.h"
using namespace std;

//������������ ��� ������ ������� 
Time::Time() : hour(0), minute(0) {}

//���� ��������
void Time::getTime() {
	cin >> hour >> minute;
}

//�������������� � ��� ������
string Time::formatTime() const {
	stringstream ss;
	ss << setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute;
	return ss.str();
}

//����������
void Time::setTime(int h, int m) {
	hour = h;
	minute = m;
}

//���������
bool Time::operator<(const Time& other) const {
	if (hour == other.hour) return minute < other.minute;
	return hour < other.hour;
}

//���� ������ � ����� ����� 
void Schedule::inputLessons() {
    int lessonNumber = 1;
    while (true) {
        Time start, end;
        cout << "������� ����� ������ ����� " << lessonNumber << " (���� ������), ��� -1 ��� ����������: ";
        int h, m;
        cin >> h;
        if (h == -1) break;
        cin >> m;
        start.setTime(h, m);

        cout << "������� ����� ��������� ����� " << lessonNumber << " (���� ������): ";
        cin >> h >> m;
        end.setTime(h, m);

        lessons[lessonNumber] = { start, end };
        lessonNumber++;
    }
    saveToFile("time.txt");
}

//���������� � ����� 
void Schedule::saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    for (const auto& lesson : lessons) {
        file << lesson.first << " "
            << lesson.second.first.formatTime() << "-"
            << lesson.second.second.formatTime() << endl;
    }
    file.close();
}

//�������� ����� 
void Schedule::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }

    lessons.clear();
    string line;
    while (getline(file, line)) {
        size_t space_pos = line.find(' ');
        if (space_pos == string::npos) continue;

        int lessonNumber = stoi(line.substr(0, space_pos));
        string timeStr = line.substr(space_pos + 1);

        size_t dash_pos = timeStr.find('-');
        if (dash_pos == string::npos) continue;

        string startStr = timeStr.substr(0, dash_pos);
        string endStr = timeStr.substr(dash_pos + 1);

        Time start, end;

        // ������ ����� ������
        size_t colon_pos = startStr.find(':');
        if (colon_pos != string::npos) {
            int h = stoi(startStr.substr(0, colon_pos));
            int m = stoi(startStr.substr(colon_pos + 1));
            start.setTime(h, m);
        }

        // ������ ����� ���������
        colon_pos = endStr.find(':');
        if (colon_pos != string::npos) {
            int h = stoi(endStr.substr(0, colon_pos));
            int m = stoi(endStr.substr(colon_pos + 1));
            end.setTime(h, m);
        }

        lessons[lessonNumber] = { start, end };
    }
    file.close();
}


//����� ���� ������
void Schedule::printall() {
    if (lessons.empty()) {
        cout << "���������� ������ ������!" << endl;
        return;
    }

    // ������� ������ ��� ���������� ������ �� ������� ������
    vector<pair<int, pair<Time, Time>>> sorted(lessons.begin(), lessons.end());

    // ��������� �� ������� ������ �����
    sort(sorted.begin(), sorted.end(),
        [](const auto& a, const auto& b) {
            return a.second.first < b.second.first;
        });

    cout << "\n��� ����� �� ������� �������:\n";
    for (const auto& lesson : sorted) {
        cout << "���� " << lesson.first << ": "
            << lesson.second.first.formatTime() << "-"
            << lesson.second.second.formatTime() << endl;
    }
}

//������� ����� �����
void Schedule::clearFile() {
    ofstream file("time.txt", ios::trunc); 
    if (!file.is_open()) {
        cerr << "������: �� ������� ������� ����!" << endl;
        return;
    }
    file.close();
    cout << "����� �������!" << endl;
}

// ��������� ����� ����� ��� ������
string SubjectManager::getFilename(int grade) const {
    return "class_" + to_string(grade) + "_subjects.txt";
}

// �������� ������������� �������� � ������
bool SubjectManager::subjectExists(const vector<string>& subjects, const string& subject) const {
    return find(subjects.begin(), subjects.end(), subject) != subjects.end();
}

// �������� ������� ��� ������
void SubjectManager::addSubject(int grade, const string& subject) {
    if (find(grades.begin(), grades.end(), grade) == grades.end()) {
        cout << "������: ����� ��������� �������� ������ ��� 1-4 �������\n";
        return;
    }
    vector<string> subjects = getSubjects(grade);
    if (subjectExists(subjects, subject)) {
        cout << "������� '" << subject << "' ��� ���� � " << grade << " ������\n";
        return;
    }
    ofstream file(getFilename(grade), ios::app);
    if (file.is_open()) {
        file << subject << endl;
        cout << "������� '" << subject << "' �������� � " << grade << " �����\n";
    }
    else {
        cout << "������ ��� �������� ����� ��� ������\n";
    }
}

// �������� ��� �������� ������
void SubjectManager::showSubjects(int grade) const {
    vector<string> subjects = getSubjects(grade);
    cout << "�������� " << grade << " ������:\n";
    for (const auto& subject : subjects) {
        cout << "- " << subject << endl;
    }
}

// �������� ������ ��������� ������
vector<string> SubjectManager::getSubjects(int grade) const {
    vector<string> subjects;
    ifstream file(getFilename(grade));

    if (file.is_open()) {
        string subject;
        while (getline(file, subject)) {
            if (!subject.empty()) {
                subjects.push_back(subject);
            }
        }
    }
    return subjects;
}


// ������� ������� �� ������
void SubjectManager::removeSubject(int grade, const string& subject) {
    vector<string> subjects = getSubjects(grade);
    auto it = find(subjects.begin(), subjects.end(), subject);

    if (it == subjects.end()) {
        cout << "������� '" << subject << "' �� ������ � " << grade << " ������\n";
        return;
    }

    subjects.erase(it);

    ofstream file(getFilename(grade));
    if (file.is_open()) {
        for (const auto& subj : subjects) {
            file << subj << endl;
        }
        cout << "������� '" << subject << "' ������ �� " << grade << " ������\n";
    }
    else {
        cout << "������ ��� �������� ����� ��� ������\n";
    }
}