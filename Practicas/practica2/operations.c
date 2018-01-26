
#include "operations.h"
#include <assert.h>
#define MAX_INT 2147483647


int add (int a, int b)
{
	long c = (long) a + b;
	assert( c < MAX_INT ||  c > MAX_INT  );
	return (int) c ;
}

int subtraction (int a, int b)
{
	long c = (long) a - b;
	assert( c < MAX_INT ||  c > MAX_INT  );
	return (int) c ;
}
