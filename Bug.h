//
// Created by caitl on 29/03/2024.
//

#ifndef CA2_BUGS_LIFE_BUG_H
#define CA2_BUGS_LIFE_BUG_H

#endif //CA2_BUGS_LIFE_BUG_H

//Bug is the Abstract Base Class

class Bug{
protected:
    int id;                     //bug id
//    pair<int, int> position;  //co-ordinate pair (x,y)
    enum direction{             //direction the bug is facing
        North = 1,
        East = 2,
        South = 3,
        West = 4
    };

    int size;
    bool alive;
//    list<pair<int,int>> path;
//
//    virtual move(){
//    };

};