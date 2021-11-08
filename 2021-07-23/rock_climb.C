#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse, random_shuffle, sort
#include<math.h>
#include<vector>

/*
23 July 2021 Riddler

Place rock climbing holds randomly (an uniformly distributed) along a 10-m high climbing wall until there is no gap of at least 1 m.
How many holds on average will be placed?

For this I am instead just using a 1-m wall and considering a gap of 0.1 m.

With 1e6 trials, the average is 41.83
*/

int main()
{
	srand(time(NULL));	// seed random generator

	double trials = 1e6;	// number of trials
	double average_holds = 0;	// keep track of average
	std::vector<double> positions;	// keep track of all hold positions in a trial
	double max_gap;	// keep track of max gap in a trial
	double temp_max_gap;	// placeholder for max gap during calculations

	for( double i=1; i<=trials; i++ )
	{
		// reset stuff
		max_gap = 1;
		positions.clear();

		// always use 0 and 1 to calculate gaps at the top and bottom
		positions.push_back(0);
		positions.push_back(1);

		while( max_gap > 0.1 )
		{
			positions.push_back( static_cast<double> (rand()) / static_cast<double> (RAND_MAX) );	// place a hold randomly
			std::sort( positions.begin(), positions.end() );	// sort numerically
		
			if( positions.size()>11 )	// don't waste time when there's definitely a gap>0.1
			{
				temp_max_gap = 0;	// reset the placeholder for this set of calculations
				
				for( unsigned int j=1; j<positions.size(); j++ )
				{
						if( (positions.at(j)-positions.at(j-1))>temp_max_gap )
							temp_max_gap = positions.at(j)-positions.at(j-1);
				}
				if( temp_max_gap<max_gap )
					max_gap = temp_max_gap;
			}
		}

		if( (static_cast<long unsigned int>(i)%10000)==0 )
		{
			printf("\r%.0f trials",i);
			std::cout.flush();
		}

		average_holds += (positions.size()-2);	// don't count the 0 and 1
	}

	printf("\nAfter %.0e trials, the average number of holds was %.4f.\n", trials, average_holds/trials );

	return 0;
}
