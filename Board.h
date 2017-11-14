// Created by Elad Aharon on 28/10/17.
// ID: 311200786

#ifndef EX02_BOARD_H
#define EX02_BOARD_H


#include "Cell.h"

class Board {
public:
    Board(int row , int col); // Constructor
    Board(const Board &board); // Copy Constructor
    ~Board(); // Destructor

    /**
     * Initialize the board with empty cells and puts 2 cells of player 1
     * and 2 cells of player 2 in the middle.
     */
    void initBoard();
    void markCell(Point &p, owner symbol);
    bool isCellEmpty(Point &p) const;
    bool isBoardFull() const;
    bool isInBoard(Point &p) const;
    int getRow() const;
    int getCol() const;
    Cell getCell(Point &p) const;

private:
    int row;
    int col;
    Cell** matrix; // (row x col) dimensions matrix of Cell objects.
};


#endif //EX02_BOARD_H
