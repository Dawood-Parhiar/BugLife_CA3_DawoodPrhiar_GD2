//
// Created by Dawood Parhiar on 20/04/2023.
//

#include <cstdlib>
#include "Crawler.h"

Crawler::Crawler(int id, std::pair<int, int> position, int direction, int size, bool alive) : Bug(id, position, direction, size, alive) {
    // this constructor will be used to create a crawler object
    // it will call the constructor of the bug class
}
 void Crawler::move()
{
    while(isWayBlocked()){
        int newDirection = rand() % 5+1;
        setDirection(newDirection);
    }

    switch(direction)
    {
        case 1://North up
            position.second--;
            break;
        case 2://East right
            position.first++;
            break;
        case 3://South down
            position.second++;
            break;
        case 4://West left
            position.first--;
            break;
        case 5: //stay dumb
            break;
    }

}
