//
// Created by caitl on 06/04/2024.
//

#include "Crawler.h"
#include <iostream>
using namespace std;


Crawler::Crawler(int id, int x, int y, Direction direction, int size, bool alive){};

void Crawler::move() {        //implementation of Crawler move()
cout << "Moving a crawler bug " << endl;

this->id =4;

    // get the direction crawler currently facing
    // check at edge of board - isWayBlocked()
    //

if(this->direction == Direction::North) {
    // bla bla

    int x = this->position.first;
    int y = this->position.second;

    this->position.first -= 1;


}


}



