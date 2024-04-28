//
// Created by caitl on 06/04/2024.
//

#include "Hopper.h"
#include <iostream>
#include <list>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


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

//  Implementation of Hopper move()
void Hopper::move() {

    // need to check if wayIsBlocked() everytime a bug moves - if it is then move to a random cell
    while (isWayBlocked()) {
        setRandomDirection();
    }

    // Bugs way is not blocked - so move by hopLength
    int x = this->position.first;       // row
    int y = this->position.second;      // column

    // checking which direction and if the bug can move the full hopLength
    // If bug can't move full hopLength - moves but hits edge and falls on square where it hit the edge
    switch (this->direction) {
        case North:
            // checking if x minus the hopLength is greater than 0 - then the bug can move the full hopLength
            if (x - hopLength >= 0) { // 0 is first row - edge
                // if the bug is going north they need to go up one row - so decrement by hopLength
                this->position.first = x - hopLength;
            } else {
                // can't move the full hopLength so set x to 0 - the edge
                this->position.first = 0;
            }
        case South:
            // checking if x plus the hopLength is less than 9 - then the bug can move the full hopLength
            if (x + hopLength <= 9) { // 9 is the last row - edge
                // if bug is going south they are going down one row - so increment by hopLength
                this->position.first = x + hopLength;
            } else {
                // can't move the full hopLength so set x to 9 - the edge
                this->position.first = 9;
            }
            break;
        case East:
            // checking if y plus the hopLength is less than 9 - then the bug can move the full hopLength
            if (y + hopLength <= 9) {
                // if bug is going east they are going right one column - so increment by hopLength
                this->position.second = y + hopLength;
            } else {
                // can't move the full hopLength so set y to 9 - the edge
                this->position.second = 9;
            }
            break;
        case West:
            // checking if y minus the hopLength is greater than 0 - then the bug can move the full hopLength
            if (y - hopLength >= 0) {
                // if bug is going west they are going left one column - so decrement by hopLength
                this->position.second = y -hopLength;
            } else {
                // can't move the full hopLength so set y to 0 - the edge
                this->position.second = 0;
            }
            break;
    }


    // record new position in path
    this->path.push_back(position);
    cout << "Bug " << id << " has moved to: " << "(" << position.first << "," << position.second << ")" << endl;
}

void Hopper::setRandomDirection() {
    cout << "Setting a new direction using random" << endl;
    // Trying to get a random number by using the shuffle()
    // making a vector of ints from 1 - 4 , to represent the directions
    vector<int> randomNums = {1, 2, 3, 4};

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(randomNums.begin(), randomNums.end(), default_random_engine(seed));

    // make the randDirectionNum equal to the first element in the shuffled vector
    int randDirectionNum = randomNums[0];

    // using a switch statement to check what number x is , then assigning a direction to the number
    switch (randDirectionNum) {
        case 1:
            direction = Direction::North;
            cout << "Bug " << id << " New direction is North" << endl;
            break;
        case 2:
            direction = Direction::East;
            cout << "Bug " << id << " New direction is East" << endl;
            break;
        case 3:
            direction = Direction::South;
            cout << "Bug " << id << " New direction is South" << endl;
            break;
        case 4:
            direction = Direction::West;
            cout << "Bug " << id << " New direction is West" << endl;
            break;
    }
}

void Hopper::recordStartPosition() {
    this->path.push_back(position);
}

void Hopper::print() const {
    cout << this->id << " Hopper " << "(" << this->position.first << "," << this->position.second << ") " << this->size
         << " " << directionToString(this->direction) << " " << this->hopLength << " " << endl;
}

void Hopper::printHistory() const {
    cout << this->id << " Hopper Path: ";

    for (auto listIter = path.begin(); listIter != path.end(); listIter++) {
        pair<int, int> p = *listIter;

        cout << "(" << p.first << "," << p.second << ")" << ",";
    }

    // checking if bug has been eaten
    if (alive) {
        cout << " Alive!";
    } else {
        // display who ate the bug
        cout << "Eaten by ";
    }
}

//  Used this website to learn how to add to a string in C++ as I wasn't sure
//  https://www.geeksforgeeks.org/stdstringappend-vs-stdstringpush_back-vs-operator-c/
string Hopper::bugHistoryToString() {
    string bugHistory;

    bugHistory += "Hopper Path: ";

    // TODO: check for the last comma - want to take it out

    // iterate through the path
    for (auto listIter = path.begin(); listIter != path.end(); listIter++) {
        pair<int, int> p = *listIter;
        // adding the path to the string one by one
        bugHistory += "(";
        bugHistory += std::to_string(p.first);
        bugHistory += ",";
        bugHistory += std::to_string(p.second);
        bugHistory += ")";
        bugHistory += ",";
    }
    return bugHistory;
}

string Hopper:: getBugType(){
    string hopperType = "Hopper";
    return hopperType;
}