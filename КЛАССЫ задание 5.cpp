/*Взяв в качестве основы структуру из упражнения 5 главы 4, создайте класс date. Его данные должны размещаться в трех полях типа int: month, 
day и year. Метод класса getdate() должен принимать значение для объекта в формате 12/31/2002, а метод showdate() — выводить данные на экран.*/
#include <iostream>
using namespace std;
class timee {
private:
	int day;
	int month;
	int year;
public:
	timee() :day(0), month(0), year(0) {}
	timee(int d, int m, int y) :day(d), month(m), year(y) {}
	void getdata() {
		cout << "Введите день: "; cin >> day;
		cout << "Введите месяц: "; cin >> month;
		cout << "Введите год: "; cin >> year;
	}
	void print() {
		cout << (month < 10 ? "0" : "") << month << "/"
			<< (day < 10 ? "0" : "") << day << "/"
			<< year << endl;
	}
};
int main() {
	setlocale(LC_ALL, "rus");
	timee t;
	t.getdata();
	cout << "Дата: "; t.print();
	return 0;
}