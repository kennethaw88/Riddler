#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>
#include<vector>

/*
10 December 2021 Riddler

Three students compete in a fencing relay.
The students have a 25%, 50%, and 75% chance of winning any point.
One student starts a match; after either team gets 15 points,
the next student competes.
After either team gets 30 points, the third student competes.
The match ends at 45 points.
What order of students has the highest probability of winning
the match?
And what is that probability?
*/

int main()
{
	std::mt19937 generator(time(NULL));	// seed random generator

	double N_trials = 1e7;
	int score_A, score_B;
	double wins_A, win_ratio_A;

	wins_A = 0;
	win_ratio_A = 0;

	for( double i=0; i<N_trials; i++ )
	{
		// reset score
		score_A = 0;
		score_B = 0;

		// round 1
		while( score_A < 15 && score_B < 15 )
		{
			if( generator()%2 ) // 50% win rate
				score_A++;
			else
				score_B++;
		}

		// round 2
		while( score_A < 30 && score_B < 30 )
		{
			if( generator()%2 || generator()%2 ) // 75% win rate
				score_A++;
			else
				score_B++;
		}

		// round 3
		while( score_A < 45 && score_B < 45 )
		{
			if( generator()%2 && generator()%2 ) // 25% win rate
				score_A++;
			else
				score_B++;
		}

		if( score_A > score_B )
			wins_A++;
	}
	
	// calculate the final result (normalize to the number of trials)
	win_ratio_A = wins_A/N_trials*100.;

	printf("\nAfter %.0e trials, team A won %.2f%% of the time.\n", N_trials, win_ratio_A );

	return 0;
}
