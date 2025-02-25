/*Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа 
int: часы, минуты и секунды. Функция должна возвращать эквивалент пе- 
реданного ей временного значения в секундах (типа long). Создайте про- 
грамму, которая будет циклически запрашивать у пользователя ввод значе- 
ния часов, минут и секунд и выводить результат работы функции на экран. 
*/
#include <iostream>
using namespace std;
long to_sec(int, int, int);
int main() {
	setlocale(LC_ALL, "rus");
	int h, m, s, x;
	while (true) {
		do {
			cout << "Введите часы: "; cin >> h;
		} while (h > 24 || h < 0);
		do {
			cout << "Введите минуты: "; cin >> m;
		} while (m > 60 || m < 0);
		do {
			cout << "Введите секунды: "; cin >> s;
		} while (s > 60 || s < 0);
		cout << "Время в секундах: " << to_sec(h, m, s);
		cout << "\nПродолжить? 0 - нет"; cin >> x;
		if (x == 0)return 0;
	}
}
long to_sec(int hour, int minute, int second) {
	long a = hour * 3600 + minute * 60 + second;
	return a;
}
