#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int SIZE = 4;
int board[SIZE][SIZE];

void printBoard();
void initializeBoard();
void addRandom();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
bool isGameOver();

int main() {
    initializeBoard();
    addRandom();
    addRandom();
    printBoard();
    while (!isGameOver()) {
        char move;
        cout << "Enter your move: ";
        cin >> move;
        switch (move) {
            case 'w':
                moveUp();
                break;
            case 's':
                moveDown();
                break;
            case 'a':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            default:
                cout << "Invalid move" << endl;
        }
        addRandom();
        system("clear");
        printBoard();
    }
    cout << "Game Over!" << endl;
    return 0;
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                cout << setw(4) << ".";
            } else {
                cout << setw(4) << board[i][j];
            }
        }  
        cout << endl;
    }
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void addRandom() {
    int i, j;
    bool empty = false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty = true;
                break;
            }
        }
    }
    if (!empty) {
        return;
    }
    do {
        i = rand() % SIZE;
        j = rand() % SIZE;
    } while (board[i][j] != 0);
    board[i][j] = (rand() % 2 + 1) * 2;
}

void moveUp() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k - 1][j] == 0) {
                    board[k - 1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
                if (k > 0 && board[k - 1][j] == board[k][j]) {
                    board[k - 1][j] *= 2;
                    board[k][j] = 0;
                }
            }
        }
    }
}

void moveDown() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < SIZE - 1 && board[k + 1][j] == 0) {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[k + 1][j] == board[k][j]) {
                    board[k + 1][j] *= 2;
                    board[k][j] = 0;
                }
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k - 1] == 0) {
                    board[i][k - 1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
                if (k > 0 && board[i][k - 1] == board[i][k]) {
                    board[i][k - 1] *= 2;
                    board[i][k] = 0;
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j;
                while (k < SIZE - 1 && board[i][k + 1] == 0) {
                    board[i][k + 1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[i][k + 1] == board[i][k]) {
                    board[i][k + 1] *= 2;
                    board[i][k] = 0;
                }
            }
        }
    }
}

bool isGameOver() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
            if (i < SIZE - 1 && board[i][j] == board[i + 1][j]) {
                return false;
            }
            if (j < SIZE - 1 && board[i][j] == board[i][j + 1]) {
                return false;
            }
        }
    }
    return true;
}