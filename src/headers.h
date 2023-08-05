#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>    
#include <unistd.h>

#include "/opt/homebrew/include/SDL2/SDL.h"

#define TICK_TIME 100 //ms
                      
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1500

typedef struct {
    int **board;
    int boardSize;
    int gameTick;
    bool isRunning;
} GameHandler;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} DisplayHandler;

//main.c
extern void GameLoop(GameHandler *game, DisplayHandler display);

//init.c
extern GameHandler init();

//game.c
extern void tick(GameHandler *game);
extern bool isValid(int boardSize, int spot);
extern int countNeighbors(GameHandler game, int i, int j);

//misc.c
extern int msleep(long ms);

//display.c
extern void drawGrid(GameHandler game, DisplayHandler display);
extern DisplayHandler initDisplay();
