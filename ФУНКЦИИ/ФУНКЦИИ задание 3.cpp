/*Напишите функцию с именем zeroSmaller(), в которую передаются с по- 
мощью ссылок два аргумента типа int, присваивающую меньшему из ар- 
гументов нулевое значение. Напишите программу для проверки работы 
функции. */
#include <iostream>
using namespace std;
void zerosmaller(int&, int&);
int main() {
	setlocale(LC_ALL, "rus");
	int a, b;
	cout << "Введите первое число: "; cin >> a;
	cout << "Введите второе число: "; cin >> b;
	cout << "Результат: "; zerosmaller(a, b);
	return 0;
}
void zerosmaller(int& aa, int& bb) {
	if (aa > bb) {
		bb = 0; cout << aa << " " << bb;
	}
	else if (aa < bb) {
		aa = 0; cout << aa << " " << bb;
	}
	else cout << "Оба числа равны!";
}
