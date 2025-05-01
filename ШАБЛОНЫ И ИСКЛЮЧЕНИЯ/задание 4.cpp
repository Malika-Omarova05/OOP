/*Создайте функцию swaps(), обменивающую значения двух аргументов, по- 
сылаемых ей. (Возможно, вы догадаетесь передавать эти аргументы по 
ссылке.) Сделайте из функции шаблон, чтобы она могла использоваться 
с любыми числовыми типами данных (int, char, float и т. д.). Напишите 
main() для тестирования функции. */
#include <iostream>
using namespace std;

template <typename mlk>
void swaps(mlk& a, mlk& b) {
	mlk temp = a;
	a = b;
	b = temp;
}
int main() {
	setlocale(LC_ALL, "rus");
	
	cout << "Ввод значений для int" << endl;
	int a, b;
	cout << "а = "; cin >> a;
	cout << "b = "; cin >> b;

	swaps(a, b);
	cout << "Новые значения:" << endl;
	cout << "а = " << a << endl;
	cout << "b = " << b << endl;

	cout << "Ввод значений для float" << endl;
	float  a1, b1;
	cout << "а = "; cin >> a1;
	cout << "b = "; cin >> b1;

	swaps(a1, b1);
	cout << "Новые значения:" << endl;
	cout << "а = " << a1 << endl;
	cout << "b = " << b1 << endl;

	cout << "Ввод значений для char" << endl;
	char  a2, b2;
	cout << "а = "; cin >> a2;
	cout << "b = "; cin >> b2;

	swaps(a2, b2);
	cout << "Новые значения:" << endl;
	cout << "а = " << a2 << endl;
	cout << "b = " << b2 << endl;
	
	return 0;
}
