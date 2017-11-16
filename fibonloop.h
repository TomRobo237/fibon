#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fibonnachi_calc(int num, int list_flag, int numbered_flag, int comma_flag)
{
	setlocale(LC_ALL, ""); //for commas
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
//Formatting output based on flags passes over from main
		if ((list_flag == 0) && (numbered_flag == 0) && (comma_flag == 0)) //000
		printf("%d: %'llu\n",c+1, cur);
		else if ((list_flag == 0) && (numbered_flag == 0) && (comma_flag == 1)) //001
		printf("%d: %llu\n",c+1, cur);
		else if ((list_flag == 0) && (numbered_flag == 1) && (comma_flag == 0)) //010
		printf("%'llu\n", cur);
		else if ((list_flag == 1) && (numbered_flag == 0) && (comma_flag == 0)) //100
		printf("%d: %'llu ",c+1, cur);
		else if ((list_flag == 0) && (numbered_flag == 1) && (comma_flag == 1)) //011
		printf("%llu\n", cur);
		else if ((list_flag == 1) && (numbered_flag == 0) && (comma_flag == 1)) //101
		printf("%d: %llu ",c+1, cur);
		else if ((list_flag == 1) && (numbered_flag == 1) && (comma_flag == 0)) //110
		printf("%'llu ",cur);
		else if ((list_flag == 1) && (numbered_flag == 1) && (comma_flag == 1)) //111
		printf("%llu ", cur);
	}
	return 0;
}
