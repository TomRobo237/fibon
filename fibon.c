#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <getopt.h>
#include "fibonloop.h"

int fibonnachi_calc(int num, int list_flag, int numbered_flag, int comma_flag);
int main (int argc, char *argv[])
{
	int c, num = 0, option_index = 0;
/* c is a loop counter. num is amount of numbers in fibonnaci 
 * sequence to calculate, set to 0 as a test for input later
 * option index is used for getopts. */
	static int list_flag = 1, numbered_flag = 1, comma_flag = 1;
//getopts loop
	while (1) {
		static struct option long_options[] = 
		{
			{"list", no_argument, &list_flag, 0},
			{"numbered", no_argument, &numbered_flag, 0},
			{"comma", no_argument, &comma_flag, 0},
			{0,0,0,0} //index
		};
//setting flags		
	c = getopt_long( argc, argv, "lnc", long_options, &option_index);
		switch (c)
		{
			case 'l':
				list_flag = 0;
				break;
			case 'n':
				numbered_flag = 0;
				break;
			case 'c':
				comma_flag = 0;
				break;
		}
	if ( c == -1) //getopts returns -1 when it has nothing more to test.
		break;
	}
//loop to check for numbers in command line arguments.
	for ( c= 0 ; c < argc ; c++ )
		{
//Sets first number encountered in args to num.
			if ((num = atoi(argv[c])) != 0)
			break;
	}
//if number not entered or a 0 is set, accept input.
	if (num == 0)
	{
		printf("Amount of fibonacci numbers to count:\n");
		if (scanf("%d", &num) != 1)
/* Checking input for non numbers scanf will exit with 0 if it does not 
 * get the correct input for the variable type it is supposed to fill*/
		{
			printf("Please enter a positive non-zero number!\n");
			exit(EXIT_FAILURE);
		}
	}
//catching overflow
	if (num > 94)
/* 94 is the max numbers of fibonacci numbers we can calculate before 
 * the integer overflows, informing user of this and displaying max.
 * TODO: bignum implentation?*/
	{
		printf(
		"Unsigned long long intergers can hold up to "
		"18,446,744,073,709,551,615!\nThe last fibonacchi number "
		"before that is 12,200,160,415,121,876,738!\nShowing all "
		"numbers we can calculate!\n"
		);
		num = 94; 
	}
//actual caluclation loop, refer to header file.
	fibonnachi_calc(num, list_flag, numbered_flag, comma_flag);
	return 0;	
}

