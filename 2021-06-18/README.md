# Can You Bowl Three Strikes? (18 June 2021)

https://fivethirtyeight.com/features/can-you-bowl-three-strikes

## Express

Scoring in bowling can be a tricky matter.
There are 10 frames, and in each frame you get two chances to knock down as many of the 10 pins as you can.
Each pin knocked down is worth 1 point, and the pins are reset after each frame.
Your score is then the sum of the scores across all 10 frames.

If only it were that simple.
There are special rules for spares (when you've knocked down all 10 pins with the second ball of a frame) and strikes (when you knock down all 10 pins with your first ball).
Whenever you bowl a strike, that frame is scored as 10 *plus* the scores of your next two rolls.
This can lead to some dependency issues at the end of the game, which means the final frame has its own set of rules that I won't go into here.

For example, if you bowled three strikes and missed every subsequent shot (i.e., they were gutter balls), your third frame would be worth 10 points, your second frame would be worth 20 and your first frame 30.
Your final score would be 30 + 20 + 10, or 60 points.

This week, Magritte is going bowling, and the bowling gods have decided that he will bowl *exactly* three strikes in three randomly selected frames.
All the other frames will consist of nothing but gutter balls.
Magritte also lacks patience for bowling's particular rules.
If one of his three strikes comes on the 10th and final frame and he is prompted to bowl further to complete the game, he will bowl gutter balls out of frustration.

What score can Magritte expect to achieve?
(That is, with three randomly placed strikes, what is his average score?)

## Classic

Eight two-way roads all converge at a single intersection, as shown in the diagram below.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-06-18/roads_1.png)

Two cars are heading toward the single intersection from different directions chosen at random.
Upon reaching the intersection, they both turn in a random direction (where proceeding straight is a possible “turn”)—however, neither car pulls a U-turn (i.e., heads back the way it came).

In some cases, the paths of the cars can be drawn so that they do not cross.
In this case, all is well.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-06-18/roads_2.png)

However, in other cases, the paths *must* cross. In this event, the cars will crash.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-06-18/roads_3.png)

What is the probability the cars will crash?
(If both cars head off in the same direction, that also counts as a crash.)

*Extra credit*: As the number of two-way roads converging at the intersection approaches infinity, what value does the probability of crashing approach?


