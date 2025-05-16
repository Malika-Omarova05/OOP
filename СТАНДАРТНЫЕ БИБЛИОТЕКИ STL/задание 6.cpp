/*В упражнении 3 два обычных итератора использовались для переворачи- 
вания содержимого контейнера. Теперь используйте один прямой и один 
обратный контейнер для выполнения того же задания, на сей раз в приме- 
нении к вектору. */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    vector<int> con1;
    for (int j = 2; j < 16; j += 2) {
        con1.push_back(j);
    }

    cout << "До переворачивания: ";
    for (int num : con1) {
        cout << num << " ";
    }
    vector<int> con2(con1.rbegin(), con1.rend());

    cout << "\nПосле переворачивания: ";
    for (int num : con2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
