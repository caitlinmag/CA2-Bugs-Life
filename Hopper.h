//
// Created by caitl on 06/04/2024.
//

#ifndef CA2_BUGS_LIFE_HOPPER_H
#define CA2_BUGS_LIFE_HOPPER_H

//hopper inherits from bug

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;              // distance hopper bug can hop (2-4 units)

public:
    // moves by hopLength units in current direction
    // edge of board and can't move in current direction - set a new direction at random
    // -repeat until bug can move forward and then move
    // if bug can't move the full hopLength - bug does move but hits edge and falls on square where it hit edge
    // record new position in hoppers path history

    Hopper(int id, int x, int y, Direction direction1, int size, bool alive, int hopLength);

// function prototype
    void move() override;

};

#endif //CA2_BUGS_LIFE_HOPPER_H
