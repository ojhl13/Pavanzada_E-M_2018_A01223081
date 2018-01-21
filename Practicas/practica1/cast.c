#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int 		a =250; /*2147493649;*/
	int j=0,k=0,l=0;
	int * p;
	long int 	d = a*(long)a;
	float 		f = 4.67f;
	int 		e = 4;
	int 		c = (int) f + e;
	p 	= &a;
	*p 	= 400;
	p++;
	*p = 5555;

	printf("a = %d p = %p j = %d k = %d, l = %d \n",a,p,l,j,k,l );

	/*prinft(" a= %d, d = %ld, f = %f , e = %d, c = %d \n", a,d,f,e,c);*/


	return 0;
}