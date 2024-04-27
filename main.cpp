#include <iostream>
#include <fstream> //to access file input and output
#include <ostream>
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main() {
    Board brd;                                    // make a board object

    // read data from text file "bugs.txt"
    ifstream fin("bugs.txt");         //create input file stream to the text file "bugs.txt"
    if (fin)                             //checking the file input is opened correctly
    {
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
                    // load data from the file and fill the vector
                    brd.fillBugsVector(fin);
                    break;
                }
                case 2: {
                    // display all bugs
                    brd.displayAllBugs();
                    break;
                }
                case 3: {
                    //find a bug (take in user input of id)
                    brd.findBugById();
                    break;
                }
                case 4: {
                    //tap bug board (moves all bugs - fight/eat)
                    brd.tapBugBrd();
                    //TODO: when calling the eat function - need to check if there are bugs in the same cell
                    // for the eat functionality
                    break;
                }
                case 5: {
                    //display life history of all bugs (path)
                    brd.displayLifeHistory();
                    break;
                }
                case 6: {
                    //display all cells listing their bugs
                    brd.displayAllCells();
                    break;
                }
                case 7: {
                    //run simulation (generates a tap every second)
                    break;
                }
                case 8: {
                    //write life history of all bugs to file before exit
                    // create a new text file for this
                    // creating a file output stream to bugs_life_history_date_time.out.
                    ofstream fileOutput("bugs_life_history_date_time.out");

                    if (fileOutput) {   // checking file is opened correctly
                        brd.writeHistoryToFile(fileOutput);
                    } else {
                        cout << "Unable to open file." << endl;
                    }

                    fileOutput.close();
                }
            }

        } while (choice != 8);         // 8 is the option to exit - will write the life history of all bugs to file

    } else {
        cout << "Unable to open the file" << endl;
    }
    fin.close();

    return 0;
}


