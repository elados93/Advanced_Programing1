// Created by Elad Aharon on 28/10/17.
// ID: 311200786

#ifndef EX02_PLAYER_H
#define EX02_PLAYER_H

#include "Point.h"

class Player {
public:
    char getSymbol() const;
    virtual Point getMove() = 0;

protected:
    char symbol;
};


#endif //EX02_PLAYER_H
