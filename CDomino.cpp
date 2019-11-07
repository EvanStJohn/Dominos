//
// Created by evan4 on 11/4/2019.
//

#include "CDomino.h"
#include <iostream>
using namespace std;

CDomino::CDomino(int l, int r)
{
    left = l;
    right = r;
}

int CDomino::getLeft()
{
    return left;
}

int CDomino::getRight()
{
    return right;
}

int CDomino::getTotal()
{
    return left + right;
}

void CDomino::flip()
{
    int num = right;
    right = left;
    left = num;
}

void CDomino::printDomino()
{
    cout << "[" <<  left << " | " << right << "]";
}