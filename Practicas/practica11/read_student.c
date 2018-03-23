#include <stdio.h>
#include <string.h>
typedef struct s
{
	char name 		[20];
	char lastName 	[20];
	unsigned int id;
	unsigned char cal;
}Student;


int main ( int argc, char **argv)
{

	Student myStudent;
	char *lastName = "Perez2";
	char *studentDb = "studenDB.data";
	FILE *data;

	data = fopen(studentDb,"rb");
	while(1)
	{
		fread(&myStudent, sizeof(Student),1,data);
		if(feof(data))
		{
			break;
		}
		if(!strcmp(myStudent.lastName,lastName)){
			printf("name %s\n", myStudent.name);
			printf("lastname %s\n",myStudent.lastName );
			printf("id %d\n",myStudent.id);
			printf("grad %d\n",myStudent.cal);
		}
	}

	fclose(data);
	return 0;
}