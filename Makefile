game-of-life:
	gcc src/*.c -o build/game-of-life.out -D_THREAD_SAFE -I/opt/homebrew/include -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2
run:
	gcc src/*.c -o build/game-of-life.out -D_THREAD_SAFE -I/opt/homebrew/include -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 && ./build/game-of-life.out
