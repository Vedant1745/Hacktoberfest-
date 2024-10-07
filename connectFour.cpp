#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

class ConnectFour {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    ConnectFour() : board(ROWS, vector<char>(COLUMNS, ' ')), currentPlayer(PLAYER1) {}

    void printBoard() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                cout << "|" << board[i][j];
            }
            cout << "|\n";
        }
        cout << "---------------\n";
        cout << " 0 1 2 3 4 5 6\n"; // Column numbers
    }

    bool dropDisc(int column) {
        if (column < 0 || column >= COLUMNS) {
            cout << "Invalid column. Try again.\n";
            return false;
        }

        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][column] == ' ') {
                board[i][column] = currentPlayer;
                return true;
            }
        }

        cout << "Column is full. Try again.\n";
        return false;
    }

    bool checkWin() {
        // Check horizontal
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLUMNS - 3; c++) {
                if (board[r][c] == currentPlayer && board[r][c + 1] == currentPlayer &&
                    board[r][c + 2] == currentPlayer && board[r][c + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check vertical
        for (int r = 0; r < ROWS - 3; r++) {
            for (int c = 0; c < COLUMNS; c++) {
                if (board[r][c] == currentPlayer && board[r + 1][c] == currentPlayer &&
                    board[r + 2][c] == currentPlayer && board[r + 3][c] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check diagonal /
        for (int r = 3; r < ROWS; r++) {
            for (int c = 0; c < COLUMNS - 3; c++) {
                if (board[r][c] == currentPlayer && board[r - 1][c + 1] == currentPlayer &&
                    board[r - 2][c + 2] == currentPlayer && board[r - 3][c + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check diagonal \
        for (int r = 0; r < ROWS - 3; r++) {
            for (int c = 0; c < COLUMNS - 3; c++) {
                if (board[r][c] == currentPlayer && board[r + 1][c + 1] == currentPlayer &&
                    board[r + 2][c + 2] == currentPlayer && board[r + 3][c + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    void play() {
        int column;
        while (true) {
            printBoard();
            cout << "Player " << currentPlayer << ", choose a column (0-6): ";
            cin >> column;

            if (dropDisc(column)) {
                if (checkWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    ConnectFour game;
    game.play();
    return 0;
}
