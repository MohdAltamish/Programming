#include <stdio.h>

//This Program gives the square of the given number:

int main( )	
	{
		int n, p;
		
		printf("Enter a number: ");
		scanf("%d", &n);
		
		p = n*n;
		
		printf("The Power of %d is %d: ", n, p);
		
		return 0;
		
		}