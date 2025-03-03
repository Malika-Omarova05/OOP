/* Матрица — это двумерный массив. Создайте класс matrix, который предоставляет те же меры безопасности, как и класс из упражнения 7, то есть 
осуществляет проверку индексов массива на вхождение их в границы массива. Полем класса matrix будет массив 10 на 10. Конструктор должен 
позволять программисту определить реальный размер массива (допустим, сделать его меньше, чем 10 на 10). Методам, предназначенным для досту- 
па к членам матрицы, теперь нужны два индекса: по одному для каждой размерности массива. Вот фрагмент функции main(), которая работает с 
таким классом. */
#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
const int LIMIT = 10;
class safearay {
private:
    int arr[LIMIT][LIMIT];
    int rows, cols;
public:
    safearay(int r, int c) {
        if (r > LIMIT || c > LIMIT || r <= 0 || c <= 0) {
            cout << "Неверный размер матрицы\n";
            exit(1);
        }
        rows = r;
        cols = c;
    }

    void putel(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Индекс вне допустимого диапазона\n";
            return;
        }
        arr[r][c] = value;
    }

    int getel(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Индекс вне допустимого диапазона\n";
            return -1; 
        }
        return arr[r][c];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "M[" << i << "][" << j << "]=" << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    safearay array(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array.putel(i, j, rand() % 100);
        }
    }

    cout << "Сгенерированный массив:" << endl;
    array.print();

    int ind, ind1;
    cout << "Введите индексы, значение которого хотите узнать (строка, столбец): ";
    cin >> ind >> ind1;
    cout << "M[" << ind << "][" << ind1 << "] = " << array.getel(ind, ind1) << endl;

    return 0;
}
