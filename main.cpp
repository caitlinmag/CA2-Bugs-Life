#include <iostream>
#include <fstream> //to access file input and output
#include <vector>
#include <memory> // for unique_ptr (SMART POINTER)
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

//function prototypes
void read_line_by_line(ifstream &);

void read_bug_by_bug(ifstream &);

void fillBugsVector();

int main() {


    // declare vector of pointers to Bug objects - type vector of pointers to Bug objects
//    vector<Bug*> bug_vector;
//    vector<unique_ptr<Bug>> bug_vector;

    // read data from text file "bugs.txt"


    ifstream fin("bugs.txt");  //create input file stream to the text file "bugs.txt"
    if (fin)                      //checking the file input is opened correctly
    {
        cout << "Read bugs in one bug at a time: " << endl;
        read_bug_by_bug(fin);   //storing each bug being read in to the text file
    } else {
        cout << "Unable to open the file" << endl;
    }
    fin.close();

    return 0;
}

// Method to read in bugs from text file "bugs.txt"
// Displaying one bug per line
void read_bug_by_bug(ifstream & ifstream1){
    string aBug;
    while(getline(ifstream1, aBug))      //while not at the end of a file, read a line
    {
        cout << aBug << endl;                  //print each bug on a new line
    }
}

void fillBugsVector(vector<unique_ptr<Bug>>& vectorRef()) {       //reference to a vector
    // dynamically allocate a hopper or crawler bug object
    // pass it into a unique_ptr constructor
    // unique_ptr added into vector as an element

//    vectorRef.push_black(unique_ptr<Bug>(new Hopper()));


    // populate the vector by reading data from a text file
    // push the bug object addresses on to the bug_vector from text file - dynamically

    // Using a SMART POINTER there is no need to remember to free the associated memory


}

