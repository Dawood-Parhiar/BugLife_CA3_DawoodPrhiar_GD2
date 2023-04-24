//
// Created by Dawood Parhiar on 31/03/2023.
//

#include "Bug.h"
#include "Hopper.h"

# include <iostream>
using namespace std;

Bug::Bug(int id, std::pair<int, int> position, int direction, int size, bool alive) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;

}

int Bug::getId() const {
    return id;
}

 pair<int, int> Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

void Bug::setDirection(int d) {
    Bug::direction = d;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

std::string Bug::getBugType() const {
    return 0;
}
//bool set alive
bool Bug::setAlive(bool alive) {
    Bug::alive = true;
}

//set size
void Bug::setSize(int size) {
    Bug::size = size;
}

list<std::pair<int, int>> Bug::getPath() const {
    return path;
}

bool Bug::isWayBlocked() const {
    //Checks if a bug is against an edge of the board AND if it is
    //facing in the direction of that edge. If so, its way is blocked.
    //[Used by the move() function]
    if(getDirection() == 1 && position.second == 0)//North
    {
        return true;
    }
    else if(getDirection() == 2 && position.first == 9)//East
    {
        return true;
    }
    else if(getDirection() == 3 && position.second == 9)//South
    {
        return true;
    }
    else if(getDirection() == 4 && position.first == 0)//West
    {
        return true;
    }else
    {
        return false;
    }
}

void Bug::setPosition(std::pair<int, int> position) {

}







