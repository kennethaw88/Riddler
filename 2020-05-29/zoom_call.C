#include<cstdlib>
#include<iostream>
#include<ctime>
#include<fstream>
#include<random>
#include<algorithm>	// reverse and random_shuffle (swap?)
#include<utility>	// swap?

/*
From 538 Riddler of 29 May 2020
Several (330 million) people randomly and uniformly select numbers between 0 and 1 to create some sub-range. What is the probability that at least one sub-range overlaps with all other sub-ranges? Basically, if the numbers are x and y (x<y) what is the probability that x_i<y_min and y_i>x_max for some i?

2 people -> 2/3
10 people -> 2/3
100 people -> 2/3
1000 people -> 2/3

So I'm guessing that the answer is 2/3 no matter what. The answers are all just approximately 2/3, with some variation, not just the same answer, so it doesn't look like a bug.
*/

int main()
{
	srand(time(NULL));	// initialize random seed
	double trials = 1e6;	// number of times to run and get a percentage
	int N = 1000;	// number of people; riddler asks for 3.3e8
	double average = 0;	// total percentage of successes
	double x[N], y[N];	// the random numbers, with x_i < y_i
	double x_max, y_min;	// maximum x (last caller to enter), minimum y (first caller to leave)
	double longest_call = 0;	// current length of longest call (largest y-x gap)
	int longest_index = 0;	// index of current longest call

	if(N<2000)
		trials=1e7;

	for(double j=0; j<trials; j++)	// do the entire procedure for each trial
	{
		success = 0;	// reset for each trial
		longest_call = 0;
		longest_index = 0;
		x_max = 0;
		y_min = 1;
		
		for(int i=0; i<N; i++)	// assign all of the random values
		{
			x[i] = (double)rand()/RAND_MAX;
			y[i] = (double)rand()/RAND_MAX;

			if(x[i]>y[i])	// force x<y using existing numbers
				std::swap(x[i],y[i]);

			if(x_max<x[i])	// check if the current x is now the highest
				x_max = x[i];
			if(y_min>y[i])	// check if the current y is now the lowest
				y_min = y[i];

			if( longest_call < (y[i]-x[i]) )	// check if the current length is now the longest
			{
				longest_call = y[i]-x[i];
				longest_index = i;
			}
		}

		for(int i=0; i<N; i++)	// run through all possible comparisons (yikes)
		{
			if( i==longest_index || x[i]<x[longest_index] || y[i]>y[longest_index] )	// only possible cases to overlap everything
			{
				if( x[i]<y_min && y[i]>x_max )	// this is the exact necessary condition
				{
					average++;
					break;	// don't waste time looking for another (or double-count)
				}
			}
		}
	}

	average = average/trials*100.;	// get the total as a percentage

	printf("\nWith %i people and %.0f trials, there were successful zoom calls %.4f%% of the time.\n",N,trials,average);	// display the results

	return 0;
}
