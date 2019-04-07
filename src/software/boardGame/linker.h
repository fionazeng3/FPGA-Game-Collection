#include <stdio.h>
#include <stdlib.h>
#include "sys/alt_stdio.h"
#include "sys/unistd.h"
#include "altera_avalon_pio_regs.h"
#include <string.h>
#define LED (volatile char*) 0x21060
#define PLAYERIN (volatile char*) 0x21050
#define PLAYEROUT (volatile char*) 0x21040
#define load (volatile char*) 0x21030
#define transmit (volatile char*) 0x21020
#define charSent (volatile char*) 0x21010
#define charRec (volatile char*) 0x21000


char buffer[20];
int gameChoice;
int gameCapacity;
int winNumber;
int totalValidMoves;
unsigned char ticBoard[8][8];
int currentPlayer;
unsigned char who;
unsigned char other;
int me;
int isWin;
int isOver;
int reversiOver;
int player1Win;
int player2Win;
int biggest;
void ticInit();
void drawTicBoard();
void changeTicPlayer();
void ticUpdate(int player, int gameChoice);
int ticCheckOver();
int ticCheckWin(int player, int winNumber);
void reverInit();
void calculateValidMoves();
int validMove(int dr, int dc, int row, int column);
int checkLineMatch(int dr, int dc, int row, int column);
void flipBoard(int row, int column);
int checkReversiOver();
void communicationUpdate(int player);
char stupid();
int send();
int receive();
