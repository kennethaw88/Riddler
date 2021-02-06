# Can You Randomly Move The Tower? (5 February 2021)

https://fivethirtyeight.com/features/can-you-randomly-move-the-tower

## Express

For your first weekly CrossProduct, there are five three-digit numbers—each belongs in a row of the table below, with one digit per cell.
The products of the three digits of each number are shown in the rightmost column.
Meanwhile, the products of the digits in the hundreds, tens and ones places, respectively, are shown in the bottom row.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-02-05/number-grid.png)

Can you find all five three-digit numbers and complete the table?

## Classic

Cassius the ape (a friend of Caesar's) has gotten his hands on a Lucas' Tower puzzle (also commonly referred to as the “Tower of Hanoi”).
This particular puzzle consists of three poles and three disks, all of which start on the same pole.
The three disks have different diameters—the biggest disk is at the bottom and the smallest disk is at the top.
The goal is to move all three disks from one pole to any other pole, one at a time, but there's a catch.
At no point can a larger disk ever sit atop a smaller disk.

For *N* disks, the minimum number of moves is 2<sup>*N*</sup>−1.
(Spoiler alert! If you haven't proven this before, give it a shot. It's an excellent exercise in mathematical induction.)

But this week, the *minimum* number of moves is not in question.
It turns out that Cassius couldn't care less about solving the puzzle, but he is very good at following directions and understands a larger disk can never sit atop a smaller disk.
With each move, he randomly chooses one among the set of valid moves.

On average, how many moves will it take for Cassius to solve this puzzle with three disks?

*Extra credit*: On average, how many moves will it take for Cassius to solve this puzzle in the general case of *N* disks?

