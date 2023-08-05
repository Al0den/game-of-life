#include "headers.h"

GameHandler init() {
    int boardSize;
    printf("Indicate a board size, ranging from 1-99\n");
    scanf("%d", &boardSize);
    system("clear");
    printf("Board size: %d\n", boardSize);
    int **board = malloc(sizeof(int*) * boardSize);
    for(int i=0; i<boardSize; i++) {
        board[i] = malloc(sizeof(int) * boardSize);
        for(int j=0; j<boardSize; j++) {
            int random = rand() % 2;
            if(random == 0) {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
    GameHandler game = {
        .board = board,
        .boardSize = boardSize,
        .gameTick = 0,
        .isRunning = false
    };
    return game;
}

