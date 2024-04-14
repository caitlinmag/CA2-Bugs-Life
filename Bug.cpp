//
// Created by caitl on 06/04/2024.
//

#include "Bug.h" //copies in the Bug.h class definition
#include <iostream>

using namespace std;

Bug::~Bug() {
    cout << "~Bug() called. Bug destructor " << endl;
}