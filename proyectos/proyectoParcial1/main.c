#include <stdio.h>
#define SIZEINPUTARRAY 	10001
#define SIZEOUTPUTARRAY 80
#define SIZE 			11
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
int proccesData(unsigned char * ptrinArray,unsigned char * ptroutArray);
static char inputArray[SIZEINPUTARRAY];
static char outputArray[SIZEOUTPUTARRAY];


static void getText(unsigned char * ptrArray)
{
	printf("%s\n","inserta texto:" );
	
	fgets(inputArray, (SIZEINPUTARRAY) , stdin);
	
}


static int  checkArray4ValidData ( char * ptrArray)
{	
	unsigned char data2return = 0;

	while((*ptrArray) != '\n' )
	{
		
		data2return |=    checkMayus( ptrArray ) 
						& checkMinus( ptrArray ) 
						& checkNums( ptrArray )
						& checkSpecialchars( ptrArray );
		ptrArray++;
	}
	
	return data2return;

}
//
//static int  checkArray4ValidData (unsigned char * ptrArray2)
//{	
//	unsigned char data2return = 0;
//	unsigned int count=0;
//	do{
//		if ((*ptrArray2)  == '\0')
//		{
//			printf("%s\n", "break:");
//			break;
//		}
//		data2return =	 checkMayus( ptrArray2 ) 
//						| checkMinus( ptrArray2 ) 
//						| checkNums( ptrArray2 )
//						| checkSpecialchars( ptrArray2 );
//	printf("%i\n",data2return );
//	if (data2return)
//	{
//		printf("%c\n",data2return );
//		putchar(*ptrArray2);
//	}
//	ptrArray2++;
//
//	}while((count++) < SIZEINPUTARRAY-1 );
//	
//	return data2return;
//
//}
//
int main ()
{
	int value= 0;
	getText(inputArray);
	value = checkArray4ValidData(inputArray);
	printf("%i\n" ,value);
	if(value )
	{
		printf("%s\n", "Error input");
		return 0; // se que esto no se hace pero no tuve tiempo de corregirlo
	}
	printf("%s\n","valid data" );
	value = proccesData(inputArray,outputArray);
	printf("%s\n","data processed" );
	if(value)
	{
		printf("%s\n","Error procesando datos" );
		return 0; // se que esto no se hace pero no tuve tiempo de corregirlo
	}
	printf("%s\n",outputArray );

	return 0;
}

int proccesData(unsigned char * ptrinArray,unsigned char * ptroutArray)
{
	unsigned char data2return = 2;
	unsigned char spacefree = SIZEOUTPUTARRAY;
	unsigned char * ptrArrayout2move;
	ptrArrayout2move=ptroutArray;
	printf("%s\n","proess data" );
	do{
			printf("%d", spacefree );
		if(0 == spacefree)
		{
			ptrArrayout2move=ptroutArray;
			spacefree = SIZEOUTPUTARRAY;
		}


		if ((specialchars[9] == *ptrinArray))
		{	
			if (0 < spacefree )
			{
				spacefree++;
				ptrArrayout2move--;

			}
			
		}
		else if (specialchars[10] == *ptrinArray)
		{
			spacefree--;
			ptrArrayout2move++;
		}
		else
		{
			spacefree--;
			(*ptroutArray) = (*ptrinArray) ;
		
			printf("%s",(*ptrinArray));
			ptrArrayout2move++;
		}
		
	}while((*ptrinArray++) != EOF );

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

	for (int i = 0; i < SIZE-1; ++i)
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

