//
// Created by caitl on 06/04/2024.
//

#ifndef CA2_BUGS_LIFE_CRAWLER_H
#define CA2_BUGS_LIFE_CRAWLER_H

//Crawler is a Derived class that inherits from Bug base class

#include "Bug.h"
class Crawler : public Bug{     //inherits from Bug

// crawler move rules:
// moves y 1 unit in direction currently facing
// if at edge of board and can't move in current direction (way blocked) - then set a new direction at random
// - repeat until bug can move forward
// record new position in crawlers path history
//    void move(){
//
//    };





};
#endif //CA2_BUGS_LIFE_CRAWLER_H


