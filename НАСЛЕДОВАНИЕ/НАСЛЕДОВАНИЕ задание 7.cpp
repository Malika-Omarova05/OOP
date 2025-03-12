/*Вспомним программу COUNTEN2 из этой главы. В ней можно увеличивать и уменьшать счетчик, используя префиксные 
операции. Используя наследование, добавьте возможность использования постфиксных операций для случаев увеличения 
и уменьшения. (Описание постфиксных операций вы сможете найти в главе 8. */
#include <iostream>
using namespace std;
class counter {
protected:
	unsigned int count;
public:
	counter() :count() {}
	counter(int c) :count(c) {}
	unsigned int getcount() const { return count; }
	counter operator++() { return counter(++count); }
	counter operator++ (int) { return counter(count++); }
};
class countdn :public counter {
public:
	countdn() :counter() {}
	countdn(int c) :counter(c) {}
	countdn operator--() { return countdn(--count); }
	countdn operator--(int) { return countdn(count--); }
};
int main() {
	setlocale(LC_ALL, "rus");
	countdn c1(1);
	countdn c2(100);
	cout << "Начальные значения:";
	cout << "\nc1 = " << c1.getcount();
	cout << "\nc2 = " << c2.getcount();
	++c1; ++c1; ++c1;
	cout << "\nc1 после префиксного инкремента = " << c1.getcount();
	c2--; c2--;
	cout << "\nc2 после постфиксного декремента = " << c2.getcount();
	c1++;
	cout << "\nc1 после постфиксного инкремента = " << c1.getcount();
	--c2; --c2;
	cout << "\nc2 после префиксного декремента = " << c2.getcount();
	cout << endl;
	return 0;
}
