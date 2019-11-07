//
// Created by evan4 on 11/4/2019.
//

#ifndef DOMINOS_CPLAYER_H
#define DOMINOS_CPLAYER_H

#include <vector>
#include "CDomino.h"


class CPlayer {
private:
    int id;
    std::vector<CDomino> hand;
public:
    CPlayer(int idNum);
    CPlayer();
    std::vector<CDomino> gethand();
    int getId();
    void addPiece(CDomino domino);
    void removePiece(int domino);
    bool isEmpty();
    bool hasPlay(int front, int end);
    void showHand(); // for debug purpose
};


#endif //DOMINOS_CPLAYER_H
