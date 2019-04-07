/*
 * ticInit.c
 *
 *  Created on: May 30, 2018
 *      Author: zeweid
 */

#include "linker.h"

// fill the board with indexes
void ticInit()
{
    currentPlayer = 1;
    who = 'X';
    other = 'O';
    int current = 0;
    for(int i = 0; i < gameCapacity; i++)
    {
        for (int j = 0; j < gameCapacity; j++)
        {
            ticBoard[i][j] = current;
            current++;
        }
    }
    return;
}

// draw the layout of the board
void drawTicBoard()
{
    alt_printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    for(int i = 0; i < gameCapacity; i++) {
        alt_printf(" _____");
    }
    alt_printf("\n");
    for(int i = 0; i < gameCapacity; i++) {
        alt_printf("|");
        for(int j = 0; j < gameCapacity; j++) {
            if(ticBoard[i][j] <=9) {
            	itoa(ticBoard[i][j], buffer, 10);
            	alt_printf("  %s  |", buffer);
            } else {
                if(ticBoard[i][j] <= 63) {
                	itoa(ticBoard[i][j], buffer, 10);
                    alt_printf("  %s |", buffer);
                } else {
                    alt_printf("  %c  |", ticBoard[i][j]);
                }
            }
        }
        alt_printf("\n");
        alt_printf("|");
        for(int k = 0; k < gameCapacity; k++) {
            alt_printf("_____|");
        }
        alt_printf("\n");
    }
    return;
}

void changeTicPlayer()
{
	if(currentPlayer == 1)
	{
		currentPlayer = 2;
		who = 'O';
		other = 'X';

	}
	else
	{
		currentPlayer = 1;
		who = 'X';
		other = 'O';
	}
	return;

}

void ticUpdate(int player, int gameChoice)
{

    alt_printf("player %c playing now\n", (currentPlayer + '0'));
    int inputValid = 0;
    int step;
    int x, y;
    while (!inputValid)
    {
    	// get the appropriate move
    	if(player != me) {
    		step = receive();
    	} else {
    		step = send();
    	}
    	// calculate which grid to  put
        x = step / gameCapacity;
        y = step % gameCapacity;
        if(step < biggest && step >= 0 && x < gameCapacity && y < gameCapacity) {
            inputValid = 1;
        }
        if(inputValid)
        {
            int maxNumber = gameCapacity * gameCapacity - 1;
            if(ticBoard[x][y] >= 0 && ticBoard[x][y] <= maxNumber)
            {
                inputValid = 1;
                if(player == 1)
                {
                    ticBoard[x][y] = 'X';
                }
                else
                {
                    ticBoard[x][y] = 'O';
                }
            }
            else
            {
                inputValid = 0;
            }
        }
    }
    if(gameChoice == 3) flipBoard(x, y);
    return;
}

int ticCheckWin(int player, int winNumber)
{
    // check player horizontal
    for(int i = 0; i < gameCapacity ; i++)
    {
        int countH = 0;
        for(int j = 0; j < gameCapacity; j++)
        {
            if(ticBoard[i][j] == who)
            {
                countH++;
            }
        }
        if(countH == winNumber)
        {
            return 1;
        }
    }

    // check player 1 vertical
    for(int j = 0; j < gameCapacity ; j++)
    {
        int countV = 0;
        for(int i = 0; i < gameCapacity; i++)
        {
            if(ticBoard[i][j] == who)
            {
                countV++;
            }
        }
        if(countV == winNumber)
        {
            return 1;
        }
    }
// top left to bottom right
    for(int j = 0; j < gameCapacity; j++) {
        for(int i = 0; i < gameCapacity; i++)
        {
            int match = 0;
            for(int count = 0; count < winNumber; count++) {
                if(ticBoard[i + count][j + count] == who) {
                    match++;
                }
            }
            if(match == winNumber) return 1;
        }
    }
    //top-right to bottom-left
    for(int j = gameCapacity - 1; j >= 0; j--) {
        for(int i = 0; i < gameCapacity; i++)
        {
            int match = 0;
            for(int count = 0; count < winNumber; count++) {
                if(ticBoard[i + count][j - count] == who) {
                    match++;
                }
            }
            if(match == winNumber) return 1;
        }
    }
    return 0;
}

int ticCheckOver() {
    int counter = 0;
    for (int i = 0; i < gameCapacity; i++) {
        for(int j = 0; j < gameCapacity; j++) {
            if(ticBoard[i][j] <= 64) {
                counter++;
            }
        }
    }
    if(counter == 0) {
        return 1;
    }
    return 0;
}

char stupid() {
    char c1 = alt_getchar();
    alt_getchar();
    char c2 = alt_getchar();
    alt_getchar();
    int big = c1 - '0';
    int small = c2 - '0';
    char value = (char)(big * 10 + small);
    return value + '0';

}


int receive() {
	char result = '0';
	while((*(charRec) & 0x1) != 0x1) {}
	result = *(PLAYERIN);
	//itoa(result, buffer, 10);
	//alt_printf("received grid is %s\n", buffer);
	int value = result - '0';
	return value;
}

int send() {
	alt_putstr("Which grid do you want to choose? \n");
    alt_putstr("Now please enter the grid \n");
	char result = stupid();
	//itoa(result, buffer, 10);
	*(PLAYEROUT) = result;
	//alt_printf("sending char %s\n",buffer);
	*(transmit) = 0x1;
	usleep(1000);
	*(load) = 0x1;
	while(!charRec){}
	usleep(2000);
	*(transmit) = 0x0;
	*(load) = 0x0;
	int value = result - '0';
	return value;
}




















