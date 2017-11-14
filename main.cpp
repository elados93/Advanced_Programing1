// Created by Elad Aharon on 28/10/17.
// ID: 311200786

#include "Board.h"
#include "ReversiDefaultRules.h"
#include "HumanPlayer.h"
#include "ConsolePrinter.h"
#include "GameManager.h"

int main() {

    Board board(8, 8);
    ReversiDefaultRules gameRules(board);
    HumanPlayer p1('x');
    HumanPlayer p2('o');
    ConsolePrinter printer(board, p1,p2);

    GameManager game(board, p1, p2, printer, gameRules);
    game.run(); // Run the game.

    return 1; // Return 1 as a successful operation.
}