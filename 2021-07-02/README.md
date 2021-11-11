# Who Will Win ‘Riddler Jeopardy!'? (2 July 2021)

https://fivethirtyeight.com/features/who-will-win-riddler-jeopardy

## Express

There are 200 episodes in a season of *Riddler Jeopardy!*.
The first episode of the season features three brand-new contestants.
Each subsequent episode includes a returning champion (the winner of the previous episode) as well as two new challengers.

Throughout the season, it so happens that the returning champions are particularly strong, with each one winning five consecutive episodes before being dethroned on the sixth.

If you pick a contestant at random from the season, what is the probability that they are a *Riddler Jeopardy!* champion (meaning they won at least one episode)?

## Classic

On June 24, the following challenge was posted on Twitter:

>Join the dots with straight lines that don't cross.
>Your score is the sum of the products of the numbers joined.
>What's the highest score possible?
>#iteachmath #mtbos [pic.twitter.com/urqWYbgJzT](https://t.co/urqWYbgJzT)
>
>— Everything is Structural (@ChrisKlerkx) [June 24, 2021](https://twitter.com/ChrisKlerkx/status/1408140074089435140)

In this challenge, the numbers from 1 to 11 are arranged in a circle in a particular order: 1, 4, 8, 7, 11, 2, 5, 9, 3, 6, 10.
You then have to connect pairs of numbers with straight line segments that don't intersect, and your score is the sum of the products of the joined numbers.
For example, with the connections {1, 4}, {8, 10}, {3, 7}, {5, 9}, and {2, 11} (and the 6 left by itself), you get a score of 1·4 + 8·10 + 3·7 + 5·9 + 2·11, or 172.

The *best* score you can achieve with this ordering of 1 through 11 around the circle is 237, which you can get with the following connections: {6, 10}, {3, 4}, {7, 8}, {9, 11} and {2, 5} (and the 1 left by itself).

This got Friend-of-The-Riddler Tyler Barron and me thinking about possible extensions of this challenge.
If you want the highest possible maximum score, then you can rearrange the numbers from 1 to 11 so that they are in numerical order around the circle.
(With this arrangement, the maximum score is 250.)

But what if you want the *lowest* possible maximum score?
That is, how can you order the numbers from 1 to 11 around the circle so that the maximum possible score is as low as possible?
And what is the resulting score?

