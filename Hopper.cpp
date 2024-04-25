//
// Created by caitl on 06/04/2024.
//

#include "Hopper.h"
#include <iostream>

using namespace std;

Hopper::Hopper(int id, int x, int y, Direction direction, int size, int hopLength, bool alive) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->hopLength = hopLength;
    this->alive = alive;
}

// need to check if wayIsBlocked() everytime a bug moves - if it is then move to a random cell
void Hopper::move() {      //implementation of Hopper move()
    cout << "Moving a hopper bug " << endl;

    while (isWayBlocked()) {
        setRandomDirection();
    }

    // Bugs way is not blocked - so move by hopLength
    int x = this->position.first;       // row
    int y = this->position.second;      // column

    // checking which direction and if the bug can move the full hopLength
    // If bug can't move full hopLength - moves but hits edge and falls on square where it hit the edge
    switch(this->direction){
        case North:
            // checking if x minus the hopLength is greater than 0 - then the bug can move the full hopLength
            if(x - hopLength >=0){ // 0 is first row - edge
                // if the bug is going north they need to go up one row - so decrement by hopLength
                this->position.first = x - hopLength;
            }else{
                // can't move the full hopLength so set x to 0 - the edge
                this->position.first = 0;
            }
        case South:
            // checking if x plus the hopLength is less than 9 - then the bug can move the full hopLength
            if(x + hopLength <=9){ // 9 is the last row - edge
                // if bug is going south they are going down one row - so increment by hopLength
                this->position.first = x + hopLength;
            }else{
                // can't move the full hopLength so set x to 9 - the edge
                this->position.first = 9;
            }
            break;
        case East:
            // checking if y plus the hopLength is less than 9 - then the bug can move the full hopLength
            if(y + hopLength <=9){
                this->position.second = y + hopLength;   // if bug is going east they are going right one column - so increment by hopLength
            }else{
                // can't move the full hopLength so set y to 9 - the edge
                this->position.second = 9;
            }
            break;
        case West:
            // checking if y minus the hopLength is greater than 0 - then the bug can move the full hopLength
            if(y - hopLength >=0){
                this->position.second = y - hopLength;    // if bug is going west they are going left one column - so decrement by hopLength
            }else{
                // can't move the full hopLength so set y to 0 - the edge
                this->position.second = 0;
            }
            break;
    }

    // record new position in path
    this->path.push_back(position);
}

void Hopper::setRandomDirection() {
    cout << "setting a new direction using random" << endl;

    /*
     *  From StackOverflow:
     *  https://stackoverflow.com/questions/30540078/using-c-rand-to-get-random-directions-up-down-left-right-always-getting#:~:text=company%20blog-,Using%20C%2B%2B%20rand()%20to%20get%20random%20directions%20(up%2Fdown,%2Fright)%20%2D%20always%20getting%20up&text=It%20randomly%20gets%20a%20number,always%20sets%20the%20pieces%20vertically
     */

    int randNum = rand();
    int x = (randNum % 4) + 1;      // getting a random number between 1 and 4

    // using a switch statement to check what number x is , then assigning a direction to the number
    switch (x) {
        case 1:
            direction = Direction::North;
            cout << "New direction is North" << endl;
            break;
        case 2:
            direction = Direction::East;
            cout << "New direction is east" << endl;
            break;
        case 3:
            direction = Direction::South;
            cout << "New direction is south" << endl;
            break;
        case 4:
            direction = Direction::West;
            cout << "New direction is west" << endl;
            break;
    }
}

// this->setDirection()
// TODO: need to get in the direction and change it to the corresponding enum
void Hopper::print() const {
    cout << this->id << " Hopper " << "(" << this->position.first << "," << this->position.second << ") " << this->size
         << " " << directionToString(this->direction) << " " << this->hopLength << " " << this->alive << endl;
}

void Hopper::printHistory() const {
    cout << this->id << " Hopper Path: ";

    for (auto listIter = path.begin(); listIter != path.end(); listIter++){
        cout << "(" << listIter->first << "," << listIter->second << ")" << ",";
    }


}