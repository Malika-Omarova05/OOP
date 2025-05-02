/*Добавьте класс исключений к программе ARROVER из главы 8, чтобы ин- 
дексы, выходящие за пределы массива, вызывали генерацию исключения. 
Блок-ловушка может выводить пользователю сообщение об ошибке. */
#include <iostream>
#include <stdexcept>
using namespace std;
const int LIMIT = 100;
template <typename mlk>
class SafeArray {
private:
    mlk arr[LIMIT];
    int l;
    int u;
public:
    SafeArray(int lower, int upper) {
        if (upper - lower >= LIMIT || lower >= upper) {
            throw invalid_argument("Некорректные границы массива!");
        }
        l = lower;
        u = upper;
    }
    mlk& operator[](int index) {
        if (index < l || index > u) {
            throw out_of_range("Ошибочный индекс!");
        }
        return arr[index - l];
    }
    int size() const {
        return u - l + 1;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        int v, ni;
        cout << "Введите нижнюю границу массива int: ";
        cin >> v;
        cout << "Введите верхнюю границу массива int: ";
        cin >> ni;
        SafeArray<int> intArray(v, ni);
        for (int i = v; i <= ni; i++)
            intArray[i] = i * 10;
        for (int i = v; i <= ni; i++)
            cout << "Элемент intArray[" << i << "] = " << intArray[i] << endl;
        cout << "Пробуем получить элемент intArray[" << ni + 1 << "]..." << endl;
        cout << intArray[ni + 1] << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
