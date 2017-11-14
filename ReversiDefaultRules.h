
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#ifndef EX02_REVERSIDEFAULTRULES_H
#define EX02_REVERSIDEFAULTRULES_H


#include "GameRules.h"

class ReversiDefaultRules : public GameRules {
public:
    ReversiDefaultRules(Board &board1);

    /**
     * make a vector with all the possible moves of symbol.
     * @param symbol The current player.
     * @return The possible moves vector.
     */
    vector<Point*> makePossibleMoves(owner symbol);

    /**
     * Check all the surrounding cell of Point p of the player symbol.
     * @param p Point to check his surrounding.
     * @param symbol The current player.
     */
    void checkSurround(Point &p, owner symbol);

    /**
     * Move along the dRow & dCol direction and look for possible moves.
     * @param p The point to begin with.
     * @param symbol The current player.
     * @param dRow The difference in row.
     * @param dCol The difference in col.
     */
    void moveAlong(Point p ,owner symbol, short dRow, short dCol);

    /**
     * Free all the points in the vector of "symbol" player.
     * @param symbol The player to delete his vector.
     */
    void freePointsInVec(owner symbol);
};


#endif //EX02_REVERSIDEFAULTRULES_H
