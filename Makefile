game-of-life:
	gcc src/*.c -o build/game-of-life.out 
run:
	gcc src/*.c -o build/game-of-life.out && ./build/game-of-life.out
