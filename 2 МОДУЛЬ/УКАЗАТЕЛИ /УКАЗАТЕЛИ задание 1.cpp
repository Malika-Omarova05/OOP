/*Напишите программу, которая принимает группу чисел от пользователя и 
помещает их в массив типа float. После того как числа будут помещены в 
массив, программа должна подсчитать их среднее арифметическое и вывес- 
ти результат на дисплей. Используйте указатели везде, где только возможно. */
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(0);
	int n;
	cout << "Введите количество чисел: ";
	cin >> n;
	float* arr = new float[n];
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}
	cout << "Массив А:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "]=" << *(arr + i) << "\t";
	}
	float sum = 0; int count = 0;
	for (int i = 0; i < n; i++) {
		sum += *(arr + i);
		count++;
	}
	float avg = sum / count;
	cout << "\nСреднее арифметическое = " << avg;
	return 0;
}
