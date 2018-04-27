#include <stdio.h>

typedef union i{
   unsigned char parts[4];
   unsigned dir;
}

int main(int argc, char const *argv[])
  /* code */
  IPadress myAdress;
  myAdress.parts[0]=127;
  myAdress.parts[1]=0;
  myAdress.parts[2]=0;
  myAdress.parts[3]=0;

  printf("The numbers is %u \n",myAdress.dir );
  myAdress.dir=1;
  printf("%s %d %d \n","The", myAdress.parts[0],myAdress.parts[3] );
  return 0;
}
