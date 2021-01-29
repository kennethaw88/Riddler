# Can You Guess The Mystery Word? (29 January 2021)

https://fivethirtyeight.com/features/can-you-guess-the-mystery-word

## Express

I recently found four cubic blocks in a peculiar arrangement.
Three of them were flat on the ground, with their corners touching and enclosing an equilateral triangle.
Meanwhile, the fourth cube was above the other three, filling in the gap between them in a surprisingly snug manner.
Here's a photo I took of this arrangement:

![cubes](https://github.com/kennethaw88/Riddler/blob/master/2021-01-29/four_cubes.jpg)

If you too have blocks at home (I mean, of course you do), see if you can make the same arrangement.

Now, if each of the four cubes has side length 1, then how far above the ground is the bottommost corner of the cube on top?

## Classic

You are a contestant on the game show Lingo, where your objective is to determine a five-letter mystery word.
You are told this word's first letter, after which you have five attempts to guess the word.
You can guess any five-letter word, even one that has a different first letter.

After each of your guesses, you are told which letters of your guess are also in the mystery word and whether any of the letters are in the correct position.
In the example below, T is in the correct position (remember, the first letter is provided to you), while A and C are in the mystery word but not in the correct positions.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-01-29/grid1.png)

For this example, here's how you might have figured out the mystery word (TACOS) using all five guesses:

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-01-29/grid2.png)

The mystery word and guesses can contain multiple instances of a letter.
For example, the mystery word MISOS contains one O, so a guess with more than one O (like MOSSO) will only have the first O marked as correct (but in this case, in the wrong position).

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-01-29/grid3.png)

As a contestant, your plan is to make a mockery of the game show by adopting a bold strategy: No matter what, before you are even told what the first letter of the mystery word is, you have decided what your first four guesses will be.
Then, with your fifth guess, you will use the results of your first four guesses (and your encyclopedic knowledge of five-letter words!) to determine all remaining possibilities for the mystery word.
If multiple mystery words are still possible, you will pick one of these at random.

Which four five-letter words would you choose to maximize your chances of victory?
Assume that the mystery word is selected randomly from this word list, which is also the list your guesses must be chosen from.

*Extra credit*: For the four five-letter words you chose, what are your chances of victory?

