/*Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов данных выводят их внутреннее представление 
в виде целых чисел. Для того чтобы преодолеть это ограничение, вы можете использовать конструкцию switch, с помощью которой устанавлива- 
ется соответствие между значением переменной перечисляемого типа и ее внутренним представлением. Пусть, например, в программе определен пе- 
речисляемый тип данных etype, отражающий должность сотрудника: enum etype { laborer, secretary, manager, accountant, executive, researcher }; 
Напишите программу, которая сначала по первой букве должности, введенной пользователем, определяет соответствующее значение переменной, по- 
мещает это значение в переменную типа etype, а затем выводит полностью название должности, первую букву которой ввел пользователь. Взаимодей- 
ствие программы с пользователем может выглядеть следующим образом: 
Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher); a полное название должности: accountant 
Возможно, вам понадобится два ветвления switch: одно — для ввода значения, другое — для вывода. */
#include <iostream>
using namespace std;
enum etype { laborer, secretary, manager, accountant, executive, researcher };
int main()
{
	setlocale(LC_ALL, "rus");
	etype employee;
	char x;
	while (true) {
		cout << "Введите первую букву должности: "; cin >> x;
		switch (x) {
		case 'l': employee = laborer; break;
		case 's': employee = secretary; break;
		case 'm': employee = manager; break;
		case 'a': employee = accountant; break;
		case 'e': employee = executive; break;
		case 'r': employee = researcher; break;
		}
		cout << "Должность: ";
		switch (employee) {
		case laborer: cout << "laborer"; break;
		case secretary: cout << "secretary"; break;
		case manager: cout << "manager"; break;
		case accountant: cout << "accountant"; break;
		case executive: cout << "executive"; break;
		case researcher: cout << "researcher"; break;
		}
		cout << "\nПродолжить? 1 - да, 0 - нет " << endl;
		int a;
		cin >> a;
		if (a == 0) return 0;
	}
}
