//
// Created by Dawood Parhiar on 20/04/2023.
//

#ifndef BUGLIFE_CA3_DAWOODPARHIAR_GD2_CRAWLER_H
#define BUGLIFE_CA3_DAWOODPARHIAR_GD2_CRAWLER_H


#include <utility>
#include "Bug.h"

class Crawler: public Bug{
// this class will be used to create a crawler object that inherits from the bug class
protected:
    void move() override;

public:
    Crawler(int id, std::pair<int, int> position, int direction, int size, bool alive);
};


#endif //BUGLIFE_CA3_DAWOODPARHIAR_GD2_CRAWLER_H
