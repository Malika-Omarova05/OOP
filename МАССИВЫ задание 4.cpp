/*Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять их в массиве типа int. Напишите функцию maxint(), 
которая, обрабатывая элементы массива один за другим, находит наибольший. Функция должна принимать в качестве аргумента адрес массива и 
количество элементов в нем, а возвращать индекс наибольшего элемента. Программа должна вызвать эту функцию, а затем вывести наибольший 
элемент и его индекс. (Смотрите программу SALES этой главы.) */
#include <iostream>
#include <windows.h>
using namespace std;

int maxint(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX = 100;
    int arr[MAX];
    int n;
    link:
    cout << "Сколько целых чисел вы хотите ввести (макс 100)? ";
    cin >> n;
    if (n > MAX) {
        cout << "Можно ввести не более 100 чисел." << endl;
        goto link;
    }
    for (int i = 0; i < n; i++) {
        cout << "Введите целое число #" << i << ": ";
        cin >> arr[i];
    }
    int maxIndex = maxint(arr, n);
    cout << "Наибольшее число: " << arr[maxIndex] << ", его индекс: " << maxIndex << endl;
    return 0;
}
