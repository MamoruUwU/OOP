#include <iostream>
#include <vector>
#include "TicTacToe.h"

void task3_1() {
    TicTacToe game;
    game.startGame();
    std::cin.ignore();
    std::cin.get();
    system("cls");
}