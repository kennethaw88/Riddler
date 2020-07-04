#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>

using namespace std;

/*
Find a number N such that the total sum of 1^3 + 2^3 + 3^3 + ... + N^3 can be divided into three equal parts made of some combination of cubes.
N must be of the form 3k or 3k-1.
I am doing this by first evaluating 1/3 of the total sum (the target sum), then checking the sum of every possible subset of cubes to see if any of them can get to the target sum.

Also try dividing into 2, 3, 4, 5 equal parts, but I need to narrow down which max_N numbers to try.

for 2: sum is even if N=4k or N=4k+3
for 3: if N=3k or 3k+2
for 4: if N=4k or 4k+3
for 5: if N=5k or 5k+4
for 6: if N=12k or N=12k+3 or N=12k+8
*/

// calculates the sum of cubes up to n, which is the square of the trianglular number
int triangle_sq(int n)
{
	return n*n*(n+1)*(n+1)/4;
}

int main()
{
	int divis = 5;	// number of ways to divide the cubes sum
	int divis_check;	// check if the current sum can be divided equally
	const int terms = 12;	// arbitrary limit on how long many to calculate
	int singles[terms], target[terms];	//
	bool found = false;

	for(int i=0; i<terms; i++)	// calculate all the Ns and target sums to check (N != terms)
	{
		if(i==0)
		{
			singles[i] = 1;	//start checking from at least 1
		}
		else
		{
			singles[i] = singles[i-1]+1;
		}

		divis_check = triangle_sq(singles[i]);

		while( divis_check%divis )
		{
			singles[i]++;
			divis_check = triangle_sq(singles[i]);
		}
		
		target[i] = divis_check/divis;
	}
	
	const int max_N = singles[terms-1];
	int cubes[max_N];
	int sum;
	
	for(int i=0; i<max_N; i++)
	{
		cubes[i] = pow(i+1,3);
	}

	printf("max N = %i\n",max_N);

	unsigned long int pow_set_size;
	unsigned long int counter;
	int j;

	for(int i=0; i<terms; i++)
	{
		pow_set_size = pow(2,singles[i]);

		// each loop is a particular subset of cubes, which turns into a sum of said subset
		// counter runs from 00...01 to 11...11
		// skip 0 because it is a useless "sum"
		for(counter=1; counter<pow_set_size; counter++)
		{
			//printf("counter=%lu\n",counter);
			for(j=0; j<max_N; j++)
			{
				//printf("j=%i\n",j);
				if( counter & (1<<j) )
				{
					sum += cubes[j];

					if( sum > target[i])
						break;					
				}
			}
			if( sum == target[i])
			{
				printf("\nN = %i, possible target sum match at %i.\ncounter = %lu\n",singles[i],target[i], counter);
				found = true;
			}

			sum = 0;
		}
	}

	if(!found)
		printf("\nNo possible target sum match found\n");

	return 0;
}

