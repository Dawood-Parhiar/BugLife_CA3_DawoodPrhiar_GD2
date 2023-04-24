//
// Created by Dawood Parhiar on 10/04/2023.
//

#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "SuperBug.h"
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
        }else if (bugType == "S") {
            SuperBug *superBug = new SuperBug(id, make_pair(x, y), direction, size, true, 2);
            bugs.push_back(superBug);
        }
    }
}

void Board::displayAllBugs(){

//create a new vector and add all the bugs to it
//sort the vector by id
//display the bugs in the vector
   std::list<Bug*> newBugsList;
    for (int i = 0; i < bugs.size(); i++) {
        //check if the bug is a hopper or a crawler
        if(dynamic_cast<Hopper*>(bugs[i]) != nullptr){
            cout << "Hopper: " << bugs[i]->getId() << " " << bugs[i]->getPosition().first << " " << bugs[i]->getPosition().second << " " << bugs[i]->getDirection() << " " << bugs[i]->getSize() << " " << bugs[i]->isAlive() << " " << dynamic_cast<Hopper*>(bugs[i])->getHopDistance() << endl;
        } else if(dynamic_cast<Crawler*>(bugs[i]) != nullptr){
            cout << "Crawler: " << bugs[i]->getId() << " " << bugs[i]->getPosition().first << " " << bugs[i]->getPosition().second << " " << bugs[i]->getDirection() << " " << bugs[i]->getSize() << " " << bugs[i]->isAlive() << endl;
        }else if(dynamic_cast<SuperBug*>(bugs[i]) != nullptr){
            cout << "SuperBug: " << bugs[i]->getId() << " " << bugs[i]->getPosition().first << " " << bugs[i]->getPosition().second << " " << bugs[i]->getDirection() << " " << bugs[i]->getSize() << " " << bugs[i]->isAlive() << endl;
        }
        newBugsList.push_back(bugs[i]);
    }
    //print the list
    newBugsList.sort();
    for (auto & i : newBugsList) {
        cout << i->getId() << " ";
    }
    cout << endl;


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
        }else if(dynamic_cast<SuperBug *>(bugs[i]) != nullptr){
            bugs[i]->move();
        }
    }
}

void Board::fight() {
    //fight function
    //check if any bugs are in the same position
    //if they are in the same position
    //check the size of the bugs and make the smaller bug die
    //if the bugs are the same size
    //make both bugs die

        for (int i = 0; i < bugs.size(); i++) {
            for (int j = 0; j < bugs.size(); j++) {
                if (bugs[i]->getPosition() == bugs[j]->getPosition() && bugs[i]->getId() != bugs[j]->getId()) {
                    if (bugs[i]->getSize() > bugs[j]->getSize()) {
                        bugs[j]->setAlive(false);
                        bugs[i]->setSize(bugs[i]->getSize() + bugs[j]->getSize());
                        bugs[j]->setPosition(make_pair(-1, -1));
                        bugs.erase(bugs.begin() + j);//remove the bug from the vector


                    } else if (bugs[i]->getSize() < bugs[j]->getSize()) {
                        bugs[i]->setAlive(false);
                        bugs[j]->setSize(bugs[i]->getSize() + bugs[j]->getSize());
                        bugs[i]->setPosition(make_pair(-1, -1));
                        bugs.erase(bugs.begin() + i);//remove the bug from the vector

                    } else if (bugs[i]->getSize() == bugs[j]->getSize()) {
                        bugs[i]->setAlive(false);
                        bugs[j]->setAlive(false);
                        bugs[i]->setPosition(make_pair(-1, -1));
                        bugs[j]->setPosition(make_pair(-1, -1));
                        bugs.erase(bugs.begin() + i);//remove the bug from the vector
                        bugs.erase(bugs.begin() + j);//remove the bug from the vector
                    }
                }
            }
        }

}

bool Board::checkAllDead() {
    //check if all the bugs are dead
    //if all the bugs are dead
    //return true
    //else
    //return false
    int count = 0;
    for (int i = 0; i < bugs.size(); i++) {
        if (bugs[i]->isAlive() == false) {
            count++;
        }
    }
    if (count == bugs.size()) {
        return true;
    } else {
        return false;
    }
}
