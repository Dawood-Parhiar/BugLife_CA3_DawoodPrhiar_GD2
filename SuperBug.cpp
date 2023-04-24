//
// Created by Dawood Parhiar on 24/04/2023.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SuperBug.h"

SuperBug::SuperBug(int id, std::pair<int, int> position, int direction, int size, bool alive, int superBugSize) : Bug(id, position, direction, size, alive) {
    this->superBugSize = superBugSize;
}

int SuperBug::getSuperBugSize() const {
    return superBugSize;
}

void SuperBug::setSuperBugSize(int superBugSize) {
    SuperBug::superBugSize = superBugSize;
}
void SuperBug::move() {
    //Move the bug by vector2 direction
    position.first += +1;
    position.second += +1;


}


std::pair<int, int> SuperBug::getPosition() const {
    return Bug::getPosition();
}
