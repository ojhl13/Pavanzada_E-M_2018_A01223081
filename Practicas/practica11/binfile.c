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

	char *studentDB = "studentDB.data";
	FILE *data;
	Student pAvanzada[5];
	printf("%s\n", "inicio el for" );
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", i);
		sprintf(pAvanzada[i].name, "studen%d" , i );
		sprintf(pAvanzada[i].lastName,"Perez%d", i);
		pAvanzada[i].id = i * 20;
		pAvanzada[i].cal = 70;
	}
	printf("%s\n", "sali del for" );

	data = fopen (studentDB , "wb" );
	printf("%s\n", "abrir el archivo" );
	fwrite(pAvanzada , sizeof(Student) , 4 , data );
	printf("%s\n",  "Escribir el archivo");
	fclose(data);
	return 0;
}