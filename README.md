# The Game of Life
This game is a 0-player game, originally imagined by John Horton Conway, and here implemented.

## Rules

The game runs every second, and follows two simple rules at every generation:

- A dead spot becomes alive if it has exactly 3 alive neighbors
- An alive spot with 2 or 3 alive neighbors remains alive, otherwise it dies

We count as neighbors the 8 adjacent tiles, horizontal vertical and diagonal wise

## Using

Simply compile and run the software using `make run` (Or just `make`), and enter a board size, and a random pattern will form, and evolve over time. 
