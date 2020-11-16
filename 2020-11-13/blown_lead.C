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

A coin is flipped 101 times, and whichever team (H/T) wins at least 51 flips wins the match.
What is the probability that H (or equivalently, T) has a 99% chance of winning at some point in the match, but ultimately loses?

So far, out of 10000 matches, I've gotten 32 blown leads (4/1000, 6/3000, and 22/6000)
*/

// My own function to calculated a binomial coefficient ( k Choose h ),with a normalization factor
// It's defined recursively, and the recursion depth (i.e., the value of the absolute coefficient) is too large in most cases
float norm_binomial( unsigned int k, unsigned int h)
{
	// outside the range of pascal's triangle, but this shouldn't be called anyway
	if( h>k )
		return 0;

	// the edge of pascal's triangle is just ones, but normalized
	if( h==0 || k==h )
		return 1/pow(2,k);

	// recursion step
	return ( norm_binomial( k-1, h-1 ) + norm_binomial( k-1, h ) )/2;
}

// My own function to return the sum of all binomial coefficients ( k Choose h ) at or beyond h
// Because the numbers are too large, it approximates large k with the erf function, including a continuous correction
// k=30 is an arbitrary cutoff; it's where the calculation is noticeably slow
// I don't know absolutely how accurate the approximation is
float binomial_sum( unsigned int k, unsigned int h )
{
	// can't reach h heads, but this shouldn't be called anyway
	if( h>k )
		return 0;

	// if you've already won, but this shouldn't be called anyway
	if( h==0 )
		return 1;

	if( k>29 )
	{
		// the erf function in terms of my own discrete values
		return erfc( ( static_cast<float>(h) - 0.5 - k/2. )/( sqrt( k/2. ) ) )/2;
	}

	float x = 0;	// the partial sum of coefficients (exact)

	for( unsigned int i=h; i<=k; i++ )
	{
		// the remaining sum is 1/2 under specific situations
		if( k%2 && i == ( ( k+1 )/2 ) )
		{
			x += 0.5;
			break;
		}

		x += norm_binomial( k, i );
	}

	return x;
}


int main()
{
	srand(time(NULL));	// seed random generator
	
	const unsigned int N_flips = 101;	// number of coin flips per match
	unsigned int flips;	// count the remaining flips left in the match
	unsigned int heads;	// count the remaining heads needed to win
	bool big_lead;	// check if H has a 99% chance of winning

	long int trials = 1e4;	// number of matches (long because I *want* to do >1e6)
	double blown_leads = 0;	// keep track of the number of blown big leads

	for( long int i=0; i<trials; i++ )
	{
		// reset stuff
		big_lead = false;
		flips = N_flips;
		heads = flips/2 + 1;

		// only bother flipping when there are flips left, H hasn't won yet, and T hasn't won yet
		while( flips && heads && heads<=flips )
		{
			// only bother checking if there hasn't been a big lead already, and if a big lead is mathematically possible
			if( !big_lead && heads<31 && heads<=(flips*3/8) )
				// check numerical probability of winning, unsure of accuracy
				if( binomial_sum( flips, heads )>0.99 )
					big_lead = true;

			// 50-50 for the flip
			if( rand()%2 )
				heads--;

			// one flip used up
			flips--;
		}

		// check if both H lost and there was a big lead at some point
		if( heads && big_lead )
			blown_leads++;

		if( i%100 == 0 )
			printf("\ntrial = %li, blown leads = %.0f", i, blown_leads );
	}

	printf("\nAfter %li matches, there were %.0f blown leads, or %.6f%%.\n", trials, blown_leads, blown_leads/trials*100 );

	return 0;
}
