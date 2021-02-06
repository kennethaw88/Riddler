#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>
#include<vector>

/*
5 February 2021 Riddler

Play the Towers of Hanoi game, but choose among available legal moves randomly.
What is the expected number of moves until the game is won (by moving the tower to either other peg)?

Let a,b,c be the peg positions (1, 2, or 3) of the three discs (a is largest).
Each triple (a,b,c) represents a single legal arrangement of the discs.
Except for the initial arrangement (and winning arrangements), all arrangements have three legal moves.

Using 1e6 games, the average is

2 discs: 10.6
3 discs: 70.7
4 discs: 404
5 discs: 2150
6 discs: 11111
7 discs: 
*/

bool IsWinner( std::vector<unsigned short int> &x )
{
	// quick check if the largest disc is at the starting peg
	if( x.at( 0 ) == 1 )
		return false;
	// check if all discs are on the same peg
	else
	{
		bool test = true;
		auto it = x.begin();

		while( test && ( it != x.end() ) )
		{
			test = ( *it == x.at( 0 ) );
			it++;
		}

		return test;
	}
	
	// if something is wrong, don't return a win
	// this shouldn't be called
	return false;
}

bool IsStart( std::vector<unsigned short int> &x )
{
	bool test = true;
	auto it = x.begin();

	while( test && ( it != x.end() ) )
	{
		test = ( *it == 1 );
		it++;
	}

	return test;
}

void ResetTower( std::vector<unsigned short int> &x )
{
	for( auto it = x.begin(); it != x.end(); it++ )
	{
		*it = 1;
	}

	return;
}

int main()
{
	srand(time(NULL));	// seed random generator

	double trials = 1e6;	// number of games
	double moves; // counter for moves in each game
	double average_moves = 0;	// keep track of moves
	//unsigned short int a, b, c;
	std::vector<unsigned short int> tower;
	double dummy;
	unsigned int max_discs = 7;
	signed int disc_to_move = -1;

	// put first two discs in first peg (no point in solving 1-disc game)
	tower.push_back(1);
	tower.push_back(1);

	// run the whole set of games for each number of discs
	while( tower.size() <= max_discs )
	{
		// reset stuff
		average_moves = 0;
	
		// run the whole set of games
		for( double i = 0; i < trials; i++ )
		{
			// reset stuff
			ResetTower( tower );
			moves = 0;
			disc_to_move = -1;
			
			// only run if it isn't a winning arrangement
			while( !IsWinner( tower ) )
			{
				// check for starting arrangement
				if( IsStart( tower ) )
				{
					// there are only two moves from the starting arrangement
					if( rand()%2 )
						tower.back() = 2;
					else
						tower.back() = 3;

					moves++;
				}

				// calculate random real number
				dummy = static_cast<double> (rand()) /  static_cast<double> (RAND_MAX);

				// 2 of 3 legal moves are just moving smallest disc.
				// 1 moves it "left", 1 moves it "right"
				if( dummy < 1./3. )
				{
					// move it in one direction
					tower.back()++;
					// keep it in the range 1-3
					if( tower.back() == 4 )
						tower.back() = 1;
				}
				else if( dummy < 2./3. )
				{
					// move it in the other direction
					tower.back()--;
					// keep it in the range 1-3
					if( tower.back() == 0 )
						tower.back() = 3;
				}
				// 1 of 3 legal moves is left for the other discs, but the move is forced
				else
				{
					disc_to_move = -1;
					// find the next-smallest disc not underneath the smallest disc
					for( signed int i = tower.size()-1; i >= 0; i-- )
					{
						if( tower.at( i ) != tower.back() )
						{
							disc_to_move = i;
							break;
						}
					}

					// make sure a valid disc was found
					if( disc_to_move >= 0 )
					{
						// move the found disc
						do
						{
							tower.at( disc_to_move )++;
							if( tower.at( disc_to_move ) == 4 )
								tower.at( disc_to_move ) = 1;
						}
						while( tower.at( disc_to_move ) == tower.back() );
					}
				}

				moves++;
			}

			average_moves += moves;
		}

		printf("\nFor %lu discs tested with %.0e games, the average number of moves was %.5f.\n", tower.size(), trials, average_moves/trials );

		tower.push_back(1);
	}

	return 0;
}
