#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>
#include<vector>

/*
13 November 2020 Riddler

An archer is equally likely to hit any position on a circular target.
The archer will shoot arrows at the target until an arrow lands farther from the center than the previous arrow.
How many arrows are expected to be shot?
(The minimum is trivially 2.)
*/

int main()
{
	srand(time(NULL));	// seed random generator

	double trials = 1e7;	// number of games
	double arrows; // counter for each shot taken
	double average_arrows = 0;	// keep track of scores
	double new_radius, old_radius;	// keep track of individual arrow positions

	for( double i=0; i<trials; i++ )
	{
		// reset stuff
		arrows = 0;
		old_radius = 1;

		while( new_radius < old_radius )
		{
			if( arrows )	// move up new radius constraint only after the first shot
				old_radius = new_radius;

			new_radius = sqrt( static_cast<double> (rand()) / static_cast<double> (RAND_MAX) );	// take the shot
		
			arrows++;	// count the shots
		}

		average_arrows += arrows;
	}

	printf("\nAfter %.0e games, the average score was %.5f.\n", trials, average_arrows/trials );

	return 0;
}
