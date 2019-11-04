//
// Created by evan4 on 11/4/2019.
//

#ifndef DOMINOS_CDOMINO_H
#define DOMINOS_CDOMINO_H


class CDomino {
private:
    int left, right;
public:
    CDomino(int l, int r);
    int getLeft();
    int getRight();
    void flip();
    void printDomino();
};


#endif //DOMINOS_CDOMINO_H
