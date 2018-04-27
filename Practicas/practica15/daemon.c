#include <stdio.h>




int main(int argc, char const *argv[]) {
  int pid = fork();
  if(pid ==0 )
  {
    pid = fork();
    if (pid == 0) {
      printf("%s\n", "soy el demonio");
      /* code */while(1);
      return 0;
    }
  }
  return 0;
}
