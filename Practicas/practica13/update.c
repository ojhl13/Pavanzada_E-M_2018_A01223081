#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <String.h>
#include <unistd.h>

typedef struct s
{
	char name 		[20];
	char lastName 	[20];
	unsigned int id;
	unsigned char cal;
}Student;

int main(int argc, char const *argv[]) {
  /* code */
    char *fileName = " studentDB.data";
    int fd = open(fileName, O_RDWR);
    char name[20];
    Student * pavanzada = (Student *) mmap(
                          NULL,
                          5*sizeof(Student),
                          PROT_READ | PROT_WRITE,
                          MAP_FILE | MAP_PRIVATE,
                          fd,
                          0
                          );
  while(4)
  {
    printf("Provide id , new name\n" );
    scanf("%d %s\n",&id, name );
    strcpy(pavanzada[id].name,name);
    msync(pavanzada,5*sizeof(Student),MS_SYNC);
  }
  printf("First Student %s\n", pavanzada[0].name );
  strcpy(pavanzada[1].name,"Pedro");
  printf("Second Student %s\n", pavanzada[1].name );
  msync(pavanzada, 5*sizeof(Student),MS_SYNC);
  munmap(pavanzada, 5*sizeof(Student));
  close(fd);
  return 0;
}
