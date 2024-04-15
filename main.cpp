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
void read_bugs(ifstream &fin) {
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
    vector<Bug *> bug_vector;    // vector of bugs

    while (getline(fin, line)) {
//        https://stackoverflow.com/questions/23064400/read-first-n-letters-from-file-to-a-string

// Bug fields
//        int id, x, y, direction, size, hopLength;
        bool alive;
        string str;
        int length = 10;


//        str.resize(length, ' ');

        // variables
        char *beginningOfFile = &*str.begin();  // to start iterating through file
        // semi colon
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


        /**
         *      Used this reference to learn how to split the string from the semi colon delimiter
         *      https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
         */

        string newString;

        stringstream s(line);

        vector<string> bugWithoutDelimiter; // vector of the bugs in txt file with the semi colon removed

        Bug *bugPtr; //Point at any object derived from the Bug class
        bugPtr = nullptr;

        while (getline(s, newString, ';')) {
            bugWithoutDelimiter.push_back(newString);  // push the new string into the vector
        }

        if(bugWithoutDelimiter.size() >= 6) {
            string bugType = bugWithoutDelimiter[0];
            int id = stoi(bugWithoutDelimiter[1]);
            int x = stoi(bugWithoutDelimiter[2]);
            int y = stoi(bugWithoutDelimiter[3]);
            int direction = stoi(bugWithoutDelimiter[4]);
            int size = stoi(bugWithoutDelimiter[5]);

            if (bugWithoutDelimiter[0] == "C") {
                cout << "this is a crawler bug" << endl;
                cout << "bug type " << bugType << endl;
                cout << "bug id " << id << endl;
                cout << "x " << x << endl;
                cout << "y " << y << endl;
                cout << "direction " << direction << endl;
                cout << "size " << size << endl;
                cout << " " << endl;

                bugPtr = new Crawler(id, x, y, static_cast<Direction>(direction), size, alive);

            } else if (bugWithoutDelimiter[0] == "H") {
                int hopLength = stoi(bugWithoutDelimiter[6]);

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


//        for (int i = 0; i < line.length(); i += 16) {
//            string bugType = line.substr(i, 1);
//            string readId = line.substr(2, 3);
//            string readX = line.substr(6, 1);
//            string readY = line.substr(8, 1);
//            string readDirection = line.substr(10, 1);
//            string readSize = line.substr(12, 2);
//
//            // convert strings to ints
//            int id = stoi(readId);
//            int x = stoi(readX);
//            int y = stoi(readY);
//            int direction = stoi(readDirection);
//            int size = stoi(readSize);
//
//            // crawler bug
//            if (bugType == "C") {
//                cout << "this is a crawler bug" << endl;
//                cout << "bug type " << bugType << endl;
//                cout << "bug id " << id << endl;
//                cout << "x " << x << endl;
//                cout << "y " << y << endl;
//                cout << "direction " << direction << endl;
//                cout << "size " << size << endl;
//                cout << " " << endl;
//
////                Bug* crawlerBug = new Crawler(id, x, y, static_cast<Direction>(direction), size, alive);
//
//            } else if (bugType == "H") {
//                cout << "this is a hopper bug" << endl;
//
//                cout << "bug type " << bugType << endl;
//                cout << "bug id " << id << endl;
//                cout << "x " << x << endl;
//                cout << "y " << y << endl;
//                cout << "direction " << direction << endl;
//                cout << "size " << size << endl;
//
//                string readHopLength = line.substr(i + 14, 1);
//
//                int hopLength = stoi(readHopLength);
//                cout << "hop length " << hopLength << endl;
//                cout << " " << endl;
//            } else {
//                cout << "There are no crawler or hopper bugs in the file." << endl;
//            }
//        }

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
    // print bug vector
    cout << " vector of bugs: " << endl;

    vector<Bug*>::size_type size = bug_vector.size();

    for(int i = 0; i < size; i++){
        cout << bug_vector.at(i) << endl;
    }
//
//    for(auto i: bug_vector){
//        cout << i << ' ';
//    }


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

