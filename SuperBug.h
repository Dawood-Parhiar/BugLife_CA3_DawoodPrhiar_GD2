//
// Created by Dawood Parhiar on 24/04/2023.
//

#ifndef BUGLIFE_CA3_DAWOODPARHIAR_GD2_SUPERBUG_H
#define BUGLIFE_CA3_DAWOODPARHIAR_GD2_SUPERBUG_H


#include "Bug.h"

class SuperBug: public Bug {
// this class will be used to create a superbug object that inherits from the bug class

protected:
    int superBugSize{};
    void move() override;

public:
    int getSuperBugSize() const;

    void setSuperBugSize(int superBugSize);

    std::pair<int, int> getPosition() const;

    std::pair<int, int> setPosition(int x, int y);

    SuperBug(int id, std::pair<int, int> position, int direction, int size, bool alive, int superBugSize);
};


#endif //BUGLIFE_CA3_DAWOODPARHIAR_GD2_SUPERBUG_H
