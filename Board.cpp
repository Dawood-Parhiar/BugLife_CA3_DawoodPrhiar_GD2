//
// Created by Dawood Parhiar on 10/04/2023.
//

#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

BUGLIFE_CA3_DAWOODPARHIAR_GD2_BOARD_H





void Board::loadFromFile() {

    ifstream file("bugs.txt");
    string line;
    while (getline(file, line)) {

        stringstream ss(line);
        string temp;
        string bugType;
        int id, x, y, direction, size;
        getline(ss, bugType, ';');
        getline(ss, temp, ';');
        id = stoi(temp);
        getline(ss, temp, ';');
        x = stoi(temp);
        getline(ss, temp, ';');
        y = stoi(temp);
        getline(ss, temp, ';');
        direction = stoi(temp);
        getline(ss, temp, ';');
        size = stoi(temp);

        if (bugType == "H") {
            getline(ss, temp, ';');
            int hopDistance = stoi(temp);
            Hopper *hopper = new Hopper(id, make_pair(x, y), direction, size, true, hopDistance);
            bugs.push_back(hopper);
        } else if (bugType == "C") {
            Crawler *crawler = new Crawler(id, make_pair(x, y), direction, size, true);
            bugs.push_back(crawler);
        }
    }
}

void Board::displayAllBugs() {
    for (int i = 0; i < bugs.size(); i++) {
        //check if the bug is a hopper or a crawler
        if(dynamic_cast<Hopper*>(bugs[i]) != nullptr){
            cout << "Hopper: " << bugs[i]->getId() << " " << bugs[i]->getPosition().first << " " << bugs[i]->getPosition().second << " " << bugs[i]->getDirection() << " " << bugs[i]->getSize() << " " << bugs[i]->isAlive() << " " << dynamic_cast<Hopper*>(bugs[i])->getHopDistance() << endl;
        } else if(dynamic_cast<Crawler*>(bugs[i]) != nullptr){
            cout << "Crawler: " << bugs[i]->getId() << " " << bugs[i]->getPosition().first << " " << bugs[i]->getPosition().second << " " << bugs[i]->getDirection() << " " << bugs[i]->getSize() << " " << bugs[i]->isAlive() << endl;
        }
    }
}

void Board::shakeBoard() {
    //shake the board to move the bugs around
    //for each bug in the vector of bugs
    for (int i = 0; i < bugs.size(); i++) {
        //check if the bug is a hopper or a crawler
        if (dynamic_cast<Hopper *>(bugs[i]) != nullptr) {
            //if the bug is a hopper
            //call the move function
            bugs[i]->move();
        }else if (dynamic_cast<Crawler *>(bugs[i]) != nullptr) {
            //if the bug is a crawler
            //call the move function
            bugs[i]->move();
        }
    }
}