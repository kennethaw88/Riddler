#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>
#include<vector>

/*
20 November 2020 Riddler

20 people are seated at a circular table.
The cranberry sauce starts at one spot (say 1), and is passed either left or right one person with 50% probability.
Which person (2-20) is most likely to be served last?

Apparently everybody is equally likely.
Sample results (out of 1e8):
Position        Last count
2               5266781
3               5258326
4               5262347
5               5260950
6               5264241
7               5269333
8               5266353
9               5262939
10              5257483
11              5261289
12              5258953
13              5265369
14              5264188
15              5270231
16              5264248
17              5262048
18              5262265
19              5256353
20              5266303
*/

int main()
{
	srand(time(NULL));	// seed random generator

	const int N = 20;	// number of people at table
	double trials = 1e8;	// number of times to calculate last person
	int position;	// keep track of posiiton of cranberry sauce
	int people_left;	// keep track of who's gotten cranberry sauce
	std::vector<long int> last_place_count( N, 0 );	// count who's been last
	std::vector<bool> found( N, false );	// keep track of who still needs cranberry sauce

	for( double i=0; i<trials; i++ )
	{
		// reset stuff
		position = 1;
		people_left = 19;
		found.at(0) = true;	// first person always has cranberry sauce
		for( int j=1; j<N; j++ )
			found.at(j) = false;

		while( people_left )
		{
			// move up or down (left or right) with 50% probability
			if( rand()%2 )
			{
				position++;
				// keep position within 1-20
				if( position>N )
					position = 1;
			}
			else
			{
				position--;
				// keep position within 1-20
				if( position==0 )
					position = N;
			}

			// check if this person has gotten cranberry sauce yet
			if( !found.at( position-1 ) )
			{
				found.at( position-1 ) = true;
				people_left--;
			}
		}

		last_place_count.at( position-1 )++;
	}

	// display results (could also be printed to file)
	printf( "\nAfter %.0e trials, here are the results:\n\n", trials );
	printf( "Position\tLast count\n" );
	for( int i=1; i<N; i++ )
		printf( "%i\t\t%li\n", i+1, last_place_count.at( i ) );

	return 0;
}
