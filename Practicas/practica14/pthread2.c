#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NUM_THREADS 20
static int counter=0;
void * helloWorld(void *p)
{
    long id = (long)p;
    char *msg = (char*) malloc(25*sizeof(char));
    sprintf("%s %d \n", "Hello World threads", id );
    counter++;
    return (void*)msg;
}


int main(int argc, char const *argv[]) {
  /* code */
  pthread_t threads[NUM_THREADS];
  int i;
  char *msg;
  printf("%s\n",  "start");
  do {
    pthread_create(
        &threads[i],
        NULL,
        helloWorld,
        (void*) i
    );
  } while(i++ < NUM_THREADS);
  i=0;
  do {
    pthread_join(
      threads[i],
      (void*)&msg);
      printf("%s", msg );
      free(msg);
    } while(i++ < NUM_THREADS);
    printf("%s\n", "finish" );
  return 0;
}
