#include <stdio.h>

void swap_no(int a , int b)
{
	int t;
	t=b;
	b=a;
	a=t;

}

int swap(int *a, int *b)
{
	int t;
	t  = *b;
	*b = *a;
	*a =t;

}

int main(int argc, char const *argv[])
{
	int i = 5, j = 10;
	swap_no(i,j);
	printf("i= %d, j = %d \n",i,j ); 
	swap(&i,&j);
	printf("i= %d, j = %d \n",i,j);
	return 0;
}	