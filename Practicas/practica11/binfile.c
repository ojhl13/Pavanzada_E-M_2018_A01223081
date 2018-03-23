#include <stdio.h>

typedef struct s
{
	char name 		[20];
	char lastName 	[20];
	unsigned int id;
	unsigned char cal;
}Student;

int main (int argc, char **argv)
{

	char * studentDB = "studentDB.data";
	FILE * data;
	Student pAvanzada[5];
	for (int i = 0; i < 5; ++i)
	{
		sprintf(pAvanzada[i].name, "studen%d" , i );
		sprintf(pAvanzada[i].lastName,"Perez%d", i);
		pAvanzada[i].id = i * 20;
		pAvanzada[i].cal = 70;
	}

	data = fopen (studentDB , "bw" );
	fwrite(pAvanzada,sizeof(Student),5,data);
	fclose(data);
	return 0;
}