#include <stdio.h>


char  search_movies(int timeflight, int *listMovies  )
{
  int leasttime;
  int i;
  int j;
  int *ptrtemp;
  char result;
  ptrtemp = listMovies;
  result = 0 ;

  for( i =0 ; i < sizeof(listMovies)-1;i++)
  {
    leasttime = *listMovies - timeflight;
    for (j = i; j < sizeof(listMovies); j++) {
        if( leasttime == *ptrtemp)
        {
          result = 1 ;
          break;
        }
        ptrtemp++;

    }
    listMovies++;
    ptrtemp = listMovies;
  }
  return result;
}

int int main(int argc, char const *argv[]) {
  /* code */

  int myInt;
  int listofMovies[10000];
  scanf("Time of flight :%d", &myInt);
  do{
    scanf(":%d", &listofMovies);

  }while(myInt == EOF);
  return 0;
}
