/* Создайте класс Int, имитирующий стандартный тип int. Единственное поле этого класса должно иметь тип int. Создайте методы, которые будут 
устанавливать значение поля, равным нулю, инициализировать его целым значением, выводить значение поля на экран и складывать два значения 
типа Int. Напишите программу, в которой будут созданы три объекта класса Int, два из которых будут инициализированы. Сложите два инициализирован- 
ных объекта, присвойте результат третьему, а затем отобразите результат  на экране. */
#include<iostream>
using namespace std;
class Int {
private:
	int val;
public:
	Int() :val(0) {}
	Int(int x) :val(x) {}
	void func1() { val = 0; }
	void func2(int x) { val = x; }
	void print() {
		cout << val << endl;
	}
	Int plus(const Int& n) {
		return Int(val + n.val);
	}
};
int main() {
	setlocale(LC_ALL, "rus");
	Int num1(100), num2(150), num3;
	num3 = num1.plus(num2);
	cout << "Первое слагаемое = ";  num1.print();
	cout << "Второе слагаемое = "; num2.print();
	cout << "Pезультат = "; num3.print();
	return 0;
}
