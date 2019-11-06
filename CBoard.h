//
// Created by evan4 on 11/4/2019.
//

#ifndef DOMINOS_CBOARD_H
#define DOMINOS_CBOARD_H


#include <vector>
#include "CDomino.h"

class CBoard {
private:
    int front;
    int end;
    std::vector<CDomino> train;
public:
    void playFirstTile(CDomino tile);
    void playTile(CDomino tile, int location);
    int getFront();
    int getEnd();
    void printBoard();
};


#endif //DOMINOS_CBOARD_H
