// Created by Elad Aharon on 28/10/17.
// ID: 311200786

#include "Board.h"
#include "ReversiDefaultRules.h"
#include "HumanPlayer.h"
#include "ConsolePrinter.h"
#include "GameManager.h"
#include "AIPlayer.h"

int main() {

    Board *board = new Board(4, 4);
    GameState gameState1(board);
    ReversiDefaultRules *gameRules = new ReversiDefaultRules();
    HumanPlayer p1('x');
    AIPlayer p2('o', *gameRules);
    ConsolePrinter printer(*board, p1,p2);

    GameManager game(gameState1, p1, p2, printer, *gameRules);
    game.run(); // Run the game.

    delete(gameRules);
    return 1; // Return 1 as a successful operation.
}