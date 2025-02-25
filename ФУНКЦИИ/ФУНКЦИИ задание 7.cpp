/* Взяв в качестве основы функцию power() из упражнения 2, работающую 
только со значением типа double, создайте перегруженные функции с этим 
же именем, принимающими в качестве аргумента значения типа char, int, 
long и float. Напишите программу, вызывающую функцию power() со все- 
ми возможными типами аргументов. */
#include <iostream>
using namespace std;
long power(int, int = 2);
long power(long, int = 2);
double power(float, int = 2);
double power(double, int = 2);
long power(char, int = 2);
int main() {
	setlocale(LC_ALL, "rus");
	int n1, a, x;
	long n2;
	float n3;
	double n4;
	char n5;
	cout << "Введите число (int): "; cin >> n1;
	cout << "Вводить степень ? 1 - да "; cin >> x;
	if (x == 1) {
		cout << "Введите степень: "; cin >> a;
		cout << n1 << " ^ " << a << " = " << power(n1, a);
	}
	else cout << n1 << " ^ " << 2 << " = " << power(n1);

	cout << "\nВведите число (long): "; cin >> n2;
	cout << "Вводить степень ? 1 - да "; cin >> x;
	if (x == 1) {
		cout << "Введите степень: "; cin >> a;
		cout << n2 << " ^ " << a << " = " << power(n2, a);
	}
	else cout << n2 << " ^ " << 2 << " = " << power(n2);

	cout << "\nВведите число (float): "; cin >> n3;
	cout << "Вводить степень ? 1 - да "; cin >> x;
	if (x == 1) {
		cout << "Введите степень: "; cin >> a;
		cout << n3 << " ^ " << a << " = " << power(n3, a);
	}
	else cout << n3 << " ^ " << 2 << " = " << power(n3);

	cout << "\nВведите число (double): "; cin >> n4;
	cout << "Вводить степень ? 1 - да "; cin >> x;
	if (x == 1) {
		cout << "Введите степень: "; cin >> a;
		cout << n4 << " ^ " << a << " = " << power(n4, a);
	}
	else cout << n4 << " ^ " << 2 << " = " << power(n4);

	cout << "\nВведите символ (char): "; cin >> n5;
	cout << "Вводить степень ? 1 - да "; cin >> x;
	if (x == 1) {
		cout << "Введите степень: "; cin >> a;
		cout << n5 << " ^ " << a << " = " << power(n5, a);
	}
	else cout << n5 << " ^ " << 2 << " = " << power(n5);
}
long power(int a, int b) {
	long c = pow(a, b); return c;
}
long power(long a, int b) {
	long c = pow(a, b); return c;
}
double power(float a, int b) {
	double c = pow(a, b); return c;
}
double power(double a, int b) {
	double c = pow(a, b); return c;
}
long power(char a, int b) {
	long c = pow(a, b); return c;
}
