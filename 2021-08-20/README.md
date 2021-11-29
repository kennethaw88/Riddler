# Can You Catch The Cricket? (20 August 2021)

https://fivethirtyeight.com/features/can-you-catch-the-cricket

## Express

Help, there's a cricket on my floor!
I want to trap it with a cup so that I can safely move it outside.
But every time I get close, it hops exactly 1 foot in a random direction.

I take note of its starting position and come closer.
Boom—it hops in a random direction. I get close again.
Boom—it takes another hop in a random direction, independent of the direction of the first hop.

What is the *most probable* distance between the cricket's current position after two random jumps and its starting position?
(Note: This puzzle is not asking for the *expected* distance, but rather the *most probable* distance.
In other words, if you consider the probability distribution over all possible distances, where is the peak of this distribution?)

## Classic

When you roll a pair of fair dice, the most likely outcome is 7 (which occurs 1/6 of the time) and the least likely outcomes are 2 and 12 (which each occur 1/36 of the time).

Annoyed by the variance of these probabilities, I set out to create a pair of “uniform dice.”
These dice still have sides that are uniquely numbered from 1 to 6, and they are identical to each other.
However, they are weighted so that their sum is more uniformly distributed between 2 and 12 than that of fair dice.

Unfortunately, it is impossible to create a pair of such dice so that the probabilities of all 11 sums from 2 to 12 are *identical* (i.e., they are all 1/11).
But I bet we can get pretty close.

The variance of the 11 probabilities is the average value of the squared difference between each probability and the average probability (which is, again, 1/11).
One way to make my dice as uniform as possible is to minimize this variance.

So how should I make my dice as uniform as possible?
In other words, which specific weighting of the dice minimizes the variance among the 11 probabilities?
That is, what should the probabilities be for rolling 1, 2, 3, 4, 5 or 6 with one of the dice?


