#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fibonnachi_calc(int num, int list, int numbered, int commas)
{
	setlocale(LC_ALL, ""); 
	unsigned long long int past2 = 0, past1 = 1, cur;
	int c;
	for (c = 0 ; c < num ; c++ )
	{
		if (c <=1)
			cur = c;
		else
		{ 
			cur = past1 + past2;
			past2 = past1;
			past1 = cur; 
		}
		printf("%'llu\n", cur);
	}
	printf("\n"); 
	return 0;
}
