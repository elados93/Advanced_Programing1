
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#ifndef EX02_PRINTER_H
#define EX02_PRINTER_H

#include "Board.h"
#include "Player.h"


class Printer {

public:
    virtual void printBoard() = 0;
    virtual void printNextPlayerMove(Player &p, vector<Point*> v) = 0;
    virtual void printLastMove(Player &player, Point *point) = 0;
    virtual void printEndOfGame(Player &p, status status1) = 0;
    virtual void printError(possible_outcome outcome) = 0;
};



#endif //EX02_PRINTER_H
