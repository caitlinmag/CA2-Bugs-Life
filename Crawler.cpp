//
// Created by caitl on 06/04/2024.
//
#include "Crawler.h"
#include "Board.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

Crawler::Crawler(int id, int x, int y, Direction direction, int size, bool alive) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
};

//TODO: implement logic for when a crawler bug moves
// need to check if wayIsBlocked() everytime a bug moves - if it is then move to a random cell
void Crawler::move() {        //implementation of Crawler move()
    cout << "Moving a crawler bug " << endl;

    this->id = 4;

    //check if bug is at the edge of board - if true then means they cant move in current direction
    while (isWayBlocked()) {  // loop until we have a possible way to go
        cout << "bugs way is blocked.";
        setNewDirection();      // call the setRandomDirection method
    }

    //TODO: if isWayBlocked() == false, then move by 1 unit in current direction
    int x = this->position.first;       // row
    int y = this->position.second;      // column

//        this->position.first -= 1;

    // checking which direction the bug is CURRENTLY facing - then moving 1 unit in that direction
    if (this->direction == Direction::North) {
        this->position.first = x - 1;           // if the bug is going north they need to go back the ways - so decrement by 1
    }

    if (this->direction == Direction::South) {
        this->position.first = x + 1;          // if bug is going south they are going forward - so increment by 1
    }

    if (this->direction == Direction::East) {
        this->position.second = y + 1;           // if bug is going east they are going right - so increment by 1
    }

    if (this->direction == Direction::West) {
        this->position.second = y - 1;          // if bug is going west they are going left - so decrement by 1
    }

    cout << "bugs way is not blocked." << endl;


    //TODO: add to crawlers path history
    // remember to add current position of every new bug to the path (once only)
    // after move, new positions will be added to path here
    this->path.push_back(position);
    // then could push the new path to the vector
}

// TODO: could make a function instead, to set a random direction
void Crawler::setNewDirection() {
    cout << "setting a new direction using random" << endl;

//    std::vector<int> directionNums = {1, 2, 3, 4};      // 1,2,3,4 are the numbers used for directions
//
//    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//
//    shuffle(directionNums.begin(), directionNums.end(), default_random_engine(seed));
//
//    cout << "random directions " << endl;
//    for (int &x: directionNums)         // iterate through the vector - now in random order
//        cout << ' ' << x;
//    cout << '\n';

    // use a switch statement

    // then if the random number is for example 1 then set new direction to North

    // could also try this way of using random for directions if the other way doesn't work
    // https://www.baeldung.com/java-enum-random-value#:~:text=Random%20Enum%20Value%20with%20Generics&text=We%20could%20generate%20a%20random,randomEnum()%3B

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

// TODO: make a function to display and record the new path history

// TODO: need to fix print to read in the direction not the number
// printing the fields of a Crawler bug
void Crawler::print() const {
    cout << this->id << " Crawler " << "(" << this->position.first << "," << this->position.second << ") " << this->size
         << " " << this->direction << " " << this->alive << endl;
}

void Crawler::printHistory() const {
    for (auto listIter = path.begin(); listIter != path.end(); listIter++){

    }

    cout << this->id << " Crawler Path:" << "(" << ")" << endl;
}