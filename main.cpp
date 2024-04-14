#include <iostream>
#include <fstream> //to access file input and output
#include <vector>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include <string>

using namespace std;

//function prototypes
void read_bug_by_bug(ifstream &);

void read_bugs(ifstream &);

void fillBugsVector(vector<Bug *> &vec);

int main() {

    // read data from text file "bugs.txt"
    ifstream fin("bugs.txt");  //create input file stream to the text file "bugs.txt"
    if (fin)                      //checking the file input is opened correctly
    {
        cout << "Read bugs in one bug at a time: " << endl;
        read_bugs(fin);   //storing each bug being read in to the text file
    } else {
        cout << "Unable to open the file" << endl;
    }
    fin.close();

    Bug *bugPtr; //Point at any object derived from the Bug class
    bugPtr = nullptr;

    // declare vector of pointers to Bug objects - type vector of pointers to Bug objects
//  vector<Bug *> bug_vector;

//    fillBugsVector(bug_vector);

    return 0;
}

// Method to read in bugs from text file "bugs.txt"
// Displaying one bug per line
void read_bug_by_bug(ifstream &ifstream1) {
    string aBug;
    while (getline(ifstream1, aBug))      //while not at the end of a file, read a line
    {
        cout << aBug << endl;                  //print each bug on a new line
    }
}

// take in the vector in here 
void read_bugs(ifstream &ifstream1) {
    /**
     *  Assign variables from reading in the text file
     *
     *  Check if the first character in a line is C or H
     *  If its C then create a crawler object with the data
     *  If its H then create a hopper object with the data - extra field (hopLength)
     *  need to also check for ';'

     *  Populate the vector with these objects
     *
     */


//    int id;
//    pair<int, int> position;  //x,y
//    Direction direction;
//    int size;
//    bool alive;
//    int x;
//    int y;

    string line;
    while (getline(ifstream1, line)) {
//        https://stackoverflow.com/questions/23064400/read-first-n-letters-from-file-to-a-string

// Bug fields
        int id, x, y, direction, size, hopLength;
        bool alive;
        string str;
        int length = 10;

        vector<Bug *> bug_vector;    // vector of bugs

//        str.resize(length, ' ');

        // variables
        char *beginningOfFile = &*str.begin();  // to start iterating through file
        char semiColonFound = ';';              // semi colon
        //char bugType = line[0];                 // first character in the line , c = crawler, h = hopper



//        if (bugType == 'C') {
//            cout << "this is a crawler bug" << endl;
//
////            // extracting the crawler bug fields from the text file
////            istringstream1 >> id >> x >> y >> direction >> size >> alive;
////
////            // create a crawler
////            Crawler *crawlerBug = new Crawler(id, x, y, direction, size, alive);
////
////            // pushing the crawler bug into the vector
////            bug_vector.push_back(crawlerBug);
//
//
////            cout << " crawler bug " << crawlerBug;
//
//        } else if (bugType == 'H') {
//            cout << "this is a hopper bug" << endl;
//        } else {
//            cout << "There are no Crawler or Hopper bugs in this text file.";
//        }



//        // for loop - iterate through each character in each line - https://cplusplus.com/forum/beginner/24492/
//        for (int i = 0; i < line.length(); ++i) {
//            char ch = line[i];
//            cout << ch << endl;
//        }

    for (int i = 0; i < line.length(); ++i) {
        string bugType = line.substr(i, 1);
        string id = line.substr(2, 3);
        string x = line.substr(6, 1);
        string y = line.substr(8, 1);
        string size = line.substr(10, 1);

        cout << "bug type " << bugType << endl;
        cout << "bug id " << id << endl;
        cout << "x " << x << endl;
        cout << "y" << y << endl;
        cout << "size" << size << endl;

        //stoi

        // crawler bug
        if (bugType == "C") {
            cout << "this is a crawler bug" << endl;
//            Crawler crawlerBug = new Crawler(bugType, id, x, y, size);
        } else if (bugType == "H") {
            cout << "this is a hopper bug" << endl;
            string hopLength = line.substr(12, 1);
            cout << "hop length" << hopLength << endl;

        }else{
            cout << "There are no crawler or hopper bugs in the file." << endl;
        }

    }


//        ifstream1.read(beginningOfFile, length);
//
//        cout << *beginningOfFile << endl;
//        cout << length << endl;

//        while (singleChar != semiColonFound){
//            cout << singleChar;
//            ifstream1.get(singleChar);
//        }

//            if (*beginningOfFile == crawlerType) {
//                cout << "this is a crawler bug" << endl;
//                bug_vector.push_back(new Crawler(id, x, y, static_cast<Direction>(direction), size, alive));
//
//            } else if (*beginningOfFile == hopperType) {
//                cout << "this is a hopper bug" << endl;
//                bug_vector.push_back(new Hopper(id, x, y, static_cast<Direction>(direction), size, alive, hopLength));
//
//            } else {
//                cout << "There are no Crawler or Hopper bugs in this text file.";
//            }

        }
}


void fillBugsVector(vector<Bug *> &vec) {       //reference to a vector
    // dynamically allocate a hopper or crawler bug object
    // pass it into a unique_ptr constructor
    // unique_ptr added into vector as an element

//    vectorRef.push_back(unique_ptr<Bug>(new Hopper()));

    // populate the vector by reading data from a text file
    // push the bug object addresses on to the bug_vector from text file - dynamically

    // Using a SMART POINTER there is no need to remember to free the associated memory

}

