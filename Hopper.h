//
// Created by Dawood Parhiar on 20/04/2023.
//

#ifndef BUGLIFE_CA3_DAWOODPARHIAR_GD2_HOPPER_H
#define BUGLIFE_CA3_DAWOODPARHIAR_GD2_HOPPER_H


#include "Bug.h"

class Hopper: public Bug{
// this class will be used to create a hopper object that inherits from the bug class
protected:
    int hopDistance{};
    void move() override;

public:
    Hopper(int id, std::pair<int, int> position, int direction, int size, bool alive, int hopDistance);

    int getHopDistance() const;

    void setHopDistance(int hopDistance);

};


#endif //BUGLIFE_CA3_DAWOODPARHIAR_GD2_HOPPER_H
