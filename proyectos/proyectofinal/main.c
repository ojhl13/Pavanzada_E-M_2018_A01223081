#include <stdlib.h>

#define Kamehameha_Atack(a,b) do{(((a)<(b))?(a):(b))}while(0)

#define MAXSIZE     1000000000
#define MAXTESTCASE 10
#define MAXENEMYS   1000

typedef unsigned int uint

static char ArrayX [MAXSIZE];
static char ArrayY [MAXSIZE];
static int enemiesFiles;
static int enemiesColums;

void Kamehameha_Charging(uint x , uint y)
{

  if(0 == ArrayX[x] )
  {
    ArrayX[x]=1;
    enemiesFiles++;
  }
  if (0 == ArrayY[y]) {
    ArrayY[y] = 1;
    enemiesColums++;
  }
}




int main(int argc, char const *argv[]) {
  uint numTestCases;
  uint numEnemys;
  uint coordinateX;
  uint coordinateY;
  enemiesFiles=0;
  enemiesColums=0;
  ArrayX = calloc(MAXSIZE,sizeof(uint));
  ArrayY = calloc(MAXSIZE,sizeof(uint));
  scanf("%d\n", &numTestCases );
  if(numTestCases <=MAXTESTCASE){
    while (testcase--) {
      scanf("%d\n", &numEnemys );
      if(numEnemys <= MAXENEMYS)
      {
        while(numEnemys--)
        {
          scanf("%d %d\n", &coordinateX, &coordinateY );
          Kamehameha_Charging(coordinateX,coordinateY);
        }
        printf("%d\n", Kamehameha_Atack(enemiesFiles,enemiesColums));
      }
      else
      {
          printf("%s\n", "error more than 1000 enemies");
      }
    }
  }
  else
  {
    printf("%s\n", "error more than 10 cases");
    return 0;
  }
}
