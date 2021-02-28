# How Many Ways Can You Build A Staircase? (26 February 2021)

https://fivethirtyeight.com/features/how-many-ways-can-you-build-a-staircase

## Express

This is the fourth and final week of CrossProduct™ puzzles—for now.
This time, there are *four* four-digit numbers—each belongs in a row of the table below, with one digit per cell.
The products of the four digits of each number are shown in the rightmost column.
Meanwhile, the products of the digits in the thousands, hundreds, tens and ones places, respectively, are shown in the bottom row.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-02-26/number-grid.png)

Can you find all four four-digit numbers and complete the table?

## Classic

You have 10 blocks with which to build four steps against a wall.
The first step is one block high, the second is two blocks high, the third is three blocks high and the fourth is four blocks high.

However, the ground ever-so-slightly slopes down toward the wall, and both the floor and the blocks are a little bit slippery.
As a result, whenever you place a block at ground level, it slides toward the wall until it hits the wall or another block.
And when you place a block atop another block, it will similarly slide toward the wall until it hits the wall or another block.

Suppose the four blocks in the bottom row are labeled A, the three blocks in the second row are labeled B, the two blocks in the next row are labeled C and the topmost block is labeled D.
One way to build the steps would be to place the blocks in the following order, one row at a time: A-A-A-A-B-B-B-C-C-D.
You could alternatively place the blocks one column at a time: A-B-C-D-A-B-C-A-B-A.
But you could *not* place them in the order A-B-B-A-A-A-B-C-C-D because that would mean at one point you have more blocks in the second row, B, than in the bottom row, A—a physical impossibility!

How many distinct ways are there to build these four steps using the 10 blocks?

*Extra credit*: Suppose you have precisely enough blocks to build a staircase with *N* stairs. How many distinct ways are there to build this staircase?

