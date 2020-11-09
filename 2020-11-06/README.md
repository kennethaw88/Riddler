# Can You Make An Unfair Coin Fair?  (6 November 2020)

https://fivethirtyeight.com/features/can-you-make-an-unfair-coin-fair

## Express

Last weekend's New York City Marathon was canceled.
But runners from Des Linden—one of the top American marathoners—to FiveThirtyEight's own Santul Nerkar—my number one editor—still went out there and braved the course.
Santul finished in a time of 3:41:43 (3 hours, 41 minutes, 43 seconds), which averaged to 8 minutes, 27 seconds per mile.

Suppose, while training, Santul completed two 20-mile runs on a treadmill.
For the first run, he set the treadmill to a constant speed so that he ran every mile in 9 minutes.

The second run was a little different.
He started at a 10 minute-per-mile pace and accelerated continuously until he was running at an 8-minute-per mile pace at the end.
Moreover, Santul's minutes-per-mile pace (i.e., *not* his speed) changed linearly over time.
So a quarter of the way through the duration (in time, not distance) of the run, his pace was 9 minutes, 30 seconds per mile, halfway through it was 9 minutes per mile, etc.

Which training run was faster (i.e., took less time) overall?
And what were Santul's times for the two runs?

## Classic

Mathematician John von Neumann is credited with figuring out how to take a biased coin (whose probability of coming up heads is *p*, not necessarily equal to 0.5) and “simulate” a fair coin.
Simply flip the coin twice.
If it comes up heads both times or tails both times, then flip it twice again.
Eventually, you'll get two different flips—either a heads and then a tails, or a tails and then a heads, with each of these two cases equally likely.
Once you get two different flips, you can call the second of those flips the outcome of your “simulation.”

For any value of *p* between zero and one, this procedure will always return heads half the time and tails half the time.
This is pretty remarkable!
But there's a downside to von Neumann's approach—you don't know how long (i.e., how many flips) the simulation will last.

Suppose I want to simulate a fair coin in at most *three* flips.
For which values of *p* is this possible?

*Extra credit*: Suppose I want to simulate a fair coin in at most *N* flips. For how many values of *p* is this possible?

