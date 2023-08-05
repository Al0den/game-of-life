#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>    
#include <unistd.h>

#define TICK_TIME 1 //s

typedef struct {
    int **board;
    int boardSize;
    int gameTick;
    bool isRunning;
} GameHandler;

//main.c
extern void GameLoop(GameHandler *game);

//init.c
extern GameHandler init();
extern void printGame(GameHandler game);

//game.c
extern void tick(GameHandler *game);
extern bool isValid(int boardSize, int spot);
extern int countNeighbors(GameHandler game, int i, int j);

//misc.c
extern int msleep(long ms);
