#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class TicTacToe {

private:
    char board[3][3];
public:
    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void drawBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "---+---+---" << endl;
        }
        cout << endl;
    }

    bool isPositionAvailable(int row, int col) {
        return board[row][col] == ' ';
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
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }


    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void playGame() {
        char currentPlayer = 'X';
        int row, col;


        while (true) {
            cout << "'X'  <-->  'O'" << endl;
            drawBoard();

            cout << "Player '" << currentPlayer << "' turns: ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid position. Please choose between 1 and 3 for both row and column." << endl;
                continue;
            }

            if (!isPositionAvailable(row - 1, col - 1)) {
                cout << "Position already taken. Choose another." << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(currentPlayer)) {
                drawBoard();
                cout << "Player '" << currentPlayer << "' wins!" << endl;
                break;
            }
            else if (isBoardFull()) {
                drawBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            system("cls");
        }
    }


};

int main() {
    cout << "\t\t\t\t\t<------ TIC TAC TOE ------>" << endl;
    TicTacToe game;
    game.playGame();

    return 0;
}
