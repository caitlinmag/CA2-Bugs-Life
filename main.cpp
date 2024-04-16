#include <iostream>
#include <fstream> //to access file input and output
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include <string>
#include <sstream>

using namespace std;

//function prototypes
void fillBugsVector(ifstream &fin, vector<Bug *> &bug_vector);   // using reference to file input and the bugs vector
void displayMenu();


int main() {
    vector<Bug *> bug_vector;        // declare vector of pointers to Bug objects - type vector of pointers to Bug objects

    // read data from text file "bugs.txt"
    ifstream fin("bugs.txt");         //create input file stream to the text file "bugs.txt"
    if (fin)                             //checking the file input is opened correctly
    {
        cout << "Read bugs in one bug at a time: " << endl;
        fillBugsVector(fin, bug_vector);               //storing each bug being read in to the text file
        displayMenu();
    } else {
        cout << "Unable to open the file" << endl;
    }
    fin.close();

    for(Bug* bugPtr: bug_vector){   // call the move methods for crawler and hopper bugs
        bugPtr->move();             // use this for menu option 4 - tap the board bug
    }

//    for(Bug* ptr: bug_vector){
//        delete ptr;                 // free the memory
//    }
//
//    bug_vector.clear();             // clear the contents of the bug_vector

    return 0;
}


// take in reference to file input and bugs vector
void fillBugsVector(ifstream &fin, vector<Bug *> &bug_vector) {
    /**
     *  Assign variables from reading in the text file
     *
     *  Check if the first character in a line is C or H
     *  If its C then create a crawler object with the data
     *  If its H then create a hopper object with the data - extra field (hopLength)
     *  need to also check for ';'

     *  Populate the vector with these objects
     */

    string line;

    while (getline(fin, line)) {

        /**
         *      Used this reference to learn how to split the string from the semi colon delimiter
         *      https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
         */

        string newString;

        stringstream s(line);           // using stringstream to extract strings from each line of the text file

        vector<string> bugWithoutDelimiter; // Creating a vector to hold the bug strings after the semicolons are removed

        Bug *bugPtr; // Point at any object derived from the Bug class

        bugPtr = nullptr;

        while (getline(s, newString,';')) {   // taking in the stringstream, new string and semicolon - split the string when a ";" is found
            bugWithoutDelimiter.push_back(newString);      // push the new string into the vector
        }

        bool alive;

        if (bugWithoutDelimiter.size() >=6) {         // size >= 6 as a bug would have no more than 6 fields (crawler = 5 , hopper = 6)
            string bugType = bugWithoutDelimiter[0];
            int id = stoi(bugWithoutDelimiter[1]);     // using the method stoi() to convert the strings to ints and storing them in bug field variables
            int x = stoi(bugWithoutDelimiter[2]);      // getting the bug fields based on the position in the bugWithoutDelimiter vector
            int y = stoi(bugWithoutDelimiter[3]);
            int direction = stoi(bugWithoutDelimiter[4]);
            int size = stoi(bugWithoutDelimiter[5]);

            if (bugWithoutDelimiter[0] == "C") {           // checking the bug type - Crawler
                cout << "this is a crawler bug" << endl;
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

//
//void fillBugsVector(vector<Bug *> &vec) {       //reference to a vector
//    // dynamically allocate a hopper or crawler bug object
//    // pass it into a unique_ptr constructor
//    // unique_ptr added into vector as an element
//
////    vectorRef.push_back(unique_ptr<Bug>(new Hopper()));
//
//    // populate the vector by reading data from a text file
//    // push the bug object addresses on to the bug_vector from text file - dynamically
//
//    // Using a SMART POINTER there is no need to remember to free the associated memory
//
//}

void displayMenu() {

    int choice;

    do {
        cout << "***************** WELCOME TO THE BUG'S LIFE MENU *****************" << endl;
        cout << "*            1.Initialise Bug Board                              *" << endl;
        cout << "*            2.Display All Bugs                                  *" << endl;
        cout << "*            3.Find a Bug                                        *" << endl;
        cout << "*            4.Tap the Bug Board                                 *" << endl;
        cout << "*            5.Display Life history of all Bugs                  *" << endl;
        cout << "*            6.Display all Cells listing their Bugs              *" << endl;
        cout << "*            7.Run simulation                                    *" << endl;
        cout << "*            8.Exit                                              *" << endl;
        cout << "******************************************************************" << endl;

        cout << "Please Enter a number from the menu above:" << endl;

        // take in user input
        cin >> choice;
        switch (choice) {
            case 1: {
                // load data from the file
                break;
            }
            case 2: {
                //display all bugs
                break;
            }
            case 3:{
                //find a bug (take in user input of id)
                break;
            }
            case 4:{
                //tap bug board (moves all bugs - fight/eat)
                break;
            }
            case 5:{
                //display life history of all bugs (path)
                break;
            }
            case 6:{
                //display all cells listing their bugs
                break;
            }
            case 7:{
                //run simulation (generates a tap every second)
                break;
            }
            case 8:{
                //write life history of all bugs to file before exit
            }
        }


    } while (choice != 8);         // 8 is the option to exit - will write the life history of all bugs to file

}



