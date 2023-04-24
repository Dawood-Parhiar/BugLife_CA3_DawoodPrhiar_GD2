//
// Created by Dawood Parhiar on 10/04/2023.
//


#define BUGLIFE_CA3_DAWOODPARHIAR_GD2_BOARD_H


#include "Bug.h"
#include <iostream>
#include <utility>
#include <list>
#include <vector>

class Board {
    // this class will be used to create a board object
    // a board will have a 2d array of ints
    // a board will have a vector of bugs

    int BOARD_WIDTH = 10;

    std::vector<Bug *> bugs;


public:

    void loadFromFile();

    void displayAllBugs();

    void shakeBoard();

    void fight();

    std::vector<Bug*> & getBugs() { return bugs;}

    bool checkAllDead();
};

