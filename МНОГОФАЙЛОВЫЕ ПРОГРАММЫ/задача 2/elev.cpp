#include "elev.h"
#include <iostream>
using namespace std;

Elevator::Elevator() : currentFloor(1) {}
void Elevator::requestFloor() {
    int floor;
    cout << "На каком Вы этаже? ";
    cin >> floor;
    if (floor < 1 || floor > 20) {
        cout << "Этаж вне диапазона (1-20). Повторите попытку." << endl;
        return;
    }
    cout << "В каком направлении будете двигаться (u/d): ";
    char direction;
    cin >> direction;
    if (direction != 'u' && direction != 'd') {
        cout << "Неверное направление. Используйте 'u' для вверх и 'd' для вниз." << endl;
        return;
    }
    destinations.push_back(floor);
    cout << "Запрос принят. Лифт прибудет на этаж " << floor << "." << endl;
    moveToFloor(floor);
}

void Elevator::moveToFloor(int floor) {
    cout << "Лифт движется к этажу " << floor << "..." << endl;
    currentFloor = floor;
    cout << "Лифт прибыл на этаж " << currentFloor << "." << endl;
}

void Elevator::setDestination() {
    int dest;
    cout << "Введите номера нужных этажей (0 для окончания ввода): ";
    while (true) {
        cin >> dest;
        if (dest == 0) break;
        if (dest < 1 || dest > 20) {
            cout << "Этаж вне диапазона. Повторите ввод." << endl;
            continue;
        }
        destinations.push_back(dest);
    }
    cout << "Пункты назначения: ";
    for (int floor : destinations) {
        cout << floor << " ";
    }
    cout << endl;
    serviceDestinations();
}

void Elevator::serviceDestinations() {
    for (int floor : destinations) {
        moveToFloor(floor);
    }
    destinations.clear();
}
