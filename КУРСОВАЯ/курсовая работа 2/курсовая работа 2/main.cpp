#include <iostream>
#include <Windows.h>
#include <string>
#include "header.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ch;
	administrator admin;
	teacher tea;
	tea.loadT("teacherLogin.txt");
	student st;
	st.loadS("studentLogin.txt");
	parent par;
	par.loadP("parentLogin.txt");
	while (true) {
		cout << "--------------------------------------------" << endl
			<< "Выберите в качестве кого вы хотите зайти?" << endl //выбор роли
			<< "1 - администратор " << endl
			<< "2 - учитель " << endl
			<< "3 - ученик " << endl
			<< "4 - родитель " << endl
			<< "--------------------------------------------" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			if (admin.authorizationA() == true) {
				cout << "Добро пожаловать, Администратор!" << endl;
				admin.adminMenu();
			}
			break;
		case 2:
			tea.authorizeT();				
			break;
		case 3:
			st.authorizeS();
			break;
		case 4:
			par.authorizeP();
			break;
		default: cout << "Некорректный выбор. Попробуйте снова.\n"; break;
		}
	}
}