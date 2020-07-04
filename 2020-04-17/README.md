#Can You Solve The Chess Mystery? (17 April 2020)

https://fivethirtyeight.com/features/can-you-beat-the-goat-monty-hall-problem

## Express

Black Bishop: “Sir, forensic testing indicates the Queen's assassin, the White Knight between us, has moved exactly eight times since the beginning of the game, which has been played by the legal rules.”

Black King: “So?”

Black Bishop: “Well, to convict this assassin, we need to construct a legal game history.
But we just can't figure out how he got there!”

Can *you* figure it out?

![chess](https://github.com/kennethaw88/Riddler/blob/master/2020-04-17/chess.png)

## Classic

Riddler Nation was deeply saddened to hear of the loss of John Conway last week.
It is only fitting that this week's Classic is a spin on Conway's Game of Life.

In the most common version of the game, there is an infinite grid of square cells, which are initially either alive or dead. Each square has eight neighbors — the eight squares that surround it. And after every step in time, or “tick,” all the cells are simultaneously updated according to the following rules:

    A living cell with two or three living neighbors remains living.
    A living cell with any other number of living neighbors dies (due to under- or overpopulation).
    A dead cell with exactly three living neighbors comes alive (due to reproduction).

These relatively simple rules lead to some startlingly complex, emergent behaviors. For example, some formations of living cells are known as “oscillators,” which change form from one tick to the next, ultimately returning back to their original formation.

Now suppose we were to replace the infinite grid with a finite grid that has periodic boundary conditions, so that cells in the first row are neighbors with cells in the last row, and cells in the first column are neighbors with cells in the last column. If there are three rows and N columns, what is the smallest value of N that can support an oscillator?

