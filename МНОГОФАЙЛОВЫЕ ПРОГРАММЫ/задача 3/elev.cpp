#include "elev.h"
#include <iostream>
using namespace std;

Elevator::Elevator() : currentFloor(1), direction('u') {}

void Elevator::addRequest() {
    int floor;
    char dir;
    cout << "На каком Вы этаже? (1-20): ";
    cin >> floor;
    if (floor < 1 || floor > 20) {
        cout << "Неверный этаж! Повторите ввод (1-20)." << endl;
        return;
    }
    cout << "В каком направлении вы хотите двигаться? (u - вверх, d - вниз): ";
    cin >> dir;
    if (dir != 'u' && dir != 'd') {
        cout << "Неверное направление! Используйте 'u' или 'd'." << endl;
        return;
    }
    direction = dir;
    if (processedRequests.find(floor) == processedRequests.end()) {
        requests.push(floor);
        processedRequests.insert(floor);
        cout << "Запрос добавлен на этаж " << floor << "." << endl;
    }
    else {
        cout << "Запрос на этаж " << floor << " уже существует." << endl;
    }
}

void Elevator::processRequests() {
    while (!requests.empty()) {
        int nextFloor = requests.front();
        requests.pop();
        moveToFloor(nextFloor);
    }
    processedRequests.clear();
}

void Elevator::moveToFloor(int floor) {
    cout << "Лифт движется " << (floor > currentFloor ? "вверх" : "вниз") << " к этажу " << floor << "..." << endl;
    currentFloor = floor;
    cout << "Лифт прибыл на этаж " << currentFloor << "." << endl;
}

void Elevator::displayStatus() const {
    cout << "Текущий этаж: " << currentFloor << ", Направление: " << (direction == 'u' ? "Вверх" : "Вниз") << endl;
}
