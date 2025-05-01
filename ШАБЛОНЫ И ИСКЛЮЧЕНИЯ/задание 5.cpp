/*Создайте функцию amax(), возвращающую значение максимального эле- 
мента массива. Аргументами функции должны быть адрес и размер мас- 
сива. Сделайте из функции шаблон, чтобы она могла работать с массивом 
любого числового типа. Напишите секцию main(), в которой проверьте 
работу функции с разными типами массивов. */
#include <iostream>
#include <cstdlib>
using namespace std;

template <class mlk>
class maximum {
private:
	int size;
	mlk *arr;
public:
	maximum(int n) :size(n) {
		arr = new mlk[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 30;
	}
	~maximum() { delete[]arr; }
	
	void putdata()const {
		for (int i = 0; i < size; i++) {
			cout << "arr[" << i << "]=" << arr[i] << "\t";
		}
		cout << endl;
	}
	void amax() {
		mlk max = arr[0]; int n = 0;
		for (int i = 0; i < size; i++) {
			if (max < arr[i]) {
				max = arr[i];
				n = i;
			}
		}
		cout << "Максимальный элемент в массиве: " << max << endl;
	}
};

int main() {
	setlocale(LC_ALL, "rus"); 
	int x; 

	cout << "Тип данных int:" << endl;
	cout << "Введите количество элементов в массиве: "; cin >> x;
	maximum <int> i(x);
	i.putdata(); i.amax();

	cout << "\nТип данных double:" << endl;
	cout << "Введите количество элементов в массиве: "; cin >> x;
	maximum <double> d(x);
	d.putdata(); d.amax();

	cout << "\nТип данных char:" << endl;
	cout << "Введите количество элементов в массиве: "; cin >> x;
	maximum <char> c(x);
	c.putdata(); c.amax();
	return 0;
}
