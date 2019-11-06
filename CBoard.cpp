//
// Created by evan4 on 11/4/2019.
//

#include "CBoard.h"
#include <iostream>
using namespace std;

void CBoard::playFirstTile(CDomino tile)
{
    front = tile.getLeft();
    end = tile.getRight();
    train.push_back(tile);
}

void CBoard::playTile(CDomino tile, int location)
{
    if (location == 0) {
        if (tile.getLeft() == end) {
            end = tile.getRight();
            train.push_back(tile);
        }
        else {
            end = tile.getLeft();
            train.push_back(tile);
        }
    }
    if (location == 1) {
        if (tile.getLeft() == front) {
            front = tile.getRight();
            train.insert(train.begin(), tile);
        }
        else {
            front = tile.getLeft();
            train.insert(train.begin(), tile);
        }
    }
}

int CBoard::getFront()
{
    return front;
}

int CBoard::getEnd()
{
    return end;
}

void CBoard::printBoard()
{
    cout << "front: " << front << endl;
    cout << "end: " << end << endl;
    cout << "board:" << endl;
    for (int i = 0; i < train.size(); i++ )
    {
        train.at(i).printDomino();
    }
    cout << " " << endl;
}
