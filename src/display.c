#include "headers.h"

DisplayHandler initDisplay() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    DisplayHandler display = {.window = window, .renderer = renderer};

    return display;
}

void drawGrid(GameHandler game, DisplayHandler display) {
    int **grid = game.board;

    SDL_Window *window = display.window;
    SDL_Renderer *renderer = display.renderer;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the cells
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    int cellWidth = WINDOW_WIDTH / game.boardSize;
    int cellHeight = WINDOW_HEIGHT / game.boardSize;

    for (int i = 0; i < game.boardSize; i++) {
        for (int j = 0; j < game.boardSize; j++) {
            if (grid[i][j] == 1) {
                SDL_Rect cellRect = {j * cellWidth, i * cellHeight, cellWidth, cellHeight};
                SDL_RenderFillRect(renderer, &cellRect);
            }
        }
    }

    // Update the screen
    SDL_RenderPresent(renderer);
}
