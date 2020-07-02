#include<cstdlib>
#include<iostream>
#include<ctime>	// time
#include<fstream>
#include<random>	// random
#include<algorithm>	// reverse and random_shuffle
#include<math.h>

using namespace std;

/*
Check the output (the counter variable) of the sums_of_cubes.exe output, one N at a time,
*/

int main()
{
	int N = 24;
	unsigned long int counter[] = {65450,97909,118703,123882,124507,125163,125258,159737,161704,162985,163080,175867,175962,176005,177628,177632,177834,179210,183953,185662,188917,189119,189214,189218,190495,190499,209803,211044,214957,216333,217550,218179,221417,221512,230885,231087,231182,231833,232463,237642,293172,306561,309302,314510,319675,319770,335140,338554,338597,338692,340220,345513,346640,361643,361738,397187,398810,405556,410099,410764,548405,553423,553584,567055,567868,574378,574801,575003,575659,575754,595548,595552,596204,596285,606837,658292,661540,671913,672008,688138,788848,789050,790716,1063728,1068936,1070567,1071515,1074119,1074525,1074529,1074731,1084864,1085066,1090030,1090655,1090659,1097978,1098116,1116900,1116981,1181320,1183899,1311412,1312788,2108845,2110687,2110691,2110786,2115512,2116482,2116793,2116888,2122071,2131440,2131642,2133018,2138240,2163611,2164039,2164852,2228866,2229272,4198361,4200328,4201609,4204907,4211613,4211617,4212993,4227541,4227743,4227747,4227842,4228153,4229123,4260041,4325377,8391542,8394790,8397372,8405163,
	8405258};
	int length = sizeof(counter) / sizeof(counter[0]);
	unsigned long int sum = pow(2,N)-1;
	bool success = 0;

	printf("\nN = %i:",N);

	for(int i=0; i<length; i++)
	{
		for(int j=0; j<i; j++)
		{
			for(int k=0; k<j; k++)
			{
				for(int l=0; l<k; l++)
				{
					if(  !(counter[i] & counter[j])
						&& !(counter[i] & counter[k])
						&& !(counter[i] & counter[l])
						&& !(counter[j] & counter[k])
						&& !(counter[j] & counter[l])
						&& !(counter[k] & counter[l]) )
					{
						printf("\nI found a solution:\ncounter = %lu, %lu, %lu, %lu, %lu\n",counter[i],counter[j],counter[k],counter[l],sum-counter[i]-counter[j]-counter[k]-counter[l]);
						success = 1;
					}
				}
			}
		}
	}

	if(!success)
		printf("\nNo solution found\n");

	return 0;
}

