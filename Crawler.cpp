//
// Created by caitl on 06/04/2024.
//

#include "Crawler.h"
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

Crawler::Crawler(int id, int x, int y, Direction direction, int size, bool alive) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
}; // bool alive has been taken out - was getting an error with it in constructor

//TODO: implement logic for when a crawler bug moves
// need to check if wayIsBlocked() everytime a bug moves - if it is then move to a random cell
void Crawler::move() {        //implementation of Crawler move()
    cout << "Moving a crawler bug " << endl;

    this->id = 4;

    // crawler move rules:
    //TODO: first get the current direction of crawler bug


    //TODO: if statement : check if at edge of board - if true then means they cant move in current direction
    if (isWayBlocked()) {
        cout << "bugs way is blocked.";
        // call the setRandomDirection function

        // setting a new direction for the bug

    } else {
        //TODO: if isWayBlocked() = false, then move by 1 unit in current direction
        int x = this->position.first;       // row
        int y = this->position.second;      // column

//        this->position.first -= 1;

        // checking which direction the bug is CURRENTLY facing - then moving 1 unit in that direction
        if (this->direction == Direction::North) {
            this->position.second =
                    y - 1;           // if the bug is going north they need to go back the ways - so decrement by 1
            setNewDirection();
        }

        if (this->direction == Direction::South) {
            this->position.second = y + 1;          // if bug is going south they are going forward - so increment by 1
            setNewDirection();
        }

        if (this->direction == Direction::East) {
            this->position.first = x + 1;           // if bug is going east they are going right - so increment by 1
        }

        if (this->direction == Direction::West) {
            this->position.first = x - 1;          // if bug is going west they are going left - so decrement by 1
        }

        cout << "bugs way is not blocked." << endl;
    }

    //TODO: so now we need to get a new direction - if isWayBlocked() is true then setting new direction at random
    // for loop - iterate through - repeating until bug can move forward


    //TODO: get the new position
    // add to crawlers path history
}

// TODO: could make a function instead, to set a random direction
void Crawler::setNewDirection() {
    cout << "setting a new direction using random" << endl;

    std::vector<int> directionNums = {1, 2, 3, 4};
    // get random number

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(directionNums.begin(), directionNums.end(), default_random_engine(seed));

    cout << "random directions " << endl;
    for (int &x: directionNums)
        cout << ' ' << x;
    cout << '\n';

    // use a switch statement
    // then if the random number is for example 1 then set new direction to North

    // could also try this way of using random for directions if the other way doesn't work
    // https://www.baeldung.com/java-enum-random-value#:~:text=Random%20Enum%20Value%20with%20Generics&text=We%20could%20generate%20a%20random,randomEnum()%3B
}

// TODO: make a function to display and record the new path history
// TODO: need to fix it to read in the name of the direction not the number
// printing the fields of a Crawler bug
void Crawler::print() const {
    cout << this->id << " Crawler " << "(" << this->position.first << "," << this->position.second << ") " << this->size
         << " " << this->direction << " " << this->alive << endl;
}

