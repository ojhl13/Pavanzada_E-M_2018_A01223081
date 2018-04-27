#include <stdio.h>
#define MASK_FULL   0b010
#define MASK_DELETE 0b001
typedef struct s{
  char f:3;
}Flags;

int main(int argc, char const *argv[]) {
  /* code */
  Flags status;
  status.f = 0b100;
  if( (status.f & MASK_FULL) == MASK_FULL)
  {
    printf("%s\n", "The data is full" );
  }
  return 0;
}
