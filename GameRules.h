
// Created by Elad Aharon on 29/10/17.
// ID: 311200786

#ifndef EX02_GAMERULES_H
#define EX02_GAMERULES_H


#include <vector>
#include "Board.h"
#include "GenralDef.h"

using namespace std;

class GameRules {
public:
    GameRules(Board &board1); // Constructor.
    virtual ~GameRules(); // Destructor.

    /**
     *  Make the vector of possible moves of "symbol" and also returns it.
     *  Notice the difference with getPossibleMoves function that's only returns it.
     * @param symbol The player.
     * @return The vector of possible points of symbol.
     */
    virtual vector<Point*> makePossibleMoves(owner symbol);

    /**
     * Make a single move of "symbol" at point p.
     * @param p Given point to mark.
     * @param symbol The player who plays.
     * @return Possible outcome of the procedure.
     */
    possible_outcome makeMove(Point &p, owner symbol);

    /**
     * Returns true if the point is in the board.
     * @param p Point to check.
     * @return True if the point it's in the board.
     */
    bool isLegal(Point &p) const;

    /**
     * Returns the possible moves of "symbol"
     * @param symbol The player.
     * @return Possible moves of symbol.
     */
    vector<Point*> &getPossibleMoves(owner symbol);

protected:
    Board &board;
    vector<Point*> vec1; // Vector with all the possible points of player 1.
    vector<Point*> vec2; // Vector with all the possible points of player 2.

    bool isAlreadyContains(Point &p, owner symbol);

private:
    /**
     * Get the specific point "point" in vector "vec".
     * @param point Point to extract from vec.
     * @param vec Given vector of Point objects.
     * @return The point in the vector.
     */
    Point* getPointFromVec(const Point &point, vector<Point*> vec) const;
};


#endif //EX02_GAMERULES_H
