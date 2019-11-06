//
// Created by evan4 on 11/4/2019.
//

#ifndef DOMINOS_CDECK_H
#define DOMINOS_CDECK_H


#include <vector>
#include "CDomino.h"
#include "CPlayer.h"

class CDeck {
private:
    std::vector<CDomino> deck;
public:
    void shuffle();
    int size();
    void deal(CPlayer player);
    std::vector<CDomino> getDeck();
};


#endif //DOMINOS_CDECK_H
