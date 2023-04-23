//
// Created by Dawood Parhiar on 20/04/2023.
//

#include <cstdlib>
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
    //A Hopper bug moves according to these rules:
    //- moves by “hopLength” units in current direction
    //- if at edge of board and can’t move over edge in
    //current direction, set a new direction at random
    //(repeat until bug can move forward) and then
    //move.
    //- if bug can’t hop the full ‘hopLength’, then the bug
    //does move but ‘hits’ the edge and falls on the
    //square where it hit the edge/wall
    //- record new position in hoppers path history

    while(isWayBlocked()){
        int newDirection = rand() % 5+1;
        setDirection(newDirection);
    }

    switch(direction)
    {
        case 1://North up
            position.second -= hopDistance;
            break;
        case 2://East right
            position.first += hopDistance;
            break;
        case 3://South down
            position.second += hopDistance;
            break;
        case 4://West left
            position.first -= hopDistance;
            break;
        case 5: //stay dumb
            break;
    }

}
