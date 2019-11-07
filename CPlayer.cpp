//
// Created by evan4 on 11/4/2019.
//

#include "CPlayer.h"
#include <iostream>
using namespace std;

CPlayer::CPlayer()
{
    id = NULL;
}

CPlayer::CPlayer(int idNum)
{
    id = idNum;
}

std::vector<CDomino> CPlayer::gethand()
{
    return hand;
}

int CPlayer::getId()
{
    return id;
}

void CPlayer::addPiece(CDomino domino)
{
    hand.push_back(domino);
}

void CPlayer::removePiece(int domino)
{
    hand.erase(hand.begin() + domino);
}

bool CPlayer::isEmpty()
{
    if (hand.size() == 0)
        return true;
    else
        return false;
}

bool CPlayer::hasPlay(int front, int end)
{
    for (int i = 0; i < hand.size(); i++)
    {
        if (front == hand.at(i).getLeft() || front == hand.at(i).getRight())
            return true;

        if (end == hand.at(i).getLeft() || end == hand.at(i).getRight())
            return true;
    }
    return false;
}

void CPlayer::showHand()
{
    cout << "here is your hand" << endl;

    for (int i = 0; i < hand.size(); i++)
    {
        hand.at(i).printDomino();
    }
    cout << endl;
}