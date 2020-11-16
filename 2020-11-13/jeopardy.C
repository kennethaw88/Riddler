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

While playing the Jeopardy round of Jeopardy! (not Double Jeopardy), you get every single question, and choose clues left to right, then top to bottom.
If the Daily Double is randomly (and equally) distributed among the 30 clues, what are your expected winnings?

What are your expected winnings if you choose clues randomly (equally distributed)?

With left-to-right, top-to-bottom clue selection, the average payoff is $23800.00 (exactly).

With random clue selection, the average payoff is $26150 (roughly).
*/

int main()
{
	srand(time(NULL));	// seed random generator

	const int N_clues = 30;	// size of Jeopardy board
	long int money = 0;	// keeps track of money won per round
	double avg_money;	// keeps track of average money over all rounds
	int daily_double = -1;	// position of daily double

	for( int i=0; i<N_clues; i++ )
	{
		// reset money and increment position of DD
		money = 0;
		daily_double = i;
		
		for( int j=0; j<N_clues; j++ )
		{
			if( j == daily_double )	// or, if j==i
			{
				// add maximum of earned money or 1000
				if( money < 1000 )
					money += 1000;
				else
					money *= 2;
			}
			else
				money += ( j/6 + 1 ) * 200;
		}

		avg_money += money;	// add up current winnings
	}

	avg_money /= N_clues;	// total average

	printf("\nWith left-to-right, top-to-bottom clue selection, the average payoff is $%.2f.\n", avg_money);

/*
	double trials = 1e6;	// number of rounds to check
	bool clues[N_clues];	// keeps track of which clues have been found
	int found_clues = 0;	// keeps track of how many clues have been found
	int current_clue;	// position of current clue section

	avg_money = 0;	// reset for new problem

	for( double i=0; i<trials; i++ )
	{
		// reset clue board
		for(int j=0; j<N_clues; j++)
			clues[j] = true;

		// reset money and move around DD (randomly)
		daily_double = rand() % N_clues;
		money = 0;
		found_clues = 0;

		while( found_clues<N_clues )
		{
			current_clue = rand() % N_clues;	// choose a random clue
			if( clues[current_clue] )	// check if the current clue has been found
			{
				// check for DD, and add money accordingly
				if( current_clue == daily_double )
				{
					// add maximum of earned money or 1000
					if( money < 1000 )
						money += 1000;
					else
						money *= 2;
				}
				else
					money += ( current_clue/6 + 1 ) * 200;	// add clue value

				// update clue board
				clues[current_clue] = false;
				found_clues++;
			}
		}

		avg_money += money;	// add up current winnings
	}

	avg_money /= trials;	// total average

	printf("\nWith random clue selection, the average payoff is $%.2f.\n", avg_money);
*/

	double trials = 1e6;	// number of rounds to check
	std::vector<int> v_clues(N_clues);	// store clue values more safely

	// assign all clue values
	for( unsigned int i=0; i<v_clues.size(); i++ )
		v_clues.at(i) = ( i/6 + 1 ) * 200;

	avg_money = 0;	// reset for new problem

	for( double i=0; i<trials; i++ )
	{	
		// reset money, move around clue values, and move around DD (randomly)
		money = 0;
		daily_double = rand() % N_clues;
		std::random_shuffle( v_clues.begin(), v_clues.end() );

		// go through clues in "order" (after randomization)
		for( int j=0; j<N_clues; j++ )
		{
			// check for DD, and add money accordingly
			if( j == daily_double )
			{
				// add maximum of earned money or 1000
				if( money < 1000 )
					money += 1000;
				else
					money *= 2;
			}
			else
				money += v_clues.at(j);	// add clue value
		}

		avg_money += money;	// add up current winnings
	}

	avg_money /= trials;	// total average

	printf("\nWith random clue selection, the average payoff is $%.2f.\n", avg_money);

	return 0;
}
