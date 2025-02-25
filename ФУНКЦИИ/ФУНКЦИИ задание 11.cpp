/*Напишите программу, использующую структуру sterling, которая описана 
в упражнении 10 главы 4. Программа должна получать от пользователя 
значения двух денежных сумм, выраженных в фунтах, шиллингах и пен- 
сах, складывать эти значения и выводить результат на экран в том же 
формате. Необходимо разработать три функции. Первая из них должна 
получать от пользователя число фунтов, шиллингов и пенсов и возвра- 
щать соответствующее значение типа sterling. Вторая функция должна при- 
нимать в качестве аргументов два значения типа sterling, складывать их и 
возвращать значение, также имеющее тип sterling. Третья функция долж- 
на принимать аргумент типа sterling и выводить его значение на экран. */

/*1 фунт (£) = 20 шиллингов (s)
1 шиллинг = 12 пенсов (d)
1 фунт = 240 пенсов*/

#include <iostream>
using namespace std;
struct sterling {
	int pounds;
	int shillings;
	int pence;
};
sterling func1();
sterling func2(sterling, sterling);
void func3(sterling);
int main() {
	setlocale(LC_ALL, "rus");
	sterling a1, a2, a3;
	cout << "Введите первую сумму: ";
	a1 = func1();
	cout << "Введите вторую сумму: ";
	a2 = func1();
	a3 = func2(a1, a2);
	cout << "Сумма = "; func3(a3);
}
sterling func1() {
	sterling n;
	cout << "Фунты: "; cin >> n.pounds;
	cout << "Шиллинги: "; cin >> n.shillings;
	cout << "Пенсы: "; cin >> n.pence;
	return n;
} 
sterling func2(sterling a, sterling b) {
	sterling s;
	int sum = a.pounds * 240 + a.shillings * 12 + a.pence +
		b.pounds * 240 + b.shillings * 12 + b.pence;
	s.pounds = sum / 240;
	s.shillings = (sum % 240) / 12;
	s.pence = sum % 240 % 12;
	return s;
}
void func3(sterling a) {
	cout << a.pounds << " футов " << a.shillings 
		<< " шиллингов " << a.pence << " пенсов.";
}
