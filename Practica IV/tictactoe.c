#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerTurn(int (*m)[3]){

    int row, column, occupied;

    do{

        printf("Ingresa la coordenada del renglon: "); scanf("%d",&row);
        printf("\nIngresa la coordenada de la columna: "); scanf("%d",&column);

        occupied = isBoxOccupied(m, row, column);

        if(occupied == 1)
            printf("Casilla ocupada, intente de nuevo.\n");

    }while(occupied == 1);

    printf("\nTURNO DEL HUMANO\n");
    makeMove(m, row, column, 1);

    return 2;

}

void makeMove(int (*m)[3], int row, int column, int symbol){

    m[row][column] = symbol;
    displayTicTacToe(m);

}

void displayTicTacToe(int (*m)[3]){

    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(m[i][j] == -1)
                printf(" |   | ", m[i][j]);
            else if(m[i][j] == 1)
                printf(" | X | ", m[i][j]);
            else
                printf(" | O | ", m[i][j]);
        }
        printf("\n---------------------\n");
    }

}

int isBoxOccupied(int (*m)[3], int row, int column){

    if( m[row][column] != -1){
        return 1;
    }else
        return 0;

}

int canComputerWin(int (*m)[3]){

    int i, j, winningMove[2], winningChance, boxesNotOccupied;

    //Check for possible winning move in rows
    for(i=0; i<3; i++){
        winningChance=0;
        boxesNotOccupied=0;
        winningMove[0]=-1;
        winningMove[1]=-1;
        for(j=0; j<3; j++){
            if(isBoxOccupied(m, i, j) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=j;
            }else if(m[i][j] == 0)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        }
    }

    //Check for possible winning move in columns
    for(i=0; i<3; i++){
        winningChance=0;
        boxesNotOccupied=0;
        winningMove[0]=-1;
        winningMove[1]=-1;
        for(j=0; j<3; j++){
            if(isBoxOccupied(m, j, i) != 1){
                boxesNotOccupied++;
                winningMove[0]=j;
                winningMove[1]=i;
            }else if(m[j][i] == 0)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        }
    }

    //Check for possible winning move in left to right diagonal
    winningChance=0;
    boxesNotOccupied=0;
    winningMove[0]=-1;
    winningMove[1]=-1;
    for(i=0; i<3; i++){
        if(isBoxOccupied(m, i, i) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=i;
        }else if(m[i][i] == 0)
            winningChance++;
        if(winningChance == 2 && boxesNotOccupied == 1)
            return winningMove;
    }

    //Check for possible winning move in right to left diagonal
    winningChance=0;
    boxesNotOccupied=0;
    winningMove[0]=-1;
    winningMove[1]=-1;
    i=0; j=2;
    while(i<3){
        if(isBoxOccupied(m, i, j) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=j;
            }else if(m[i][j] == 0)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        i++; j--;
    }

    winningMove[0]=-1;
    winningMove[1]=-1;
    return winningMove;
}

int canHumanWin(int (*m)[3]){

    int i, j, winningMove[2], winningChance, boxesNotOccupied;

    //Check for possible winning move in rows
    for(i=0; i<3; i++){
        winningChance=0;
        boxesNotOccupied=0;
        winningMove[0]=-1;
        winningMove[1]=-1;
        for(j=0; j<3; j++){
            if(isBoxOccupied(m, i, j) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=j;
            }else if(m[i][j] == 1)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        }
    }

    //Check for possible winning move in columns
    for(i=0; i<3; i++){
        winningChance=0;
        boxesNotOccupied=0;
        winningMove[0]=-1;
        winningMove[1]=-1;
        for(j=0; j<3; j++){
            if(isBoxOccupied(m, j, i) != 1){
                boxesNotOccupied++;
                winningMove[0]=j;
                winningMove[1]=i;
            }else if(m[j][i] == 1)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        }
    }

    //Check for possible winning move in left to right diagonal
    winningChance=0;
    boxesNotOccupied=0;
    winningMove[0]=-1;
    winningMove[1]=-1;
    for(i=0; i<3; i++){
        if(isBoxOccupied(m, i, i) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=i;
        }else if(m[i][i] == 1)
            winningChance++;
        if(winningChance == 2 && boxesNotOccupied == 1)
            return winningMove;
    }

    //Check for possible winning move in right to left diagonal
    winningChance=0;
    boxesNotOccupied=0;
    winningMove[0]=-1;
    winningMove[1]=-1;
    i=0; j=2;
    while(i<3){
        if(isBoxOccupied(m, i, j) != 1){
                boxesNotOccupied++;
                winningMove[0]=i;
                winningMove[1]=j;
            }else if(m[i][j] == 1)
                winningChance++;
            if(winningChance == 2 && boxesNotOccupied == 1)
                return winningMove;
        i++; j--;
    }

    winningMove[0]=-1;
    winningMove[1]=-1;
    return winningMove;

}

int computerTurn(int (*m)[3], int playerTurns){

    int row, column, *computerWinningMove, *humanWinningMove;

    printf("\nTURNO DE LA COMPUTADORA\n");

    if(playerTurns <= 1){
        do{
            srand(time(NULL));
            row = rand() % 2;
            if(row == 1)
                row++;
            column = rand() % 2;
            if(column == 1)
                column++;
        }while(isBoxOccupied(m, row, column) == 1);
        makeMove(m, row, column, 0);
        return 1;
    }else{

        computerWinningMove = canComputerWin(m);

        if(computerWinningMove[0] != -1){
            makeMove(m, computerWinningMove[0], computerWinningMove[1], 0);
            return -1;
        }

        humanWinningMove = canHumanWin(m);
        if(humanWinningMove[0] != -1){
            makeMove(m, humanWinningMove[0], humanWinningMove[1], 0);
            return 0;
        }

        do{

            srand(time(NULL));
            row = rand() % 2;
            srand(time(NULL));
            column = rand() % 2;

        }while(isBoxOccupied(m, row, column) == 1);
        makeMove(m, row, column, 0);
        return 1;

    }

}

void main(){

    int turn, gameIsOn = 1, computerTurnCounter = 0, playerTurnCounter = 0;
    int m[3][3] =   {
                        {-1,-1,-1},
                        {-1,-1,-1},
                        {-1,-1,-1}
                    };

    do{
        printf("Comienzas tu?\n1. Si\n2. No");
        scanf("%d",&turn);
    }while(turn != 1 && turn != 2);

    while(gameIsOn == 1 || gameIsOn == 2){

        if(turn == 1){
            turn = playerTurn(m);
            playerTurnCounter++;
        }
        if(turn == 2){
            turn = computerTurn(m, playerTurnCounter);
            computerTurnCounter++;
        }

        gameIsOn = turn;

    }

    if(gameIsOn == -1)
        printf("\nJuego terminado.\nGanador: Computadora\nNumero de movimientos: %d", computerTurnCounter);
    else if(gameIsOn == 0)
        printf("\nJuego terminado.\nGanador: Humano\nNumero de movimientos: %d", playerTurnCounter);

}
