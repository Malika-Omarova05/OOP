#include <iostream>
#include "elev.h"

int main() {
    setlocale(LC_ALL, "rus");
    Elevator elevator;

    elevator.requestFloor();
    elevator.setDestination();

    return 0;
}
