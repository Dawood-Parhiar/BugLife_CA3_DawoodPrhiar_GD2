//
// Created by Dawood Parhiar on 20/04/2023.
//

#include "Hopper.h"

Hopper::Hopper(int id, std::pair<int, int> position, int direction, int size, bool alive,int hopDistance) : Bug(id, position, direction, size, alive) {
    // this constructor will be used to create a hopper object
    // it will call the constructor of the bug class
    this->hopDistance = hopDistance;
}

int Hopper::getHopDistance() const {
    return hopDistance;
}

void Hopper::setHopDistance(int h) {
    Hopper::hopDistance = h;
}

 void Hopper::move()
{

}
