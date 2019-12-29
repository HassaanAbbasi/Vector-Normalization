#include "normalizeFuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
	printf("Welcome to my Vector Normalization program.\nFor instructions on how to use the program, please refer to 'instructions.txt'\n");

	int errorFlag = 0; //Raised if any BAD INPUT received

	while (1)
	{
		int counter = 0;
		int numComponents = 0;
		double components[9];
		char temp[100];

		int flag = scanf("%s", temp); //Checking to see if the first item entered is EOF

		if (flag != 1)
		{
			exit(errorFlag);
		}

		int exitFlag1 = 0; //Raised when bad input. Allows you to try new input
		for (int i = 0; i < strlen(temp); i++)
		{
			if(temp[i] == '+' && i == 0 && strlen(temp) > 1) //Checking to see if the token has '+' before it
			{
				continue;
			}
			if (isdigit(temp[i]) == 0 || temp[i] == '.') //Catching decimals as number of components
			{
				fprintf(stderr, "BAD INPUT\n");
				clearB();
				exitFlag1 = 1;
				errorFlag = 1;
				break;
			}
		}

		if (exitFlag1 == 1) //Start a new input
		{
			continue;
		}

		numComponents = atoi(temp); //Converting our first number to integer

		if (numComponents > 9 || numComponents < 0) //Catching if vector size is too large or negative
		{
			fprintf( stderr, "BAD INPUT\n");
			clearB();
			errorFlag = 1;
			continue;
		}

		if (numComponents == 0) //Exiting if 0 is entered first
		{
			exit(errorFlag);
		}

		int exitFlag = 0; //Raised when bad input. Allows you to try new input
		while (counter < numComponents)
		{
			int flag = scanf("%lf", components + counter); //Take components from user. Flag raised if input is successful

			if (flag == 0)
			{
				fprintf(stderr, "BAD INPUT\n");
				clearB();
				exitFlag = 1;
				errorFlag = 1;
				break;
			}
			
			else
			{
				int next = getchar();

				if (next != ' ' && next != '\t' && next != '\n')
				{
					fprintf(stderr, "BAD INPUT\n");
					clearB();
					errorFlag = 1;
					exitFlag = 1;
					break;
				}

				else if (next == '\n')
				{
					ungetc('\n', stdin); //Rebuffers so info is displayed properly
				}
			}
			
			counter++;
		}

		if (exitFlag == 1) //Start a new input
		{
			continue;
		}
		
		printf("VECTOR: [ "); //Print out the given vector one by one
		for (int a = 0; a < numComponents; a++)
		{
			if (a == numComponents - 1)
			{
				printf("%.3f ", components[a]);
				break;
			}

			printf("%.3f, ", components[a]);
		}
		printf("] ");
		clearB();

		double norm = normalize(components, numComponents);
		printf("NORMALIZED: [ "); //Print out our normalized vector
		for (int a = 0; a < numComponents; a++)
		{
			if (a == numComponents - 1)
			{
				printf("%.3f ", (components[a])/norm);
				break;
			}

			printf("%.3f, ", (components[a])/norm);
		}
		printf("]\n");
	}

	printf("Thank you for using my Vector Normalization program!");
}