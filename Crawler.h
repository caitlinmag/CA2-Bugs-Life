//
// Created by caitl on 06/04/2024.
//

#ifndef CA2_BUGS_LIFE_CRAWLER_H
#define CA2_BUGS_LIFE_CRAWLER_H

//Crawler is a Derived class that inherits from Bug base class

#include "Bug.h"
class Crawler : public Bug{     //inherits from Bug

public:
    Crawler(int id, int x, int y, Direction direction, int size, bool alive);

    void move() override; // only the function prototype
};
#endif //CA2_BUGS_LIFE_CRAWLER_H


