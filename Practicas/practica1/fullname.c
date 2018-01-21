#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void doFullName(char *firstName, char *lastName, char **fullNameValue)
{
	int sizeFirstName = strlen(firstName);
	int sizeLastName = strlen(lastName);
	int sizeFullName = sizeFirstName + sizeLastName;

	char *fullName = (char *) malloc(sizeFullName * sizeof(char));

	strcpy(fullName, firstName);
	strcpy(fullName + sizeFirstName, " ");
	strcpy(fullName + sizeFirstName + 1, lastName);
	*fullNameValue = fullName;
}

void main()
{
	char firstName[] = "Oscar";
	char lastName[]  = "Hinojosa";
	char *fullName;
	doFullName(firstName, lastName, &fullName);
	printf("%s \n", fullName);
}

