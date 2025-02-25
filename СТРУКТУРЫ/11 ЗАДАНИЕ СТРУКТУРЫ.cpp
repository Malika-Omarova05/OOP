/* Используя структуру time из упражнения 9, напишите программу, кото- 
рая получает от пользователя два значения времени в формате 12:59:59, 
сохраняет их в переменных типа struct time, затем переводит оба значения 
в секунды, складывает их, переводит сумму в исходный формат, сохраня- 
ет его в переменной типа time и выводит полученный результат на экран 
в формате 12:59:59. */
#include <iostream>
using namespace std;
struct timee {
	int hours;
	int minutes;
	int seconds;
};
int main() {
	setlocale(LC_ALL, "rus");
	timee t1, t2;
	do {
		cout << "Введите часы: ";
		cin >> t1.hours;
	} while (t1.hours >= 12 || t1.hours <= 0);
	do {
		cout << "Введите минуты: ";
		cin >> t1.minutes;
	} while (t1.minutes >= 60 || t1.minutes <= 0);
	do {
		cout << "Введите секунды: ";
		cin >> t1.seconds;
	} while (t1.seconds >= 60 || t1.seconds <= 0);
	do {
		cout << "\nВведите часы: ";
		cin >> t2.hours;
	} while (t2.hours >= 12 || t2.hours <= 0);
	do {
		cout << "Введите минуты: ";
		cin >> t2.minutes;
	} while (t2.minutes >= 60 || t2.minutes <= 0);
	do {
		cout << "Введите секунды: ";
		cin >> t2.seconds;
	} while (t2.seconds >= 60 || t2.seconds <= 0);
	long totalsecs1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	long totalsecs2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	long totalsecs3 = totalsecs1 + totalsecs2;
	if (totalsecs3 > 12 * 3600) {
		totalsecs3 - (12 * 3600);
	}
	cout << "Всего в секундах = " << totalsecs3;
	cout << "\nФормат: " << (totalsecs3 / 3600 < 10 ? "0" : "") << totalsecs3 / 3600 << ":"
		<< ((totalsecs3 % 3600) / 60 < 10 ? "0" : "") << (totalsecs3 % 3600) / 60 << ":"
		<< (totalsecs3 % 3600 % 60 < 10 ? "0" : "") << (totalsecs3 % 3600 % 60);
	return 0;
}
