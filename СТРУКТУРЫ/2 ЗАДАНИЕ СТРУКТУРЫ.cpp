﻿/*  Расположение точки на плоскости можно задать с помощью двух координат: x и y. Например, если
точка имеет координаты (4, 5), то это значит, что она отстоит на 4 единицы справа от вертикальной 
оси и на 5 единиц вверх от горизонтальной оси. Сумма двух точек определяется как точка, имеющая 
координаты, равные сумме соответствующих координат слагаемых. Напишите программу, использующую для 
интерпретации точки на плоскости структуру с названием point. Определите три переменные типа point, 
и две из них инициализируйте с помощью значений, вводимых с клавиатуры. Затем присвойте третьей
переменной значение суммы первых двух переменных и выведите результат на экран. Результат работы программы 
может выглядеть следующим образом: 
Введите координаты точки p1: 3 4 
Введите координаты точки p2: 5 7 
Координаты точки p1 + p2 равны 8.11 */
#include <iostream>
using namespace std;

struct point {
    int x;
    int y;
    int sum;
};
int main()
{
    setlocale(LC_ALL, "rus");
    point p1, p2;
    cout << "Введите координаты первой точки p1: "; cin >> p1.x >> p1.y;
    cout << "Введите координаты второй точки p2: "; cin >> p2.x >> p2.y;
    cout << "Координаты точки p1 + p2 равны " << p1.x + p2.x << " " << p2.x + p2.y;
    return 0;
}
