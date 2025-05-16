/* Заполните массив четными числами, а множество — нечетными. С помо- 
щью алгоритма merge() объедините эти контейнеры в вектор. Выведите 
его содержимое, чтобы удостовериться, что слияние прошло успешно. */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    vector<int> num2 = { 2, 4, 6, 8, 10 };
    set<int> num1 = { 1, 3, 5, 7, 9 };

    vector<int> numbers(num2.size() + num1.size());

    merge(num2.begin(), num2.end(),
        num1.begin(), num1.end(),
        numbers.begin());

    cout << "Объединенный список: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
