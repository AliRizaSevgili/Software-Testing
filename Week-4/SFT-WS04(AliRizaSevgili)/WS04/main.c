/*
  --------------------------------------------
   Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date				: 10/02/2023
   Subject			: SFT221NCC
   --------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 6

struct FactorialResults
{
	int results[MAX_FACTORIALS];
	int numResults;
};

int factorial(const int n)
{
	int result;
	if (n >= 1)
	{
		result = n * factorial(n - 1);
	}
	else
	{
		result = 1;
	}
	return  result;
}

int reduceFactorial(const int n)
	
{
	int reduction = 1;
	int i; // Outside of the loop, declare the loop variable.


	if (n >= 2)
	{
		for (i = 2; i <= n; i++) //Outside the loop, assign i its initial value.
		{
			reduction *= i;
		}
	}
	else
	{
		reduction = n;
	}

	return reduction;

}

void computeFactorials(struct FactorialResults* results, int numFactorials)
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		results->results[i] = factorial(i);
	}
	results->numResults = numFactorials;
}


int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;
	computeFactorials(&results, NUM_FACTS);	

	for (i = 0; i < NUM_FACTS; i++)
	{
		results.results[i] = reduceFactorial(results.results[i]);
		printf("%d %12d\n", i + 1 , results.results[i]);
	}
	return 0;
}
