/*Создайте структуру с именем time. Три ее поля, имеющие тип int, будут 
называться hours, minutes и seconds. Напишите программу, которая просит 
пользователя ввести время в формате часы, минуты, секунды. Можно 
запрашивать на ввод как три значения сразу, так и выводить для каж- 
дой величины отдельное приглашение. Программа должна хранить время 
в структурной переменной типа time и выводить количество секунд в вве- 
денном времени, определяемое следующим образом: 
long totalseсs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds */
#include <iostream>
using namespace std;
struct timee {
	int hours;
	int minutes;
	int seconds;
};
int main() {
	setlocale(LC_ALL, "rus");
	timee t1;
	do {
		cout << "Введите часы: ";
		cin >> t1.hours;
	} while (t1.hours >= 24 || t1.hours <= 0);
	do {
		cout << "Введите минуты: ";
		cin >> t1.minutes;
	} while (t1.minutes >= 60 || t1.minutes <= 0);
	do {
		cout << "Введите секунды: ";
		cin >> t1.seconds;
	} while (t1.seconds >= 60 || t1.seconds <= 0);
	long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	cout << "Всего в секундах = " << totalsecs;
	return 0;
}
