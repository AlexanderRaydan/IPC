#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PAYS 5

/**********************************************************************************/
/* This shows how to pass parameters by reference.                                */
/**********************************************************************************/

/**
* This function computes the average and largest value in an array.
* The largest value is returned by the function and the average is returned via a parameter.
* @param ar - array of values to work with
* @param size - the number of values in the array
* @param avg - set to the average of the array
* 
* @returns the largest value in the array
*/
double maxAndAverage(const double ar[], const int size, double* avg)
{
	double sum = 0.0, largest = -999999.9;
	int i = 0;

	/******************************************************************************/
	/* TODO: Replace the comments in this function with the actual code to do the */
	/* required calculations.                                                     */
	/******************************************************************************/
	for (i = 0; i < size; i++)
	{
		sum += ar[i];
		if (/* this array value is greater than the largest seen so far */)
		{
			/* remember this to be the new largest value */
		}
	}
	/* set the avg parameter to be the average of the array values */
	return largest;
}

int main(void)
{
	double payRates[MAX_PAYS] = { 15.50, 14.50, 17.00, 15.25 };
	double average = 0.0, maxValue = 0.0;
	int numPayRates = 4;

	/*******************************************************************************/
	/* TODO: Fill in the missing parameters for the function call below.           */
	/*******************************************************************************/
	maxValue = maxAndAverage(/* array */, /* #values in array */, /* variable for avg */);

	printf("The average pay is %.2lf and the highest pay is %.2lf\n", average, maxValue);

	return 0;
}
