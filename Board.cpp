//
// Created by caitl on 18/04/2024.
//
#include <iostream>
#include <fstream> //   to access file input and output
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Ladybird.h"
#include "Board.h"
#include <string>
#include <sstream>
#include <list>

using namespace std;

Board::Board() {} // board constructor

// fill the board - 10 x 10
// maybe using a list of pairs similar to the path starting with (0,0) and max is (9,9)

void Board::fillBugsVector(ifstream &fin) {
    /**
     *  Assign variables from reading in the text file
     *
     *  need to also check for ';'
     *  Check if the first character in a line is C or H
     *  If its C then create a crawler object with the data
     *  If its H then create a hopper object with the data - extra field (hopLength)
        I read in my bug (ladybird) the same way
     *  Populate the vector with these objects
     */

    string line;

    while (getline(fin, line)) {

        bool alive = true; //
        /**
         *      Used this reference to learn how to split the string from the semi colon delimiter
         *      https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
         */

        string newString;

        stringstream s(line);           // using stringstream to extract strings from each line of the text file

        vector<string> bugWithoutDelimiter; // Creating a vector to hold the bug strings after the semicolons are removed

        Bug *bugPtr; // Point at any object derived from the Bug class

        bugPtr = nullptr;

        while (getline(s, newString, ';')) {   // taking in the stringstream, new string and semicolon
            // split the string when a ";" is found
            bugWithoutDelimiter.push_back(newString);      // push the new string into the vector
        }

// size >= 6 as a bug would have no more than 6 fields (crawler = 5 , hopper = 6)
// using the method stoi() to convert the strings to ints and storing them in bug field variables
// getting the bug fields based on the position in the bugWithoutDelimiter vector
        if (bugWithoutDelimiter.size() >= 6) {
            string bugType = bugWithoutDelimiter[0];
            int id = stoi(bugWithoutDelimiter[1]);
            int x = stoi(bugWithoutDelimiter[2]);
            int y = stoi(bugWithoutDelimiter[3]);
            int direction = stoi(bugWithoutDelimiter[4]);
            int size = stoi(bugWithoutDelimiter[5]);

            // checking the bug type - Crawler
            if (bugWithoutDelimiter[0] == "C") {
                cout << "This is a Crawler Bug" << endl;
                cout << "Bug Type: " << bugType << endl;
                cout << "Bug ID: " << id << endl;
                cout << "Position x: " << x << endl;
                cout << "Position y: " << y << endl;
                cout << "Direction: " << direction << endl;
                cout << "Size: " << size << endl;
                cout << " " << endl;

                // creating a new crawler bug based on the fields that have been taken in from the text file
                bugPtr = new Crawler(id, x, y, static_cast<Direction>(direction), size, alive);

                // adding the Crawler bugs starting position to the path
                bugPtr->recordStartPosition();

                // checking the bug type - Ladybird
            } else if (bugWithoutDelimiter[0] == "L") {
                cout << "This is a Ladybird" << endl;
                cout << "Bug Type: " << bugType << endl;
                cout << "Bug ID: " << id << endl;
                cout << "Position x: " << x << endl;
                cout << "Position y: " << y << endl;
                cout << "Direction: " << direction << endl;
                cout << "Size: " << size << endl;
                cout << " " << endl;

                // ladybird would have the same fields as the crawler bug
                // creating a ladybird bug
                bugPtr = new Ladybird(id, x, y, static_cast<Direction>(direction), size, alive);
                // adding the ladybirds starting position to the path
                bugPtr->recordStartPosition();

            } else if (bugWithoutDelimiter[0] == "H") {           // checking the bug type - Hopper
                int hopLength = stoi(bugWithoutDelimiter[6]); // only getting the hopLength if the bug is a hopper

                cout << "This is a Hopper Bug" << endl;
                cout << "Bug Type: " << bugType << endl;
                cout << "Bug ID: " << id << endl;
                cout << "Position x: " << x << endl;
                cout << "Position y: " << y << endl;
                cout << "Direction: " << direction << endl;
                cout << "Size: " << size << endl;
                cout << "Hop Length: " << hopLength << endl;
                cout << " " << endl;

                bugPtr = new Hopper(id, x, y, static_cast<Direction>(direction), size, hopLength, alive);

                // adding the Hopper bugs starting position to the path
                bugPtr->recordStartPosition();
            } else {
                cout << "There are no hopper or crawler bugs in the file." << endl;
            }
        }
        // add the crawler, hopper and ladybird bugs to the bug vector
        bug_vector.push_back(bugPtr);
    }
}

void Board::displayAllBugs() {
    cout << "**************    DISPLAYING ALL BUGS    **************" << endl;
    // iterate through the bugs vector and call the print method
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug *bugPtr = *iter;     // dereference the iter and assign to pointer to bug object bugPtr
        bugPtr->print();         // printing all bugs - separate crawler, hopper and ladybird print methods
    }
// would have liked to add "alive" or "dead" for each bug but my eat functionality isn't working correctly
}

void Board::findBugById() {
    int inputId;
    bool bugFound;

    cout << "**************    FIND A BUG    **************" << endl;
    cout << "Please Enter the Bug ID you would like to find: " << endl;       // ask the user for a bug ID
    cin >> inputId;

    // iterate through the bug_vector to find the bugID
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug *bugPtr = *iter;         // dereference the iter and assign to pointer to bug object bugPtr
        if (bugPtr->getBugId() == inputId) {    // checking if the bugId is equal to the input id from the user
            cout << "Bug " << inputId << " has been found. \n" << endl;      // bug is found
            cout << "* BUG DETAILS *" << endl;
            bugPtr->print();         // printing the bug details
            bugFound = true;    // set to true
        }
    }

    // outside of the for loop - checking if the input bug id has NOT been found
    // then output the message
    // inside the for loop it will repeat this message for every bug, so I moved it to outside the loop
    if (!bugFound) {
        cout << "Bug " << inputId << " has not been found." << endl;      // bug is found
    }
}

void Board::tapBugBrd() {
    cout << "**************    TAP THE BUG BOARD    **************" << endl;
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug *bugPtr = *iter;
        bugPtr->move(); // calling move for all bugs
    }
}

void Board::fightBugs() {
    // implementing the eat functionality when the board is tapped
    cout << "**************    FIGHTING BUGS    **************" << endl;

    // iterate through cells on the board
    for (auto listIter = boardCells.begin(); listIter != boardCells.end(); listIter++) {
        pair<int, int> brdCells = *listIter;

        // use a counter to count how many bugs there is in each cell
        int count = 0;

        // make a vector to hold the bugs that are in the current cell
        vector<Bug *> bugs_in_cells;

        // iterate through the bug_vector to check if a bug is in the cell
        for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
            Bug *bugPtr = *iter;

            // firstly, checking if there is A BUG in the cell
            // get the bug position
            // if bug position matches the cell in the board
            if (bugPtr->getPosition() == brdCells) {
                // increment the count - to get how many bugs is in the cell
                count++;
                // add the bug or bugs to the vector
                bugs_in_cells.push_back(bugPtr);
            }

            // checking there are bugs in the cell
            if (count > 0) {
                // check if there is 1 bug in the cell
                if (count == 1) {
                    cout << "There is only one bug present in the cell: " << "(" << brdCells.first << "," << brdCells.second << ")" << endl;
                    // check if cell has 2 bugs
                } else if (count == 2) {
                    cout << "There are 2 bugs in the cell: " << "(" << brdCells.first << "," << brdCells.second << ")"
                         << endl;

                    // get the sizes of the 2 bugs in the cell
                    int bug1 = bugs_in_cells[0]->getSize();
                    int bug2 = bugs_in_cells[1]->getSize();

                    // biggest bug will eat the other
                    if (bug1 > bug2) {
                        // add the size of bug2 to the size of bug 1
                        bug1 += bug2;
                        // set the new size of bug1
                        bugs_in_cells[0]->setSize(bug1);
                        // set bug2 to dead
                        bugs_in_cells[1]->setAlive(false);
                        // output message that bug2 has been eaten
                        cout << "Bug " << bugs_in_cells[1]->getBugId() << " eaten by " << bugs_in_cells[0]->getBugId();
                        cout << "Bug " << bugs_in_cells[0]->getBugId() << " size is now: " << bugs_in_cells[0]->getSize();
                    } else if (bug2 > bug1) {
                        // bug 2 will eat bug 1
                        // add the size of bug1 to bug2
                        bug2 += bug1;
                        bugs_in_cells[1]->setSize(bug2);
                        // set bug1 to dead
                        bugs_in_cells[0]->setAlive(false);
                        cout << "Bug " << bugs_in_cells[0]->getBugId() << " eaten by " << bugs_in_cells[1]->getBugId();
                        cout << "Bug " << bugs_in_cells[1]->getBugId() << " size is now: " << bugs_in_cells[1]->getSize();
                    } else {
                        // bugs are the same size
                        cout << "The bugs " << bugs_in_cells[0]->getBugId() << " and " << bugs_in_cells[0]->getBugId()
                             << " are the same size";
                        // winner would need to be resolved at random
                    }

                    // check if there are more than 2 bugs in the cell
                } else if (count == 3) {
                    cout << "There are" << count << " bugs in the cell: " << "(" << brdCells.first << ","
                         << brdCells.second << ")" << endl;
                    // what i would do when there is more than 2 bugs in a cell:
                    // get the sizes of the 2 smallest bugs
                    // get the biggest bug - add the sizes of the 2 smallest bugs to the biggest bug size , as the biggest will eat both
                    // set the bool alive() to false for smallest bugs
                    // add to the path again
                }
            }
        }
    }
    // could have made a method for solving the winner at random if the bug sizes are the same
}

void Board::displayLifeHistory() {
    cout << "**************    DISPLAY BUG LIFE HISTORY    **************" << endl;
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug *bugPtr = *iter;
        bugPtr->printHistory(); // printing the life history of all bugs
        cout << endl;
    }
}

void Board::writeHistoryToFile(ostream &fileOutput) {
    cout << "**************    WRITING BUG HISTORY TO FILE    **************" << endl;
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug *bugPtr = *iter;
        string history = bugPtr->bugHistoryToString();  // writing the life history of all bugs to the file
        fileOutput << history << endl;
    }

    for (Bug *ptr: bug_vector) {
        delete ptr;                 // free the memory
    }
    bug_vector.clear();    // clear the contents of the bug_vector
}

void Board::displayAllCells() {
    cout << "**************    DISPLAYING ALL CELLS    **************" << endl;
    // populate the boardCells list to be 10 x 10
    // min (0,0) and max (9,9)
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // make the pair and add to the boardCells list
            boardCells.push_back(make_pair(i, j));
        }
    }

    // iterate through the board list
    for (auto listIter = boardCells.begin(); listIter != boardCells.end(); listIter++) {
        pair<int, int> brdCells = *listIter;
        // output the board cell e.g (0,0)
        cout << "(" << brdCells.first << "," << brdCells.second << ")" << ": ";

        // flag to keep track of the cell being empty or occupied by a bug/bugs
        bool emptyCell = true;

        // iterate through the bug_vector to check if a bug is in the cell
        for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
            Bug *bugPtr = *iter;

            // get the bug position
            // if bug position matches the cell in the board
            if (bugPtr->getPosition() == brdCells) {
                // there is currently a bug present in the board cell
                // print the bug type and the bug id
                cout << bugPtr->getBugType() << " " << bugPtr->getBugId() << ", ";
                // set to false
                emptyCell = false;
            }
        }

        // check if the cell is empty then output
        if (emptyCell) {
            // there are no bugs in the board cell
            cout << "empty";
        }
        cout << endl;
    }
}
