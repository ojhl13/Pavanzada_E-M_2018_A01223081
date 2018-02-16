#include <stdio.h>
#define SIZEINPUTARRAY 	10001
#define SIZEOUTPUTARRAY 80
#define SIZE 			10
#define STARTMAYUS 		'A'//65
#define FINISHMAYUS 	'Z'//90
#define STARTMINUS 		'a'//97
#define FINISHMINUS 	'z'//122
#define STARTNUMS		'0'//48
#define FINISHNUMS		'9'//57

const  char specialchars []={'!','?',':','.','-',';',',',' ','>','<'};

int checkMayus ( char * ptrArray);
int checkMinus(unsigned char * ptrArray);
int checkNums(unsigned char * ptrArray);
int checkSpecialchars(unsigned char * ptrArray);
int proccesData( char * ptrinArray, char * ptroutArray);
static char inputArray[SIZEINPUTARRAY];
static char outputArray[SIZEOUTPUTARRAY];


static void getText(unsigned char * ptrArray)
{
	printf("%s\n","inserta texto:" );
	
	if(fgets(inputArray, (SIZEINPUTARRAY) , stdin))
	{

	}
	else
	{
		printf("%s\n", "errror leyendo teclado" );
	}
	
}


static int  checkArray4ValidData ( char * ptrArray)
{	
	unsigned char data2return = 0;
	char *word= ptrArray;

	while(*word != '\n' )
	{
		
		data2return |=    checkMayus( word ) 
						& checkMinus( word ) 
						& checkNums( word )
						& checkSpecialchars( word );
		word++;
	}
	
	return data2return;

}

int main ()
{
	int value= 0;
	getText(inputArray);
	value = checkArray4ValidData(inputArray);
	if(value )
	{
		printf("%s\n", "Error input");
		return 0; // se que esto no se hace pero no tuve tiempo de corregirlo
	}
	value = proccesData(inputArray,outputArray);
	printf("%s\n", (outputArray) );
	return 0;
}

int proccesData( char * ptrinArray, char * ptroutArray)
{
	char *word= ptrinArray;
	unsigned char data2return = 2;
	unsigned char spacefree = SIZEOUTPUTARRAY+1;
	char * ptrArrayout2move;
	ptrArrayout2move=ptroutArray;
	
	while(*word != '\n' )
	{
		
			
		if(0 == spacefree)
		{
			ptroutArray=ptrArrayout2move;
			spacefree = SIZEOUTPUTARRAY;
		}


		if (specialchars[9] == *word)
		{	
			
			if (0 < spacefree )
			{
				
				spacefree++;
				ptroutArray--;// kill edniands 2 hours of my time :'(
				data2return=0;
				
				
			}
			
			
		}
		else if (specialchars[8] == *word)
		{
			spacefree--;
			ptroutArray++;// kill edniands
			data2return=0;
		}
		else
		{
			spacefree--;
			(*ptroutArray) = (*word) ;
			
			ptroutArray++;
			
		}
	word++;
	}



	return data2return;

}




int checkMayus ( char * ptrArray)
{
	unsigned char data2return = 1;
	
	if ((STARTMAYUS <= (*ptrArray)) && ((*ptrArray) <= FINISHMAYUS ))
	{
		data2return = 0;
	}
	else
	{
		data2return = 1;
	}
	return data2return;
}

int checkMinus(unsigned char * ptrArray)
{
	unsigned char data2return = 2;
	if ((STARTMINUS <=(*ptrArray)) && ((*ptrArray) <= FINISHMINUS ))
	{
		data2return = 0;
	}
	else
	{
		data2return = 1;
	}
	return data2return;
}

int checkNums(unsigned char * ptrArray)
{
	unsigned char data2return = 0;
	if ((STARTNUMS <= (*ptrArray)) && ((*ptrArray) <= FINISHNUMS ))
	{
		data2return = 0;
	}
	else
	{
		data2return = 1;
	}
	return data2return;
}

int checkSpecialchars(unsigned char * ptrArray)
{
	unsigned char data2return = 1;
	for (int i = 0; i < (SIZE) ; i++)
	{
		
		if (specialchars[i] == *ptrArray)
		{
			data2return = 0;
			break;
		}
		else
		{
			
		}
 	}
	
	return data2return;
}

