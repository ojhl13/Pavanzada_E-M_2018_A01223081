/*#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[]) {
  int x=0;
  int y=400;

  #pragma omp parallel private(y) shared(x)
  {
      y = omp_get_thread_num();
      printf("%s %d\n", "helloWorld" , y );
      x+=y;
  }
  printf ("x = %d, y = %d \n",x,y);
  return 0;
}
*/

#include
<stdio.h>

#include
<omp.h>

#define
SIZE 2000

// gcc -o openmp.exe openmp.c -fopenmp

int
main (){

int a[SIZE], b[SIZE], c[SIZE];

int i;

int tid;

int chunk
=
20;



#pragma
omp
parallel
private(i,tid)
shared(a,b,chunk)

{

tid =
omp_get_thread_num();

printf("I am %d\n",tid);

#pragma
for
schedule(dynamic,chunk)
nowait

for(i=0;i<SIZE;i++){

a[i] = i;

b[i] = i;

}

}



#pragma
omp
parallel
private(i,tid)
shared(a,b,chunk)

{

tid =
omp_get_thread_num();

printf("I am %d\n",tid);

#pragma
for
schedule(dynamic,chunk)
nowait

for(i=0;i<SIZE;i++){

c[i] = a[i]
* b[i];

}

}




return
0;

}
