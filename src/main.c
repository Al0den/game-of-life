#include "headers.h"

int main() {
    GameHandler game = init();
    GameLoop(&game);
}

void GameLoop(GameHandler *game) {
    game->isRunning = true;
    while(game->isRunning) {
        system("clear");
        printGame(*game);
        tick(game);
        sleep(TICK_TIME);
    }
}
