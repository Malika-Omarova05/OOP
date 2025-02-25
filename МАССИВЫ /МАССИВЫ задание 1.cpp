  /* Напишите функцию reversit(), которая переворачивает строку (массив типа char). Используйте цикл for, который меняет местами первый и последний 
символы, затем следующие и т. д. до предпоследнего. Строка должна передаваться в функцию reversit() как аргумент. 
Напишите программу для выполнения функции reversit(). Программа должна принимать строку от пользователя, вызывать функцию reversit(), а за- 
тем выводить полученный результат. Используйте метод ввода, который позволяет использовать внутренние пробелы. Протестируйте программу 
на примере фразы «Аргентина манит негра». */
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

void reversit(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX = 2000;
    char str[MAX];
    cout << "Введите строку (закончите ввод символом $):\n";
    cin.get(str, MAX, '$');
    reversit(str);
    cout << "Перевернутая строка: " << str << endl;
    return 0;
}
