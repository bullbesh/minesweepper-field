// minesweepper-field

#include <iostream>
#include <ctime>
using namespace std;


const int ROWS = 16;
const int COLUMNS = 16;
const int MINES = 40;

void printBoard(char board[ROWS][COLUMNS]) {
    // вывод массива на экран
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int minesCount(char board[ROWS][COLUMNS], int row, int col) {
    // заполнение клеток цифрами в зависимости от количества мин рядом
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if ((i >= 0) && (i < ROWS) && (j >= 0) && (j < COLUMNS) && (board[i][j] == '*')) {
                count++;
            }
        }
    }
    return count;
}

void fillBoard(char board[ROWS][COLUMNS]) {
    // заполнение всех клеток пустыми символами
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = '0';
        }
    }

    // генерация случайных координат для мин
    srand(time(NULL));
    int count = 0;
    while (count < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLUMNS;
        if (board[row][col] == '0') {
            board[row][col] = '*';
            count++;
        }
    }

    // заполнение оставшихся клеток цифрами
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != '*') {
                int count_m = minesCount(board, i, j);
                board[i][j] = count_m + '0';
            }
        }
    }
}

int main() {
    char board[ROWS][COLUMNS];
    fillBoard(board);
    printBoard(board);
    return 0;
}
