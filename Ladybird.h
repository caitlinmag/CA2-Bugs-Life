//
// Created by caitl on 28/04/2024.
//

#ifndef CA2_BUGS_LIFE_LADYBIRD_H
#define CA2_BUGS_LIFE_LADYBIRD_H

// My new bug type is a ladybird

#include "Bug.h"
class Ladybird: public Bug{     // inherit from Bug

public:
    Ladybird(int id, int x, int y, Direction direction, int size, bool alive);

    // methods
    void move() override;
    void setRandomDirection() override;
    void recordStartPosition() override;
    void print() const override ;
    void printHistory() const override;
    std::string bugHistoryToString()  override;
    std::string getBugType() override;
};



#endif //CA2_BUGS_LIFE_LADYBIRD_H
