//
// Created by Dawood Parhiar on 31/03/2023.
//

#ifndef BUGLIFE_CA3_DAWOODPARHIAR_GD2_BUG_H
#define BUGLIFE_CA3_DAWOODPARHIAR_GD2_BUG_H

//utility standard library
#include <utility>
#include <list>

class Bug {
// this class will be used to create a bug object
// a bug will have int id,
// pair <int, int> position;
// int direction; enums to be used,
// int size
//bool alive;
//list<pair<int, int>> path;

protected:
    Bug(int id, std::pair<int, int> position, int direction, int size, bool alive);

    protected: int id{};
    protected: std::pair<int, int> position{};
    protected: int direction{};
    protected: int size{};
    protected: bool alive{};
    protected:   std::list<std::pair<int, int>> path{};
    virtual void move() = 0;
    static bool isWayBlocked() ;

};




#endif //BUGLIFE_CA3_DAWOODPARHIAR_GD2_BUG_H
