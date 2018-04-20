#include <stdio.h>
#define NUM_THREADS 20
static int counter=0;
void * helloWorld(void *p)
{
    int id = (int)p;
    printf("%s %d \n", "Hello World threads", id );
    counter++;
    return NULL;
}


int main(int argc, char const *argv[]) {
  /* code */
  pthread_t threads[NUM_THREADS];
  int i;
  printf("%s\n",  "start");
  do {
    pthread_create(
        &threads[i],
        NULL,
        helloWorld,
        (void*)i
    );
  } while(i++ < NUM_THREADS);
  i=0;
  do {
    pthread_join(
      threads[i],
      NULL
      );
    } while(i++ < NUM_THREADS);
    printf("%s\n", "finish" );
  return 0;
}
