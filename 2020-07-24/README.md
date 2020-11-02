# Are You A Pinball Wizard? (24 July 2020)

https://fivethirtyeight.com/features/are-you-a-pinball-wizard

## Express

Riddler Township is having its quadrennial presidential election.
Each of the town's 10 “shires” is allotted a certain number of electoral votes: two, plus one additional vote for every 10 citizens (rounded to the nearest 10).

The names and populations of the 10 shires are summarized in the table below.

<table>
<tr><td>Shire</td><td>Population</td><td>Electoral Votes</td></tr>
<tr><td>Oneshire</td><td>11</td><td>3</td></tr>
<tr><td>Twoshire</td><td>21</td><td>4</td></tr>
<tr><td>Threeshire</td><td>31</td><td>5</td></tr>
<tr><td>Fourshire</td><td>41</td><td>6</td></tr>
<tr><td>Fiveshire</td><td>51</td><td>7</td></tr>
<tr><td>Sixshire</td><td>61</td><td>8</td></tr>
<tr><td>Sevenshire</td><td>71</td><td>9</td></tr>
<tr><td>Eightshire</td><td>81</td><td>10</td></tr>
<tr><td>Nineshire</td><td>91</td><td>11</td></tr>
<tr><td>Tenshire</td><td>101</td><td>12</td></tr>
</table>

As you may know, under this sort of electoral system, it is quite possible for a presidential candidate to lose the popular vote and still win the election.

If there are two candidates running for president of Riddler Township, and every single citizen votes for one or the other, then what is the *lowest* percentage of the popular vote that a candidate can get while still winning the election?


## Classic

Riddler Pinball is a game with an infinitely long wall and a circle whose radius is 1 inch and whose center is 2 inches from the wall.
The wall and the circle are both fixed and never move.
A single pinball starts 2 inches from the wall and 2 inches from the center of the circle.

To play, you flick the pinball toward a spot of your choosing along the wall, specified by its distance *x* from the point on the wall that's closest to the circle, as shown in the diagram below.

![diagram](https://github.com/kennethaw88/Riddler/blob/master/2020-07-24/pinball_diagram.png)

The goal of the game is simple: Get the ball to bounce as many times as possible.

(Note: This is a geometry problem, not a physics problem.
In other words, assume the system is frictionless and that all collisions are perfectly elastic.)

Let's take a look at some games to see how they play out.

If you aim too far to the right (i.e., your value of *x* is too small), the pinball will quickly bounce its way through the gap between the circle and the wall.
That's what happened in the game below, when *x* was 0.75 inches, resulting in a rather pedestrian four bounces.

![richochet1](https://github.com/kennethaw88/Riddler/blob/master/2020-07-24/ricochet1.gif)

But if you aim too far to the left (i.e., your value of *x* is too big), the pinball will quickly come back out the same side it went in.
That's what happened in the next game, when *x* was 0.9 inches, again yielding just four bounces.

![richochet2](https://github.com/kennethaw88/Riddler/blob/master/2020-07-24/ricochet2.gif)

As you can see, Riddler Pinball is an unforgiving game—the slightest error can tank your chances of victory.
But if you strategize *just* right, it's possible to do quite well.

What's the greatest number of bounces you can achieve?
And, more importantly, what value of *x* gets you the most bounces?


