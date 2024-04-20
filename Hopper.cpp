//
// Created by caitl on 06/04/2024.
//

#include "Hopper.h"
#include <iostream>
using namespace std;

Hopper::Hopper(int id, int x, int y, Direction direction, int size,  int hopLength) {
}

// need to check if wayIsBlocked() everytime a bug moves - if it is then move to a random cell
void Hopper::move() {      //implementation of Hopper move()
    cout << "Moving a hopper bug " << endl;
}

void Hopper::print () const {
    cout << this->id << " Hopper " << "(" << this->position.first << "," << this->position.second << ") " << this->size << " " << this->direction << " " << this->hopLength << " " << this->alive << endl;
}
