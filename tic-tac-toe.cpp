#include <iostream>
#include <vector>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void printBoard() {
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---+---+---" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    char player = 'X';
    int move;
    int count = 0;

    while (count < 9) {
        printBoard();
        std::cout << "Player " << player << ", enter your move (1-9): ";
        std::cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            count++;

            if (checkWin(player)) {
                printBoard();
                std::cout << "Player " << player << " wins!" << std::endl;
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move, try again." << std::endl;
        }
    }

    if (count == 9) {
        printBoard();
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
