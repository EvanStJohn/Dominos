//
// Created by evan4 on 11/4/2019.
//

#include "CDeck.h"
#include <algorithm>    // std::shuffle
#include <vector>       // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

CDeck::CDeck()
{
    for (int i = 0; i <= 6; i++)
    {
        for (int k = 0; k <= 6; k++)
        {
            CDomino dom = CDomino(i, k);
            deck.push_back(dom);
        }
    }
}

// I have no clue if this works
void CDeck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    std::shuffle(deck.begin(), deck.end(), e);
}

int CDeck::size()
{
    return deck.size();
}

void CDeck::deal(CPlayer *player)
{
    // need to figure out how to remove piece and deal to player
}

std::vector<CDomino> CDeck::getDeck()
{
    return deck;
}
