#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle

/*
Simulate games of War, and see how often there is a perfect game (one person wins every single of 26 rounds).
I will force the game to start with all aces ('13's) one on side and all twos ('1's) on the other side to increase the chance I see anything at all with this program.
This happens with probability (25/51)*(24/50)*(23/49)*(26/48)*(25/47)*(24/46)*(23/45)=0.0084857

After 4e9 tries, there were 3004 perfect games, or 7.51e-7.
The total probability is therefore 6.4e-9.
*/

int main()
{
	double Ntrials = 3e9;	// number of times to try this
	double perfect_games = 0;	// number of perfect games
	double perfect_pct = 0;	// fraction of perfect games
	const int deck_size = 52;	// total number of cards
	char deck[deck_size];	// the deck to be shuffled
	bool tie = false;	// tie round
	bool lose = false;	// second hand loses round

	if(deck_size%2)
	{
		printf("\ndeck_size is not even!\n");
		return 0;
	}

	srand(time(NULL));	// initialize random seed

	// go through the loop for each Ntrial
	for( double i=0; i<Ntrials; i++)
	{

		tie = lose = false;

		// assign 4 of each card value to deck
		for( int j=0; j<deck_size; j++)
		{
			deck[j] = j/4 +1;
		}

		// shuffle the deck
		std::random_shuffle( &deck[4], &deck[deck_size-4] );	// leave 1s and 13s in place
		std::random_shuffle( &deck[0], &deck[deck_size/2] );	// only bother shuffling first hand

		for( int k=0; k<(deck_size/2); k++)
		{
			// check if first hand wins
			if(deck[k]>deck[k+deck_size/2])
			{
				lose = true;
				break;
			}

			// check if first hand ties
			if(deck[k]==deck[k+deck_size/2])
			{
				lose = true;
				break;
			}
		}

		if( !tie && !lose )
			perfect_games++;
	}

	perfect_pct = perfect_games/Ntrials*100;

	printf("\nAfter %.0f trials, there were %.0f perfect games, for a total of %.6f%%.\n",Ntrials,perfect_games,perfect_pct);

	printf("The overall percent is therefore %.2e%%.\n\n",perfect_pct*0.0084857);

	return 0;
}
