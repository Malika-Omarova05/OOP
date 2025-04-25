#include <iostream>
#include "elev.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    Elevator elevator;
    char moreRequests;
    do {
        elevator.addRequest(); 
        cout << "Хотите добавить еще запрос? (y/n): ";
        cin >> moreRequests;
    } while (moreRequests == 'y');

    cout << "\nОбработка запросов..." << endl;
    elevator.processRequests();
    cout << "Все запросы выполнены!" << endl;
    return 0;
}
