#include <stdio.h>
#include <math.h>

//This function normalizes an array of numbers
double normalize(double* arr, int length)
{
	double N = 0;
	for (int i = 0; i < length; i++)
	{
		N = N + arr[i] * arr[i];
	}

	return sqrt(N);
}

//This function clears the buffer
void clearB()
{
	while ((getchar()) != '\n');
}