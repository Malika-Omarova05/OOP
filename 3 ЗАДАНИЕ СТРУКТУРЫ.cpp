/*Создайте структуру с именем Volume, содержащую три поля типа Distance 
из примера englstrc, для хранения трех измерений помещения. Определи- 
те переменную типа Volume, инициализируйте ее, вычислите объем, зани- 
маемый помещением, и выведите результат на экран. Для подсчета объема 
переведите каждое из значений типа Distance в значение типа float, равное 
соответствующей длине в футах и хранимое в отдельной переменной. За- 
тем для вычисления объема следует перемножить три полученные веще- 
ственные переменные. */
#include <iostream>
using namespace std;

struct distancee {
    int feet;
    float inches;;
};

struct volume {
    distancee a;
    distancee b;
    distancee c;
};
int main()
{
    setlocale(LC_ALL, "rus");
    volume a1;
    cout << "Введите длину комнаты:" << endl;
    cout << "футы : "; cin >> a1.a.feet;
    cout << "дюймы : "; cin >> a1.a.inches;
    cout << "Введите ширину комнаты: " << endl;
    cout << "футы : "; cin >> a1.b.feet;
    cout << "дюймы: "; cin >> a1.b.inches;
    cout << "Введите высоту комнаты: " << endl;
    cout << "футы : "; cin >> a1.c.feet;
    cout << "дюймы : "; cin >> a1.c.inches;

    float aa = a1.a.feet + a1.a.inches / 12;
    float bb = a1.b.feet + a1.b.inches / 12;
    float cc = a1.c.feet + a1.c.inches / 12;

    cout << "Объем комнаты равно " << aa * bb * cc << " кубических футов";
    return 0;
}
