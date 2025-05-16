/*Напишите программу, являющуюся примером применения алгоритма sort() к массиву типа float. 
Значения вводятся пользователем, результат работы выводится на экран.*/

#include <iostream> 
#include <algorithm> 
using namespace std;
int main(){
    setlocale(LC_ALL, "rus");
    int j = 0, k;
    char ch;
    float fpn, farr[100];
    do {
        cout << "Введите число в формате с плавающей запятой:";
        cin >> fpn;
        farr[j++] = fpn;
        cout << "Продолжать('y' или 'n'):";
        cin >> ch;
    } while (ch == 'y');
    sort(farr, farr + j);
    for (k = 0; k < j; k++)
        cout << farr[k] << ", ";
    cout << endl;
    return 0;
}