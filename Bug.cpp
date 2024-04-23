//
// Created by caitl on 06/04/2024.
//

#include "Bug.h" //copies in the Bug.h class definition
#include <iostream>

using namespace std;

Bug::~Bug() {
    cout << "~Bug() called. Bug destructor " << endl;
}

int Bug::getBugId() const{     // creating a getter for bugId to use in the findBugById() function
    return this->id;
}

int Bug::getDirection() const {
    switch(direction){
        case 1:
            return Direction::North;
        case 2:
            return Direction::East;
        case 3:
            return Direction::South;
        case 4:
            return Direction::West;
    }
}

int Bug::setDirection() const {
    switch (direction) {
        case 1:
            cout << "North" << endl;
        case 2:
            cout << "East" << endl;
        case 3:
            cout << "South" << endl;
        case 4:
            cout << "West" << endl;
    }
}

// the bug board is 10 x 10 so max is so min cell is 0 and max is 9
bool Bug::isWayBlocked() {
    int x = this->position.first;
    int y = this->position.second;

    // (x,y) x is row , y is column
    // north and south will be y
    // east and west will be x

    // check if bug facing north
    if (x == 0 && direction == Direction::North) {
        cout << "bugs way is blocked facing north" << endl;
        return true;
    }

    //check if bug facing south
    if(x == 9 && direction == South){
        cout << "bugs way is blocked facing south" << endl;
        return true;
    }

    // check if bug facing east
    // ending cell is 9
    if(direction == East && y == 9){
        cout << "bugs way is blocked facing east" << endl;
        return true;
    }

    // check if bug facing west
    // first cell is 0
    if(direction == West &&  y == 0){
        cout << "bugs way is blocked facing west" << endl;
        return true;
    }

    // otherwise way is blocked
    return false;
}

void Bug::move() {}

void Bug::print() const {}

