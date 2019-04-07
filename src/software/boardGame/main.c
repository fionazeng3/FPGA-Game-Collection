#include "linker.h"
int main()
{
    alt_printf("which player are you? (1 or 2) ");
    me = stupid() - '0';
    itoa(me, buffer, 10);
    alt_printf("me is %s \n", buffer);
    if(me != 1 && me != 2) {
    	alt_printf("illegal input\n");
    	alt_printf("game terminated, please reset\n");
    	return 1;
    }
    // choosing which game to play
    int gameChoice;
    alt_printf("which game do you want to play? 1:tic-tac-toe 2:Gomoku 3:Reversi\n");
    gameChoice = stupid() - '0';
    if(gameChoice == 1) {
        gameCapacity = 3;
        winNumber = 3;
        biggest = 9;
    } else if (gameChoice == 2){
        gameCapacity = 8;
        winNumber = 5;
        biggest = 64;
    } else if (gameChoice == 3) {
    	alt_printf("Please only use the legal moves\n");
        gameCapacity = 8;
        winNumber = 0;
        biggest = 64;
    } else {
    	alt_printf("illegal input\n");
    	alt_printf("game not available. Please reset\n");
    	return 1;
    }

    // initiate board before the game
    if(gameChoice == 1 || gameChoice == 2) ticInit(ticBoard);
    else reverInit();
    drawTicBoard();
    isWin = 0;
    isOver = 0;
    reversiOver = 0;
    // gameStart each iteration of the while loop is one round
    while(!(isWin || isOver || reversiOver)) {
        if(gameChoice == 3) calculateValidMoves();
        ticUpdate(currentPlayer, gameChoice);
        drawTicBoard();
        // checking win/ loose condition for tic-tac-toe and gomoku
        if(gameChoice != 3) {
            player1Win = ticCheckWin(1, winNumber);
            player2Win = ticCheckWin(2, winNumber);
            isWin = player1Win || player2Win;
            if(!isWin) {
                isOver = ticCheckOver();
            }
        // check win / loose condition for reversi
        } else {
            reversiOver = checkReversiOver();
        }
        changeTicPlayer();
    }

    // print who wins for tic-tac-toe and gomoku
    if(gameChoice != 3)
    {
        if(player1Win)
        {
            alt_printf ("Congratulations! player1 win! ");
        }
        else if (player2Win)
        {
            alt_printf ("Congratulations! player2 win! ");
        }
        else
        {
            alt_printf("nobody wins. Game Over");
        }
    }
    return 0;
}
