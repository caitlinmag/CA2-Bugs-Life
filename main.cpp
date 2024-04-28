#include <iostream>
#include <fstream> //to access file input and output
#include <ostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"

using namespace std;

struct bug {
    int x, y;
    int moveXBy = 1;
    int moveYBy = 1;
    int id;
    int cellSize;
    sf::CircleShape shape;
    sf::Texture texture;

    bug(int i, int cellSize) {
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Red);
        x = rand() % 10;
        y = rand() % 10;
        id = i;
        this->cellSize = cellSize;
        shape.setTexture(&texture);
    }

    void move() {
        x += moveXBy;
        y += moveYBy;

        if (x >= 10 || x == 0) {
            moveXBy *= -1;
        }
        if (y >= 10 || y == 0) {
            moveYBy *= -1;
        }
        cout << id << ":" << x << " " << y << endl;
    }

    void draw(sf::RenderWindow &window) {
        shape.setPosition(x * cellSize, y * cellSize);
        window.draw(shape);
    }
};

int main() {
    Board brd;   // make a board object

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
            cout << "*            9.GUI (SFML)                                        *" << endl;
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
                    //tap bug board - move all bugs
                    brd.tapBugBrd();
                    // then make bugs fight/eat
                    brd.fightBugs();
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
                    // run simulation (generates a tap every second)
                    // I didn't have time to attempt the run simulation - also my eat/fight functionality isn't working correctly
                    // therefore I'm not sure how I would have gone about implementing the method for running the simulation
                    break;
                }
                case 8: {
                    //write life history of all bugs to file before exit
                    // create a new text file for this
                    // creating a file output stream to bugs_life_history_date_time.out.
                    ofstream fileOutput("bugs_life_history_date_time.out");

                    if (fileOutput) {   // checking file is opened correctly
                        // calling the method to write the history to file
                        brd.writeHistoryToFile(fileOutput);
                    } else {
                        cout << "Unable to open file." << endl;
                    }

                    fileOutput.close();
                }
                case 9: {
                    // GUI SFML Implementation
                    // using the ball example as a starting point
                    srand(time(NULL));
                    sf::RenderWindow window(sf::VideoMode(400, 400), "Bugs Life");

                    // I planned to add in the bug images but I couldn't get it to work as I didn't have enough time left

                    sf::Texture texture1;
                    texture1.loadFromFile("crawlerBug.png");

                    sf::Texture texture2;
                    texture1.loadFromFile("hopperBug.png");

                    sf::Texture texture3;
                    texture1.loadFromFile("ladybird.png");

                    vector<bug> bugs;
                    for (int i = 0; i < 3; i++) {
                        bugs.push_back(bug(i, 50));
                    }

                    int size = 10;
                    vector<sf::RectangleShape> board;
                    bool blk = true;

                    for (int x = 0; x < size; x++) {
                        for (int y = 0; y < size; y++) {
                            sf::RectangleShape rect(sf::Vector2f(50, 50));
                            rect.setPosition(x * 50, y * 50);
                            if (blk) {
                                rect.setFillColor(sf::Color::Magenta);

                            } else {
                                rect.setFillColor(sf::Color::White);
                            }
                            blk = !blk;
                            board.push_back(rect);
                        }
                        blk = !blk;
                    }
                    while (window.isOpen()) {
                        sf::Event event;
                        while (window.pollEvent(event)) {
                            if (event.type == sf::Event::Closed)
                                window.close();
                            if (event.type == sf::Event::MouseButtonReleased) {
                                if (event.mouseButton.button == sf::Mouse::Left) {
                                    for (bug &b: bugs) {
                                        b.move();
                                    }
                                }

                            }
                            if (event.type == sf::Event::KeyReleased) {
                                cout << event.key.code << endl;
                                cout << sf::Keyboard::C << endl;
                                if (event.key.code == sf::Keyboard::Up) {
                                    for (bug &b: bugs) {
                                        b.move();
                                    }
                                }
                            }

                        }

                        window.clear(sf::Color::White);
                        for (sf::RectangleShape &rect: board) {
                            window.draw(rect);
                        }

                        for (bug &b: bugs) {

                            b.draw(window);
                        }
                        window.display();

                    }
                }
            }

        } while (choice != 8);         // 8 is the option to exit - will write the life history of all bugs to file

    } else {
        cout << "Unable to open the file" << endl;
    }
    fin.close();

    return 0;
}


