/*Предположим, что в функции main() определены три локальных массива 
одинакового размера и типа (скажем, float). Первые два уже инициализи- 
рованы значениями. Напишите функцию addarrays(), которая принимает в 
качестве аргументов адреса грех массивов, складывает соответствующие 
элементы двух массивов и помещает результат в третий массив. Четвертым 
аргументом этой функции может быть размерность массивов. На всем 
протяжении программы используйте указатели. */
#include <iostream>
using namespace std;
void addarrays(const float* arr1, const float* arr2, float* result, int size) {
    for (int i = 0; i < size; i++) {
        *(result + i) = *(arr1 + i) + *(arr2 + i);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    const int SIZE = 5; 
    float array1[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    float array2[SIZE] = { 5.0, 4.0, 3.0, 2.0, 1.0 };
    float result[SIZE]; 
    addarrays(array1, array2, result, SIZE);
    cout << "Первый массив:\n";
    for (int i = 0; i < SIZE; i++)
        cout << *(array1 + i) << " ";
    cout << "\nВторой массив: \n";
    for (int i = 0; i < SIZE; i++)
        cout << *(array2 + i) << " ";
    cout << "\nРезультирующий массив:" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << *(result + i) << " ";
    cout << endl;
    return 0;
}
