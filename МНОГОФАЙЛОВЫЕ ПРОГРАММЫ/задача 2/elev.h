#pragma once
#include <vector>

class Elevator {
private:
    int currentFloor; 
    std::vector<int> destinations; 

public:
    Elevator();
    void requestFloor();
    void moveToFloor(int floor); 
    void setDestination(); 
    void serviceDestinations(); 
};

