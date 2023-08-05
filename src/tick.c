#include "headers.h"

void tick(GameHandler *game) {
    int **newBoard = malloc(sizeof(int*) * game->boardSize);
    for(int i=0; i<game->boardSize; i++) {
        newBoard[i] = malloc(sizeof(int) * game->boardSize);
        for(int j=0; j<game->boardSize; j++) {
            newBoard[i][j] = 0;
        }
    }

    for(int i=0; i < game->boardSize; i++) {
        for(int j=0; j < game->boardSize; j++) {
            int neighbors = countNeighbors(*game, i, j);
            if(game->board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    game->gameTick++;
    int **temp = game->board;
    game->board = newBoard;

    for(int i=0; i<game->boardSize; i++) {
        free(temp[i]);
    }
    free(temp);
}

bool isValid(int boardSize, int spot) {
    return spot >= 0 && spot < boardSize;
}

int countNeighbors(GameHandler game, int i, int j) {
    int count = 0;
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    for(int index = 0; index<8; index++) {
        int x = directions[index][0];
        int y = directions[index][1];
        if(isValid(game.boardSize, i+x) && isValid(game.boardSize, j+y)) {
            count += game.board[i+x][j+y];
        }
    }
    return count;
}
