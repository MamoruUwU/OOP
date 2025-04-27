#pragma once
#include <iostream>
#include <vector>


class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    bool gameOver;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X'), gameOver(false) {}

    void displayBoard() {
        std::cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---------\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ' || gameOver) {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        checkGameOver();
        if (!gameOver) switchPlayer();
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void checkGameOver() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) gameOver = true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) gameOver = true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) gameOver = true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) gameOver = true;

        if (gameOver) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            return;
        }

        bool draw = true;
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') draw = false;
            }
        }
        if (draw) {
            gameOver = true;
            std::cout << "The game is a draw!\n";
        }
    }

    void startGame() {
        int row, col;
        while (!gameOver) {
            displayBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (row and column, 0-2): ";
            std::cin >> row >> col;
            makeMove(row, col);
        }
        displayBoard();
        std::cout << "Game over!\n";
    }
};
