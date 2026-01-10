#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>
#include<vector>

/*
5 November 2021 Riddler

101 people on a social network.
Each has 50% probability of being friends with any other person.
A random person is chosen.
On average, how many friends do this person's friends have?
*/

int main()
{
	srand(time(NULL));	// seed random generator

	double N_trials = 1e5;
	const int N_members = 103;	// number of people on social network
	int friendships[N_members][N_members]; // keep track of all friendships
	double M_total, M_avg, Meta_total, Meta_avg;

	// just in case
	M_avg = 0;
	Meta_avg = 0;

	for( double i=0; i<N_trials; i++ )
	{
		// reset stuff
		M_total = 0;
		Meta_total = 0;

		// randomly (re-)assign friendships
		for( int a=1; a<N_members; a++ )
		{
			for( int b=0; b<a; b++ )
			{
				if( rand()%2 )
				{
					friendships[a][b] = 1;
					friendships[b][a] = 1;
				}
				else
				{
					friendships[a][b] = 0;
					friendships[b][a] = 0;
				}
			}
		}

		for( int a=0; a<N_members; a++ )
		{
			// WLOG, let Marcia be social network member #0
			if( friendships[a][0]==1 )
			{
				M_total++;
				for( int b=0; b<N_members; b++ )
				{
					if( friendships[a][b]==1 )
						Meta_total++;
				}
			}
		}
		// calculate the results for each individual trial
		// Marcia will have M_total friends, and they average
		// Meta_total/M_total friends
		M_avg += M_total;
		if( M_total != 0 )
			Meta_avg += Meta_total/M_total;
	}
		// calculate the final results (normalize to the number of trials)
		M_avg = M_avg/N_trials;
		Meta_avg = Meta_avg/N_trials;

	printf("\nAfter %.0e trials, Marcia had %.3f friends, who themselves averaged %.3f friends.\n", N_trials, M_avg, Meta_avg );

	return 0;
}
