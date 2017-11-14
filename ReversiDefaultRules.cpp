
// Created by Elad Aharon on 03/11/17.
// ID: 311200786
//

#include <iostream>
#include "ReversiDefaultRules.h"

ReversiDefaultRules::ReversiDefaultRules(Board &board1) : GameRules(board1) {}


vector<Point*> ReversiDefaultRules :: makePossibleMoves(owner symbol) {

    // Free all the previous allocations of the possible points.
    freePointsInVec(symbol);

    int row = this->board.getRow();
    int col = this->board.getCol();

    for(int i = 0;i < row;i++) {
        for(int j = 0;j < col;j++) {
            Point p(i, j);
            owner currentSymbol = this->board.getCell(p).getSymbol();
            if (currentSymbol == symbol) { // Check only the relevant cells.
                checkSurround(p, symbol);
            }
        }
    }

    return symbol == PLAYER_1 ? vec1 : vec2;
}

void ReversiDefaultRules :: checkSurround(Point &p, owner symbol) {
    int r = p.getX();
    int c = p.getY();
    int dRow = -1;
    int dCol;

    for (int i = 0; i < 3; i++) {
        dCol = -1;
        for (int j = 0; j < 3; j++) {

            // Make sure not to check the current cell again.
            if (dRow == 0 && dCol == 0) {
                dCol++;
                continue;
            }

            Point currentPoint(r + dRow, c + dCol);
            if (!board.isInBoard(currentPoint)) {
                continue;
            }

            Cell currentCell = this->board.getCell(currentPoint);
            owner otherSymbol = currentCell.getSymbol();

            // Check if the near cell belongs to the other player.
            if (isLegal(currentPoint) && otherSymbol != symbol && currentCell.isCellActive()) {
                moveAlong(currentPoint, otherSymbol, dRow, dCol);
            }

            dCol++;

        }
        dRow++;
    }
}

void ReversiDefaultRules :: moveAlong(Point p ,owner symbol, short dRow, short dCol) {
    Cell currentCell = this->board.getCell(p);
    owner currentSymbol = (symbol == PLAYER_1 ? PLAYER_2 : PLAYER_1);

    while(isLegal(p) && currentCell.getSymbol() == symbol) {

        // Advance the current point.
        p.setX(p.getX() + dRow);
        p.setY(p.getY() + dCol);
        if (board.isInBoard(p)) {
            // Advance the current cell.
            currentCell = this->board.getCell(p);
        } else {
            break;
        }
    }

    // Check if the cell isn't active.
    if (!currentCell.isCellActive()) {

        // Check if the potential point isn't already in the vector.
        bool check = this->isAlreadyContains(p, currentSymbol);
        if (!check) {
            Point *wantedPoint = new Point(p);
            Point *flowPoint = new Point(dRow * -1, dCol * -1);
            wantedPoint->insertFlowPoint(flowPoint);

            if (symbol == PLAYER_1) {
                this->vec2.push_back(wantedPoint);
            }

            if (symbol == PLAYER_2) {
                this->vec1.push_back(wantedPoint);
            }
        }
    }
}

void ReversiDefaultRules :: freePointsInVec(owner symbol) {
    if (symbol == PLAYER_1) {
        for (unsigned int i = 0; i < vec1.size(); i++) {
            delete(vec1.at(i));
        }
        vec1.clear();
    }

    if (symbol == PLAYER_2) {
        for (unsigned int i = 0; i < vec2.size(); i++) {
            delete(vec2.at(i));
        }
        vec2.clear();
    }

}
