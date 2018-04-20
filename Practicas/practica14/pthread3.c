#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 20
static int counter=0;

int varglobal;
sem_t sema;
void * helloWorld(void *p)
{
    int id = (int)p;
    printf("%s %d \n", "Hello World threads", id );
    sem_wait(&sema);
    varglobal += 100;
    sem_post(&sema);
    return NULL;
}


int main(int argc, char const *argv[]) {
  /* code */
  pthread_t threads[NUM_THREADS];
  int i;
  varglobal =0;
  printf("%s\n",  "start");
  sem_init(&sema,0,1);
  do {
    pthread_create(
        &threads[i],
        NULL,
        helloWorld,
        (void*)i
    );
  } while(++i < NUM_THREADS);
  i=0;
  do {
    pthread_join(
      threads[i],
      NULL
      );
      printf("varglobal = %d\n",  varglobal);
    } while(++i < NUM_THREADS);
    printf("%s\n", "finish" );
  return 0;
}
