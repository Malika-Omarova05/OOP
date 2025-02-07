/*Создайте структуру с именем employee, содержащую два поля: номер со- 
трудника типа int и величину его пособия в долларах типа float. Запроси- 
те с клавиатуры данные о трех сотрудниках, сохраните их в трех струк- 
турных переменных типа employee и выведите информацию о каждом из 
сотрудников на экран. */
#include <iostream>
using namespace std;

struct employee {
    int sot;
    float pos;
};
int main()
{
    setlocale(LC_ALL, "rus");
    employee x1, x2, x3;
    x1 = { 1, 20.5 };
    x2 = { 2, 16.3 };
    x3 = { 3, 18.9 };
    int n;
    cout << "Выберите сотрудника (1, 2, 3): "; cin >> n;
    switch (n)
    {
    case 1: cout << "№" << x1.sot << " размер пособия = " << x1.pos;
        break;
    case 2: cout << "№" << x2.sot << " размер пособия = " << x2.pos;
        break;
    case 3: cout << "№" << x3.sot << " размер пособия = " << x3.pos;
        break;
    default:
        cout << "Неправильный ввод! "; cin >> n;
        break;
    }
    return 0;
}

