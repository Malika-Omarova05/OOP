/*Модифицируйте программу, описанную в упражнении 11 главы 4 «Струк- 
туры», складывающую два структурных значения типа time. Теперь про- 
грамма должна включать в себя две функции. Первая, time_to_secs(), при- 
нимает в качестве аргумента значение типа time и возвращает эквивалентное 
значение в секундах типа long. Вторая, secs_to_time(), в качестве аргумента 
принимает число секунд, имеющее тип long, а возвращает эквивалентное 
значение типа time. */
#include <iostream>
using namespace std;
struct timee {
	int hour;
	int min;
	int sec;
};
long to_sec(timee);
timee to_time(long);
int main() {
	setlocale(LC_ALL, "rus");
	timee a; long second;
	do {
		cout << "Введите часы: "; cin >> a.hour;
	} while (a.hour > 24 || a.hour < 0);
	do {
		cout << "Введите минуты: "; cin >> a.min;
	} while (a.min > 60 || a.min < 0);
	do {
		cout << "Введите секунды: "; cin >> a.sec;
	} while (a.sec > 60 || a.sec < 0);
	cout << "Время в секундах: " << to_sec(a) << endl;
	cout << "Введите время в секундах: "; cin >> second;
	timee b = to_time(second);
	cout << second << " секунд = " << b.hour << ":" << b.min << ":" << b.sec;
}
long to_sec(timee t) {
	long a = t.hour * 3600 + t.min * 60 + t.sec;
	return a;
}
timee to_time(long ss) {
	timee x;
	x.hour = ss / 3600;
	x.min = (ss % 3600) / 60;
	x.sec = (ss % 3600) % 60;
	return x;
}