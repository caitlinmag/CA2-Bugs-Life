//
// Created by caitl on 06/04/2024.
//

#include "Bug.h" //copies in the Bug.h class definition
#include <iostream>

using namespace std;

Bug::~Bug() {
    cout << "~Bug() called. Bug destructor " << endl;
}

//TODO: implement logic for isWayBlocked()
bool Bug::isWayBlocked() {

    int x = this->position.first;
    int y = this->position.second;

    // (x,y)

    // check if bug facing north
    if (x == North && y == 0) {
        return true;
    }

    //check if bug facing east

    //check if bug facing south

    //check if bug facing west

}