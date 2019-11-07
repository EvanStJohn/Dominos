#include <iostream>
#include "CDomino.h"
#include "CBoard.h"
#include "CDeck.h"
using namespace std;

class CGame {
private:
    CBoard board, *boardPointer;
    CDeck deck, *deckPointer;
    CPlayer p1, *p1Pointer;
    CPlayer p2, *p2Pointer;
    int winner = 0;
    int pass = 0;
public:
    void API(int startHandSize);
    void firstplay();
    void play(CPlayer *player);
    void checkWinner();
    int score(CPlayer loser);
    void result();
};

void CGame::API(int startHandSize)
{
    deck.shuffle();
    deckPointer = &deck;

    p1 = CPlayer(1);
    p2 = CPlayer(2);
    p1Pointer = &p1;
    p2Pointer = &p2;

    for (int i = 0; i < startHandSize; i++)
    {
        deck.deal(p1Pointer);
        deck.deal(p2Pointer);
    }

    board = CBoard();
    boardPointer = &board;

    firstplay();

    while (winner == 0 && pass < 2)
    {
        pass = 0;

        cout << "Player 1:" << endl;
        p1.showHand();
        cout << "player 1 decides to play" << endl;
        play(p1Pointer);
        checkWinner();

        if (winner == 0)
        {
            cout << "Player 2:" << endl;
            p2.showHand();
            cout << "player 2 decides to play" << endl;
            play(p2Pointer);
            checkWinner();
        }
    }

    result();
}

void CGame::firstplay()
{
    vector<CDomino> hand = p1.gethand();
    CDomino firstTile = hand.at(0);

    cout << "Player 1:" << endl;
    p1.showHand();
    cout << "player 1 decides to play" << endl;
    firstTile.printDomino();
    cout << endl;
    board.playFirstTile(firstTile);
    board.printBoard();
    cout << endl;
    p1.removePiece(0);

    cout << "Player 2:" << endl;
    p2.showHand();
    cout << "Player 2 decides to play" << endl;
    play(p2Pointer);
}

void CGame::play(CPlayer *player)
{
    vector<CDomino> hand = player->gethand();
    bool played = false;

    for (int i = 0; i < hand.size(); i++) {
        CDomino tile = hand.at(i);

        if (tile.getLeft() == board.getFront() || tile.getRight() == board.getFront()) {
            tile.printDomino();
            cout << endl;
            board.playTile(tile, 1);
            board.printBoard();
            cout << endl;
            player->removePiece(i); // will not work
            played = true;
            break;
        }

        if (tile.getLeft() == board.getEnd() || tile.getRight() == board.getEnd()) {
            tile.printDomino();
            cout << endl;
            board.playTile(tile, 0);
            board.printBoard();
            cout << endl;
            player->removePiece(i); // will not work
            played = true;
            break;
        }
    }

        if(!played)
        {
            cout << "no tiles and draws a new tile" << endl;
            board.printBoard();
            cout << endl;

            if(deck.getDeck().size() != 0)
            {
                deck.deal(player);
            }
            else
            {
                pass++;
            }
        }

}

void CGame::checkWinner()
{
    if (p1.gethand().size() == 0)
    {
        winner = 1;
    }

    if (p2.gethand().size() == 0)
    {
        winner = 2;
    }
}

int CGame::score(CPlayer loser)
{
    vector<CDomino> hand = loser.gethand();
    int sum = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        sum += hand.at(i).getTotal();
    }
    return sum;
}

void CGame::result()
{
    if (winner == 1)
    {
        cout << "Player 1 wins the game with " << score(p2) << + " points" << endl;
    }
    else if (winner == 2)
    {
        cout << "Player 2 wins the game with " << score(p1) << + " points" << endl;
    }
    else
    {
        cout << "the game has ended in a tie" << endl;
    }
}


int main() {
    CGame game;
    game.API(7);

    return 0;
}