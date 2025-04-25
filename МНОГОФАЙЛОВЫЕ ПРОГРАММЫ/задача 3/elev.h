#pragma once

#include <queue>
#include <set>

class Elevator {
private:
    int currentFloor;
    std::queue<int> requests;
    std::set<int> processedRequests;
    char direction;
public:
    Elevator();
    void addRequest();
    void processRequests();
    void moveToFloor(int floor);
    void displayStatus() const;
};

