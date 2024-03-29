#include <iostream>
#include <fstream> //to access file input and output

using namespace std;

//function prototypes
void read_line_by_line(ifstream&);
void read_word_by_word(ifstream&);

int main() {

    ifstream fin("bugs.txt"); //create input file stream to the file "bugs.txt"
    if(fin)                      //checking the file input is opened correctly
    {
        cout << "\n Read bugs in one line at a time: " << endl;
        read_line_by_line(fin);
    }else
    {
        cout << "Unable to open the file" << endl;
    }
    fin.close();


    return 0;
}

void read_line_by_line(ifstream & ifstream1){
    string line;
    while( getline(ifstream1,line)){     //while not at the end of a file - read line
        cout << line << " ";
    }
}

void read_word_by_word(ifstream & ifstream1){
    string aWord;
    while(!ifstream1.eof()){
        ifstream1 >> aWord;
        cout << aWord << " ";
    }

}
