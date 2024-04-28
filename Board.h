//
// Created by caitl on 18/04/2024.
//

#ifndef CA2_BUGS_LIFE_BOARD_H
#define CA2_BUGS_LIFE_BOARD_H

#include "Bug.h"
#include <vector>
#include <fstream>
#include <list>

class Board {
protected:
    // declare vector of pointers to Bug objects - type vector of pointers to Bug objects
    std::vector<Bug *> bug_vector;  // make the bug_vector private to the board class

    std::vector<Board *> board_vector; // hold the cells

    std::list<std::pair<int, int>> boardCells;

public:
    Board();

//    std::string bugHistoryToString;

    void fillBugsVector(std::ifstream &fin);

    void displayAllBugs();

    void findBugById();

    void tapBugBrd();

    void displayLifeHistory();

    void writeHistoryToFile(std::ostream &fileOutput);

    void displayAllCells();

    void makeBugsFight();
};

#endif //CA2_BUGS_LIFE_BOARD_H
