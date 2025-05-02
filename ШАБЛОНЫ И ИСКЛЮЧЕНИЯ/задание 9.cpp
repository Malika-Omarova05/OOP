/*Измените программу из предыдущего упражнения таким образом, чтобы 
в сообщение об ошибке входила информация о значении индекса, привед- 
шего к сбою. */
#include <iostream>
#include <stdexcept>
#include <sstream> 
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
            ostringstream oss;
            oss << "Ошибочный индекс: " << index << " (допустимый диапазон: " << l << " - " << u << ")";
            throw out_of_range(oss.str());
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
