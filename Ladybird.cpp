//
// Created by caitl on 28/04/2024.
//

#include "Ladybird.h"
#include <iostream>

using namespace std;

Ladybird::Ladybird(int id, int x, int y, Direction direction, int size, bool alive) {
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
}

// implementation of ladybird move
// the idea is for the ladybird bug to fly - by taking in user input to where they would like the bug to fly to on the board
void Ladybird::move() {
    cout << "Moving a Ladybird." << endl;
    cout << "Enter a cell you would like the ladybird to fly to: (Enter x on one line, and y on the next)" << endl;

    int cellX, cellY;
    cin >> cellX;
    cin >> cellY;

    // check that x and y are within the size of the board
    // so min is (0,0) and max is (9,9)
    if((cellX >= 0 && cellX <=9) && (cellY >= 0 && cellY <=9)){
        // within bounds so update the position of the ladybird
        this->position.first = cellX;
        this->position.second = cellY;
        cout << "Ladybird has flew to: (" << this->position.first << "," << this->position.second << ")" << endl;
        // add the new position to the path
        this->path.push_back(position);

    }else{
        cout << "Input cells are out of bounds of the board.Cells must be between (0,0) and (9,9)." << endl;
        cout << "Ladybird will remain on: (" << this->position.first << "," << this->position.second << ")" << endl;
    }
}

void Ladybird::recordStartPosition() {
    this->path.push_back(position);
}

void Ladybird::print() const {
    cout << this->id << " Ladybird " << "(" << this->position.first << "," << this->position.second << ") " << this->size << " " << directionToString(this->direction) << " " << endl;
}

void Ladybird::printHistory() const {
    cout << this->id << " Ladybird Path: ";

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

string Ladybird::bugHistoryToString() {
    string bugHistory;

    bugHistory += "Ladybird Path: ";
    // iterate through the path
    for (auto listIter = path.begin(); listIter != path.end(); listIter++) {
        pair<int, int> p = *listIter;

        // TODO: check for the last comma - want to take it out
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

string Ladybird::getBugType() {
    string ladybirdType = "Ladybird";
    return ladybirdType;
}

void Ladybird::setRandomDirection() {

}