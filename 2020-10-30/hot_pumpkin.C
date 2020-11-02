#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>

/*
30 October 2020 Riddler
Hot pumpkin is played by a group of M players.
A number N is chosen.
In each round the pumpkin is passed around (circularly), and stops on the Nth person, who is removed from the game.
The next round starts again with the next person in the circle, until only 1 player is left.

In the first round, player 19 is eliminated.
In the second round, the 32nd player after 19 is eliminated.
In the third round, the 1st player after *that* player is eliminated.
i.e.,
N = 61i + 19
N = 60j + 32
N = 59k + 1
for integers i,j,k

Question 1: What is the minimum value of N which meets these requirements?
Question 2: With this N, which player wins?
Question 3: What is the minimum value of N for which player 1 wins?

*/

long DoQuestion1()
{
// identify minimum N satisfying above equations
	printf("\nQuestion 1: Find the minumum value of N such that\n");
	printf("N = 19 mod 61  and  32 mod 60  and  1 mod 59\n\n");
	
	long N = 0;	// the number of times to pass the pumpkin
	int test_range = 25000;	// how far to check for solutions
	bool found_N = false;	// toggle output message
	long min_N = 0;	// store the minimum

	for( int i = 0; i <= test_range; i++)
	{
		N = 61*i + 19;

		if( N%60 == 32 && N%59 == 1 )
		{
			printf("N = %li is a solution\n",N);
			found_N = true;
			if( min_N == 0 || N < min_N )
				min_N = N;
		}
	}

	if( found_N )
		printf("\nMinimum value is %li (of course)\n",min_N);
	else
		printf("No solution found in the given range\n");

	return min_N;
}


void DoQuestion2( const int M_players, long N )
{
	// Solve the game for N passes
	printf("\nQuestion 2: Which player (out of %i) wins?\n\n", M_players );

	int position = -1;	// keeps track of where the pumpkin is; -1 allows to move to 0 in first turn
	int winner = -1;	// place to store winning position
	int players[M_players];	// keeps track of who is still playing
	int counter = 0;	// keeps track of players who haven't lost
	int remainder = 0;	// how far to pass each turn
	
	// initialize
	for( int i = 0; i < M_players; i++ )
		players[i] = 1;

	for( int round = 1; round < M_players; round++ )
	{
		counter = 0;
		remainder = N % ( M_players - round + 1 );	// only bother passing based on the remainder
		if( remainder == 0 )
			remainder = M_players - round + 1;

		while( remainder - counter )
		{
			position++;
			if( position == M_players )
				position = 0;

			counter += players[position];
		}

		players[position] = 0;
	}

	int test_sum = 0;

	// check if there actually is a single winner left
	for( int i = 0; i < M_players; i++)
		test_sum += players[i];

	if( test_sum == 1 )
	{
		for( int i = 0; i < M_players; i++ )
			if( players[i] )
				winner = i;

		winner++;	// account for 0-indexing
	
		printf("For %i players and %li passes, the winner is %i\n", M_players, N, winner );
	}
	else
		printf("Winner not found correctly\t%i\n", test_sum );

	return;
}


void DoQuestion3( const int M_players )
{
	// Find which N makes 1 the winner
	printf("\nQuestion 3: What is the minimum N for which player 1 (out of %i) wins?\n", M_players );

	long N = 1;	// trivially, N>2, actually
	int position = -1;	// keeps track of where the pumpkin is; -1 allows to move to 0 in first turn
	int winner = -1;	// place to store winning position
	int players[M_players];	// keeps track of who is still playing
	int counter = 0;	// keeps track of players who haven't lost
	int remainder = 0;	// how far to pass each turn
	int test_sum = 0;

	printf("\nN\t\twinner\n");

	while( winner )
	{
		// reset stuff
		for( int i = 0; i < M_players; i++ )
			players[i] = 1;
		test_sum = 0;

		if( N < 0 )	// check if it overflows before finding solution
		{
			printf("\nLargest N exceeded\n");
			return;
		}

		for( int round = 1; round < M_players; round++ )
		{
			counter = 0;
			remainder = N % ( M_players - round + 1 );	// only bother passing based on the remainder
			if( remainder == 0 )
				remainder = M_players - round + 1;

			while( remainder - counter )
			{
				position++;
				if( position == M_players )
					position = 0;

				counter += players[position];
			}

			players[position] = 0;
		}

		// check if there actually is a single winner left
		for( int i = 0; i < M_players; i++)
			test_sum += players[i];

		if( test_sum == 1 )
		{
			for( int i = 0; i < M_players; i++ )
				if( players[i] )
					winner = i;
		}

		printf("\n%li\t\t%i", N , winner + 1 );

		N++;	// try another value for N
	}

	printf("\n\nPlayer 1 is a winner for N = %li\n", N - 1 );

	return;
}


int main()
{
	const int M_players = 61;
	long N = DoQuestion1();

	DoQuestion2( M_players, N );

	DoQuestion3( M_players );

	return 0;
}
