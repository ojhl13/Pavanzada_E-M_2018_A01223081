#include <stdio.h>
#include "operations.h"

void main ( void ) 
{
	char operation [200];
	int operator1, operator2;

	printf("%s\n", "What is the operation?: " );
	scanf("%s",&operator1,&operator2);
	scanf( "%d %d", &operator1, &operator2);
	printf("result: %d\n", add(operator1,operator2));
}