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

    //TODO: going to move the vector to the board - use a reference to it then in the main instead ??
public:
//    void fillBugsVector(std::ifstream &fin, std::vector<Bug *> &bug_vector);
//    void displayAllBugs(std::vector<Bug *> &bug_vector);
//    void findBugById(std::vector<Bug *> &bug_vector);
    Board();

    void fillBugsVector(std::ifstream &fin);

    void displayAllBugs();

    void findBugById();

    void tapBugBrd();
};

#endif //CA2_BUGS_LIFE_BOARD_H
