#include <iostream>
#include <fstream> //to access file input and output
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <string>
#include <sstream>

using namespace std;

//function prototypes
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

//    for(Bug* ptr: bug_vector){
//        delete ptr;                 // free the memory
//    }
//
//    bug_vector.clear();             // clear the contents of the bug_vector

    return 0;
}

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
                // display all bugs
                //TODO: create function displaying bugs from the vector - showing id, type, location, size , direction, hopLength, status (dead or alive)
                break;
            }
            case 3:{
                //find a bug (take in user input of id)
                break;
            }
            case 4:{
                //tap bug board (moves all bugs - fight/eat)
                //TODO: when calling the move function - need to check if there are bugs in the same cell
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



