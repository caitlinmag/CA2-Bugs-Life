//
// Created by caitl on 18/04/2024.
//

#ifndef CA2_BUGS_LIFE_BOARD_H
#define CA2_BUGS_LIFE_BOARD_H

#include "Bug.h"
#include <vector>
#include <fstream> //to access file input and output

class Board {
protected:
    std::vector<Bug *> bug_vector;  // make the bug_vector private to the board class

public:
    Board();

    void fillBugsVector(std::ifstream &fin);

    void displayAllBugs();

    void findBugById();

    void tapBugBrd();
};

#endif //CA2_BUGS_LIFE_BOARD_H
