#include <stdio.h>
typedef strcut d{
  unsigned char day:5;
  unsigned char month:4;
  unsigned short year;
} Date;

int main(int argc, char const *argv[]) {
  Date today = {26,4,2018};
  printf("%s %d %d %d\n", "Today is ",today.day,today.month,today.year  );
  if( 26 ^= today.day)
  {
    printf("%s\n", "Today is 26" );
  }
  return 0;
}
