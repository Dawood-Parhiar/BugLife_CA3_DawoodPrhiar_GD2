//
// Created by Dawood Parhiar on 31/03/2023.
//

#include "Bug.h"
# include <iostream>
using namespace std;

Bug::Bug(int id, std::pair<int, int> position, int direction, int size, bool alive) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
}

bool Bug::isWayBlocked() {
    //Checks if a bug is against an edge of the board AND if it is
    //facing in the direction of that edge. If so, its way is blocked.
    //[Used by the move() function]
    return false;
}

class Crawler : public Bug {
public:
    Crawler(int id, std::pair<int, int> position, int direction, int size, bool alive) : Bug(id, position, direction, size, alive) {
        this->id = id;
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = alive;
    }

    void move() override {
        cout << "Crawler is moving" << endl;
        //A Crawler bug moves according to these rules:
        // moves by 1 unit in the direction it is currently facing
        //if at edge of board and can’t move in current direction (because
        //its way is blocked), then, set a new direction at random. (Repeat
        //until bug can move forward).
        //record new position in the crawler's path history


    }

};

class Hopper : public Bug {
public:
    Hopper(int id, std::pair<int, int> position, int direction, int size, bool alive, int hopLength) : Bug(id, position, direction, size, alive)
    {
        this->id = id;
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = alive;
        //The distance/length that a particular hopper bug can hop (in
        //range (2-4 units)
        hopLength = 0 ;
    }

    void move() override {
        cout << "Hopper is moving" << endl;
    }
};



