#include <stdio.h>
unsigned int fibon(unsigned int a);
//using an unsigned int allows for more total number
int main()
{
	int n, c;
	printf("Enter amount of numbers to calculate:\n");
	scanf("%d", &n);
	
	for ( c = 0 ; c < n ; c++)
	printf("%u ", fibon(c));
	return 0;	
}

unsigned int fibon(unsigned int a)
{
	if (a < 2) return a;
	return(fibon(a - 1) + fibon(a - 2));
}

