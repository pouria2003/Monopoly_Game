#ifndef BOARDSPACE_H
#define BOARDSPACE_H

class Player;

class BoardSpace
{
public:
    BoardSpace(int _space_num) : space_num(_space_num) {}
    virtual void playerOn(Player *) = 0;
    int space_num;
};

#endif // BOARDSPACE_H
