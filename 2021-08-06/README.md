# Can You Zoom Around The Race Track? (6 August 2021)

https://fivethirtyeight.com/features/can-you-zoom-around-the-race-track

## Express

I have four equilateral triangles.
I place one on the floor.
I pick a random edge of this first triangle and attach it to a side of a second triangle.
Next, I randomly pick one of the four edges of the resulting rhombus and attach the third triangle.
Finally, I randomly pick an edge from along the perimeter of the resulting shape and attach the fourth triangle.

What is the probability that I can create a regular tetrahedron by folding the four triangles along their edges?

*Extra credit*: Instead of using four equilateral triangles to make a tetrahedron, suppose I use six squares to make a cube.
What is the probability I can make a cube by randomly attaching the squares, one at a time?
(And what are my chances of making any of the three other Platonic solids using their respective faces?)

## Classic

The game of RaceTrack was published by recreational mathematician Martin Gardner in 1973.
There have been a few modifications and even some neat digital versions since then, and it's high time we had a race here on The Riddler.

So without further ado, welcome to the Riddler-opolis 500!

You begin at the midpoint of the starting line at the bottom (the thicker border), and your goal is to circumnavigate the race track shown below in a single counterclockwise loop.
You'll be moving from point to point on the grid, without ever venturing into the gray surrounding square or the central circle.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-08-06/track1.png)

Each move takes one second.
For your first move, you can choose among nine grid points surrounding and including the starting position.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-08-06/track2.png)

From there, it's essential to remember that you have inertia.
So for your second move, you again have nine possible destinations, but they are determined by your current velocity vector.
That is, you can maintain your current direction and speed, or you can alter your destination by one point in any direction (horizontally, vertically or diagonally).
For example, if your first move was up and to the right, then your possible second moves are shown below, although two of them will cause you to crash into the wall.

![grid](https://github.com/kennethaw88/Riddler/blob/master/2021-08-06/track3.png)

So how quickly can you navigate the following track?
Fractional times are allowed, so if the finish line bisects your final move, then that move counts as 0.5 seconds toward your total time.
And remember, at no time can your path venture into the wall.
(Being tangent to the wall is allowed, as is being on a grid point along a wall.)

