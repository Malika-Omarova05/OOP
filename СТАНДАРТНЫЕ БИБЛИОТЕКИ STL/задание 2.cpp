/*Примените алгоритм sort() к массиву слов, введенных пользователем, выведите результат. 
Используйте push_back() для добавления слов, а оператор [] и size() — для вывода их на экран.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include  <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> words;
    string word;

    cout << "Введите слова (для завершения введите 'end'):" << endl;
    while (true) {
        cin >> word;
        if (word == "end") break;
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    cout << "Отсортированные слова:" << endl;
    for (size_t i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}

