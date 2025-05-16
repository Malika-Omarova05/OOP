/* Здесь аргументами bind2nd, в свою очередь, являются equal_to<>() и Search- 
Name. Это выражение возвращает итератор, указывающий на первую стро- 
ку в контейнере, равную SearchName. Напишите программу, в которой ис- 
пользуется подобное выражение для поиска строки в строковом контейнере. 
На экран должна выводиться позиция SearchName в контейнере. */
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

    cout << "Введите имя для поиска: ";
    cin >> SearchName;
    auto it = find_if(names.begin(), names.end(), [&](const string& s) { return s == SearchName; });

    if (it != names.end()) {
        cout << "Имя '" << SearchName << "' найдено на позиции " << distance(names.begin(), it) << endl;
    }
    else {
        cout << "Имя '" << SearchName << "' не найдено в контейнере." << endl;
    }

    return 0;
}
