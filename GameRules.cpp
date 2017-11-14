
// Created by Elad Aharon on 29/10/17.
// ID: 311200786
//

#include "GameRules.h"

GameRules::GameRules(Board &board1) : board(board1) {}

GameRules::~GameRules() {
    for (unsigned int i = 0; i < vec1.size(); i++) {
        delete(vec1.at(i));
    }
    vec1.clear();

    for (unsigned int j = 0; j < vec2.size(); ++j) {
        delete(vec2.at(j));
    }

    vec2.clear();
}

bool GameRules:: isLegal(Point &p) const{
    return this->board.isInBoard(p);
}

bool GameRules :: isAlreadyContains(Point &p, owner symbol) {

    if (symbol == PLAYER_1) {
        for (unsigned int i = 0; i < this->vec1.size(); i++) {

            // Check if the point already exists.
            if (p.isEqual(*(this->vec1.at(i)))) {
                return true;
            }
        }
    } else {
        if (symbol == PLAYER_2) {
            for (unsigned int i = 0; i < this->vec2.size(); i++) {

                // Check if the point already exists.
                if (p.isEqual(*(this->vec2.at(i)))) {
                    return true;
                }
            }
        }
    }

    return false;
}

possible_outcome GameRules::makeMove(Point &p, owner symbol) {

    // Not in the board.
    if (!board.isInBoard(p)) {
        return OUT_OF_BOUND;
    }

    // The cell is occupied.
    if (!board.isCellEmpty(p)) {
        return OCCUPIED_CELL;
    }

    // Not one of the possible options.
    if (!isAlreadyContains(p, symbol)) {
        return ILLEGAL_MOVE;
    }

    // Check all the possible directions of the point and mark the required cells.
    vector<Point*> possibleMoves = getPossibleMoves(symbol);
    vector<Point*> flowVec = getPointFromVec(p, possibleMoves)->getDirVector();

    for (unsigned int i = 0; i < flowVec.size(); i++) {
        int dRow = flowVec.at(i)->getX();
        int dCol = flowVec.at(i)->getY();

        Point currentPoint(p);
        Cell currentCell;

        // Mark the cell in the right direction until you first meet the player symbol.
        do {
            board.markCell(currentPoint, symbol);
            currentPoint.setX(currentPoint.getX() + dRow);
            currentPoint.setY(currentPoint.getY() + dCol);
            if (board.isInBoard(currentPoint)) {
                currentCell = board.getCell(currentPoint);
            } else {
                break;
            }
        } while (currentCell.getSymbol() != symbol);
    }

    return SUCCESS;
}

Point* GameRules :: getPointFromVec(const Point &point, vector<Point*> vec) const {
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (vec.at(i)->isEqual(point)) {
            return vec.at(i);
        }
    }
    return NULL; // If the point isn't in the vector return null.
}

vector<Point *> &GameRules::getPossibleMoves(owner symbol) {
    return symbol == PLAYER_1 ? vec1 : vec2;
}

vector<Point *> GameRules::makePossibleMoves(owner symbol) {
    return vector<Point *>();
}
