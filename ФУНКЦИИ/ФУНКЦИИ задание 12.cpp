/*Модифицируйте калькулятор, созданный в упражнении 12 главы 4, так, 
чтобы каждая арифметическая операция выполнялась с помощью функ- 
ции. Функции могут называться fadd(), fsub(), fmul() и fdiv(). Каждая из 
функций должна принимать два структурных аргумента типа fraction и воз- 
вращать значение того же типа.*/
#include <iostream>
using namespace std;
struct fraction {
	int chis;
	int znam;
};
fraction fadd(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fdiv(fraction, fraction);
void print(fraction);
int main() {
	setlocale(LC_ALL, "rus");
	fraction f1, f2, result;
	char x;
	cout << "Введите первую дробь:" << endl;
	cin >> f1.chis;
	cout << endl << "-" << endl;
	cin >> f1.znam;
	cout << "Введите вторую дробь:" << endl;
	cin >> f2.chis;
	cout << endl << "-" << endl;
	cin >> f2.znam;
	while (true) {
		cout << "Выберите действие (+, -, /, *): ";
		cin >> x;
		switch (x) {
		case '+': result = fadd(f1, f2); break;
		case '-': result = fsub(f1, f2); break;
		case '*': result = fmul(f1, f2); break;
		case '/': result = fdiv(f1, f2); break;
		default: cout << "Неверный оператор!" << endl; return 1;
		}
		cout << "Результат = "; print(result);
		int y;
		cout << "\nПродолжить? 0 - нет "; cin >> y;
		if (y == 0) return 0;
	}
	return 0;
}
fraction fadd(fraction a, fraction b) {
	fraction c;
	c.chis = a.chis * b.znam + b.chis * a.znam;
	c.znam = a.znam * b.znam;
	return c;
}
fraction fsub(fraction a, fraction b) {
	fraction c;
	c.chis = a.chis * b.znam - b.chis * a.znam;
	c.znam = a.znam * b.znam;
	return c;
}
fraction fmul(fraction a, fraction b) {
	fraction c;
	c.chis = a.chis * b.chis;
	c.znam = a.znam * b.znam;
	return c;
}
fraction fdiv(fraction a, fraction b) {
	fraction c;
	c.chis = a.chis * b.znam;
	c.znam = a.znam * b.chis;
	return c;
}
void print(fraction c) {
	cout << c.chis << "/" << c.znam;
}
