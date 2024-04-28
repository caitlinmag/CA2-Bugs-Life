//
// Created by caitl on 06/04/2024.
//
#include "Crawler.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

Crawler::Crawler(int id, int x, int y, Direction direction, int size, bool alive) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
};

// implementation of Crawler move()
void Crawler::move() {

    // check if bug is at the edge of board - if true then means they cant move in current direction
    while (isWayBlocked()) {  // loop until we have a possible way to go
        setRandomDirection();      // call the setNewDirection() method to set a new direction at random
    }

    // Bugs way is not blocked - so move 1 unit in current direction
    int x = this->position.first;       // row
    int y = this->position.second;      // column

    // checking which direction the bug is CURRENTLY facing - then moving 1 unit in that direction
    // also need to ensure cells are only between 0 and 9 - the numbers can't go above 9
    switch (this->direction) {
        case North:
            // if the bug is going north they need to go up one row - so decrement by 1
            if (x >= 0) {
                this->position.first = x - 1;
            }
        case South:
            // if bug is going south they are going forward - so increment by 1
            if (x < 9) {
                this->position.first = x + 1;
            }
            break;
        case East:
            // if bug is going east they are going right - so increment by 1
            if (y < 9) {
                this->position.second = y + 1;
            }
            break;
        case West:
            // if bug is going west they are going left - so decrement by 1
            if (y > 0) {
                this->position.second = y - 1;
            }
            break;
    }

    // add new position to the path, after bug has moved
    this->path.push_back(position);
    cout << "Crawler" << " Bug " << id << " has moved to: " << "(" << position.first << "," << position.second << ")" << endl;
}

void Crawler::setRandomDirection() {
    cout << "Setting a new random direction." << endl;

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
            cout << "Bug" << id << " New direction is North" << endl;
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

    /*
 *  Not using this way anymore. From StackOverflow:
 *  https://stackoverflow.com/questions/30540078/using-c-rand-to-get-random-directions-up-down-left-right-always-getting#:~:text=company%20blog-,Using%20C%2B%2B%20rand()%20to%20get%20random%20directions%20(up%2Fdown,%2Fright)%20%2D%20always%20getting%20up&text=It%20randomly%20gets%20a%20number,always%20sets%20the%20pieces%20vertically
 */
//
//    // I started with this way using rand() however there wasn't much randomness
//    // one bug kept getting the same direction to move in
//    int randNum = rand();
//    int x = (randNum % 4) + 1;      // getting a random number between 1 and 4
}

void Crawler::recordStartPosition() {
    this->path.push_back(position);
}

// printing the fields of a Crawler bug
void Crawler::print() const {
    cout << this->id << " Crawler " << "(" << this->position.first << "," << this->position.second << ") " << this->size
         << " " << directionToString(this->direction) << " " << endl;
}

// check if its at the end of list and output comma if not don't
void Crawler::printHistory() const {
    cout << this->id << " Crawler Path: ";

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

string Crawler::bugHistoryToString() {
    string bugHistory;

    bugHistory += "Crawler Path: ";
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

string Crawler::getBugType() {
    string crawlerType = "Crawler";
    return crawlerType;
}