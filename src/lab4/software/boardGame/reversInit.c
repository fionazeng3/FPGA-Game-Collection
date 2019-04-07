#include "linker.h"
void reverInit() {
    ticInit(ticBoard);
    ticBoard[3][3] = 'X';
    ticBoard[4][4] = 'X';
    ticBoard[3][4] = 'O';
    ticBoard[4][3] = 'O';
    return;
}

void calculateValidMoves() {
    totalValidMoves = 0;
    for (int row = 0; row < 8; row++) {
        for(int column = 0; column < 8; column++) {
            if(ticBoard[row][column] <= 64) {
                int nw = validMove(-1, -1, row, column);
                int nn = validMove(-1, 0, row, column);
                int ne = validMove(-1, 1, row, column);

                int ww = validMove(0, -1, row, column);
                int ee = validMove(0, 1, row, column);

                int sw = validMove(1, -1, row, column);
                int ss = validMove(1, 0, row, column);
                int se = validMove(1, 1, row, column);
                if(nw || nn || ne || ww || ee || sw || ss || se) {
                	itoa(ticBoard[row][column], buffer, 10);
                	if(currentPlayer == me) alt_printf("legal move position detected: %s\n", buffer);
                    totalValidMoves++;
                }
            }
        }
    }
    return;
}

// check the current position contains the mark of current player's opponent
// on the board in the intended direction
int validMove(int dr, int dc, int row, int column) {
    if((row + dr < 0) || (row + dr >7)) return 0;
    if((column + dc < 0) || (column + dc > 7)) return 0;
    if(ticBoard[row + dr][column + dc] != other) return 0;
    if((row + dr + dr < 0) || (row + dr + dr >7)) return 0;
    if((column + dc + dc < 0) || (column + dc + dc > 7)) return 0;
    return checkLineMatch(dr, dc, row + dr + dr, column + dc + dc);
}

// check if there is current player's mark at this position or
// anywhere further
int checkLineMatch(int dr, int dc, int row, int column) {
    if(ticBoard[row][column] == who) return 1;
    if(ticBoard[row][column] < 64) return 0;
    if((row + dr < 0) || (row + dr > 7)) return 0;
    if((column + dc < 0) || (column + dc > 7)) return 0;
    return checkLineMatch(dr, dc, row + dr, column + dc);
}

int flipLine(int dr, int dc, int row, int column) {
    if((row + dr < 0) || (row + dr >7)) return 0;
    if((column + dc < 0) || (column + dc > 7)) return 0;
    if(ticBoard[row + dr][column + dc] <= 64) return 0;
    if(ticBoard[row + dr][column + dc] == who) return 1;
    else {
        if (flipLine(dr, dc, row+dr, column+dc)) {
            ticBoard[row+dr][column + dc] = who;
            return 1;
        } else {
            return 0;
        }
    }
}

void flipBoard(int row, int column) {
    flipLine(-1, -1, row, column);
    flipLine(-1, 0, row, column);
    flipLine(-1, 1, row, column);
    flipLine(0, -1, row, column);
    flipLine(0, 1, row, column);
    flipLine(1, -1, row, column);
    flipLine(1, 0, row, column);
    flipLine(1, 1, row, column);
}

int checkReversiOver() {
    int player1 = 0;
    int player2 = 0;
    for(int row = 0; row < gameCapacity; row++) {
        for(int column = 0; column < gameCapacity; column++){
            if(ticBoard[row][column] == 'X') {
                player1++;
            }
            if(ticBoard[row][column] == 'O') {
                player2++;
            }
        }
    }
    if(totalValidMoves == 0) {
        reversiOver = 1;
        if(player1 > player2) {
            printf("player 1 wins");
        } else {
            printf("player 2 wins");
        }
        return 1;
    } else {
    	char helper1[20];
    	char helper2[20];
    	itoa(player1, helper1, 10);
    	itoa(player2, helper2, 10);
        alt_printf("current score: player1 %s    player2 %s\n", helper1, helper2);
        return 0;
    }
}
