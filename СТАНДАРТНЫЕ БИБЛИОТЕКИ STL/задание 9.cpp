/*В табл. 15.10 мы привели все предопределенные функциональные объек- 
ты C++. В программе PLUSAIR показали, как применять функциональ- 
ный объект plus<>() с алгоритмом accumulate(). В том примере не было 
необходимости в передаче каких-либо аргументов в функциональный 
объект, но иногда по логике работы программы это требуется. Оказывает- 
ся, в данном случае нельзя просто указать аргумент в скобках, как мы 
привыкли делать. Вместо этого нужно использовать специальный «адап- 
тер функции», называющийся bind1dt или bind2nd, для связывания аргу- 
мента с функциональным объектом. Пусть, например, мы ищем строку 
SearchName в строковом контейнере names. В этом случае необходимо 
писать такое выражение: 
ptr = find_if(names.begin(), names.end(), bind2nd(equal_to<string>(), SearchName));*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> names = { "Малика", "Айжамал", "Жоомарт", "Бека", "Куба" };
    string SearchName;
    cout << "Введите имя, которое ищите: "; cin >> SearchName;

    auto it = find_if(names.begin(), names.end(), bind(equal_to<string>(), placeholders::_1, SearchName));

    if (it != names.end()) {
        cout << "Найдено: " << *it << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }

    return 0;
}
