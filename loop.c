/* Thomas Miller
 * simple Fibonacci caluclator */
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, ""); //setting locale for adding commas
	unsigned long long int past2 = 0, past1 = 1, cur;
	int num, c;
/* past2 and past1 are already known for start of looping for fibonacci 
 * numbers, cur will be the current number caucluated by loop, and will 
 * be placed into the past variables as we move on to the next number in
 *  the sequence. Num is the provided amount of numbers to count to.
 * c is a counter for the loop. */
	printf("Amount of fibonacci numbers to count:\n");
	if (scanf("%d", &num) != 1)
/* Checking input for non numbers scanf will exit with 0 if it does not 
 * get the correct input for the variable type it is supposed to fill*/
	{
		printf("Please enter a positive non-zero number!\n");
		exit(EXIT_FAILURE);
	}
	if (num > 94)
/* 94 is the max numbers of fibonacci numbers we can calculate before 
 * the integer overflows */
	{
		printf(
		"Unsigned long long intergers can hold up to "
		"18,446,744,073,709,551,615!\nThe last fibonacchi number "
		"before that is 12,200,160,415,121,876,738!\nShowing all "
		"numbers we can calculate!\n"
		);
//reassigning 94 to num
		num = 94; 
	}
	for (c = 0 ; c < num ; c++ )
	{
		if (c <=1)
			cur = c;
/* we can disregard and print the numbers lower than 2 because the first
 *  2 digit in the sequence are 0 and 1 */
		else
		{ 
			cur = past1 + past2; //actual calculation
/* assigning cur to past1 and past1 to past2 for next loop around */
			past2 = past1;
			past1 = cur; 
		}
		printf("%'llu\n", cur);
	}
//printing newline before returing to shell
	printf("\n"); 
	return 0;
}
