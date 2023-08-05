#include "headers.h"

int main() {
    GameHandler game = init();
    DisplayHandler display = initDisplay();
    GameLoop(&game, display);
}

void GameLoop(GameHandler *game, DisplayHandler display) {
    game->isRunning = true;
    while(game->isRunning) {
        system("clear");
        drawGrid(*game, display);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game->isRunning = false;
                break;
            }
        }
        // Delay to control the frame rate
        SDL_Delay(10);
        tick(game);
        msleep(TICK_TIME);
    }
}
