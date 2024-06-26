//
// Created by caitl on 29/03/2024.
//

#ifndef CA2_BUGS_LIFE_BUG_H
#define CA2_BUGS_LIFE_BUG_H

#include <utility>
#include <list>
#include <string>

enum Direction {             //direction the bug is facing
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

class Bug {          //abstract base class Bug
protected:
    int id;

    // co-ordinate pair (x,y) - (0,0) is the top left hand cell
    std::pair<int, int> position;

    // a variable of type Direction
    Direction direction;

    // bug size will initially be 1 - 20
    int size;

    // bug life status - set to true initially (false when bug has been eaten)
    bool alive;

    std::list<std::pair<int, int>> path;    //path taken by bug (list of positions on grid)

public:
    virtual ~Bug(); //virtual Bug destructor - can be overridden in crawler, and hopper class

    int getBugId() const;

    bool getAlive() const;

    void setAlive(bool alive);

    void setSize(int size);

    int getSize() const;

    const std::pair<int, int> &getPosition() const;

    static std::string directionToString(Direction direction) ;

    bool operator>(Bug const &obj);

    Bug operator+(const Bug &otherBug);

    // Used to move a bug from current position to new position
    // this will be based on rules for the bug type
    // must use a pure virtual function (no implementation for Bug base class)
    // pure virtual function - cannot make an instance of Bug - every class derived from Bug will be forced to implement move()
    virtual void move() = 0;

    // check if bug is at the edge of board
    // AND if bug is facing in edge direction = way is blocked
    // method used by move() function
    bool isWayBlocked();
    virtual void setRandomDirection() = 0;
    virtual void print() const = 0;
    virtual void printHistory() const = 0;
    virtual std::string bugHistoryToString()  = 0;
    virtual std::string getBugType();
    virtual void recordStartPosition() = 0;
};
#endif //CA2_BUGS_LIFE_BUG_H
