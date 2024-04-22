//
// Created by caitl on 18/04/2024.
//

#include <iostream>
#include <fstream> //   to access file input and output
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <string>
#include <sstream>

using namespace std;

Board::Board(){} // board constructor

// take in reference to file input and bugs vector
void Board::fillBugsVector(ifstream &fin) {
    /**
     *  Assign variables from reading in the text file
     *
     *  need to also check for ';'
     *  Check if the first character in a line is C or H
     *  If its C then create a crawler object with the data
     *  If its H then create a hopper object with the data - extra field (hopLength)

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

        while (getline(s, newString,
                       ';')) {   // taking in the stringstream, new string and semicolon - split the string when a ";" is found
            bugWithoutDelimiter.push_back(newString);      // push the new string into the vector
        }

        if (bugWithoutDelimiter.size() >=
            6) {         // size >= 6 as a bug would have no more than 6 fields (crawler = 5 , hopper = 6)
            string bugType = bugWithoutDelimiter[0];
            int id = stoi(
                    bugWithoutDelimiter[1]);     // using the method stoi() to convert the strings to ints and storing them in bug field variables
            int x = stoi(
                    bugWithoutDelimiter[2]);      // getting the bug fields based on the position in the bugWithoutDelimiter vector
            int y = stoi(bugWithoutDelimiter[3]);
            int direction = stoi(bugWithoutDelimiter[4]);
            int size = stoi(bugWithoutDelimiter[5]);

            if (bugWithoutDelimiter[0] == "C") {           // checking the bug type - Crawler
                cout << "this is a crawler bug" << endl;   // TODO: before upload take out "this is a crawler bug" etc
                cout << "bug type " << bugType << endl;
                cout << "bug id " << id << endl;
                cout << "x " << x << endl;
                cout << "y " << y << endl;
                cout << "direction " << direction << endl;
                cout << "size " << size << endl;
                cout << " " << endl;

                // creating a new crawler bug based on the fields that have been taken in from the text file
                bugPtr = new Crawler(id, x, y, static_cast<Direction>(direction), size, alive);

            } else if (bugWithoutDelimiter[0] == "H") {           // checking the bug type - Hopper
                int hopLength = stoi(bugWithoutDelimiter[6]); // only getting the hopLength if the bug is a hopper

                cout << " this is a hopper bug" << endl;
                cout << " bug type " << bugType << endl;
                cout << "bug id " << id << endl;
                cout << "x " << x << endl;
                cout << "y " << y << endl;
                cout << "direction " << direction << endl;
                cout << "size " << size << endl;
                cout << "hop length " << hopLength << endl;

                bugPtr = new Hopper(id, x, y, static_cast<Direction>(direction), size, hopLength, alive);
            } else {
                cout << "There are no hopper or crawler bugs in the file." << endl;
            }
        }

        // add the crawler and hopper bugs to the bug vector
        bug_vector.push_back(bugPtr);
    }
    // print bug vector
    cout << " vector of bugs: " << endl;

    vector<Bug *>::size_type size = bug_vector.size();

    for (int i = 0; i < size; i++) {
        cout << bug_vector.at(i) << endl;
    }
}

void Board::displayAllBugs() {
    cout << "**************    DISPLAYING ALL BUGS    **************" << endl;
    // iterate through the bugs vector and call the print method
    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {
        Bug* b = *iter;     // dereference the iter and assign to pointer to bug object b
        b->print();         // printing all bugs - separate crawler and hopper print methods
    }
}

void Board::findBugById() {
    int inputId;
    bool bugFound;

    cout << "**************    FIND A BUG    **************" << endl;
    cout << "Please Enter the Bug ID you would like to find: " << endl;       // ask the user for a bug ID
    cin >> inputId;

    for (auto iter = bug_vector.begin(); iter != bug_vector.end(); iter++) {      // iterate through the bug_vector to find the bugID
        Bug* b = *iter;         // dereference the iter and assign to pointer to bug object b
        if(b->getBugId() == inputId){    // checking if the bugId is equal to the input id from the user
            cout << "Bug " << inputId << " has been found." << endl;      // bug is found
            b->print();         // printing the bug details
            bugFound = true;    // set to true
        }
    }

    // outside of the for loop - checking if the input bug id  has NOT been found
    // then output the message - inside the for loop it will repeat this message for every bug
    if(!bugFound){
        cout << "Bug " << inputId << " has not been found." << endl;      // bug is found
    }
}

void Board::tapBugBrd(){
    cout << "**************    TAP THE BUG BOARD    **************" << endl;
    for(Bug* bugPtr: bug_vector){   // call the move methods for crawler and hopper bugs
        bugPtr->move();             // use this for menu option 4 - tap the board bug
    }
}
