#include <stdio.h>
#include "operations.h"

void printTestMessage( int  resulExpected, char *passMsg, char *faliMsg);



void main( void)
{
	/*Test addition*/
	int a=2147483647;
	int b=2147483647;
	int result = add(a,b);
	int expected = a + b;
	printTestMessage((result == expected),
					"Addition test passed",
					"Addition test failed");

	/*Test substraction*/
	int d = 2147483647;
	int f = 2	;
	int resultSubstraction = subtraction(a,b);
	int expectedsubtraction = a + b;
	printTestMessage( resultSubstraction == expectedsubtraction,
			"subtraction test passed",
			"subtraction test failed");
}

void printTestMessage( int  resulExpected, char *passMsg, char *faliMsg)
{
	if(resulExpected)
	{
		printf("%s\n", passMsg );
	}
	else 
	{
		printf("%s\n", faliMsg );
	}
}