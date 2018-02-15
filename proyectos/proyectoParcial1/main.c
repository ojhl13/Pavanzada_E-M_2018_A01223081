#include <stdio.h>
#define SIZEINPUTARRAY 	10001
#define SIZEOUTPUTARRAY 80
#define STARTMAYUS 		65
#define FINISHMAYUS 	90
#define STARTMINUS 		97
#define FINISHMINUS 	122
#define STARTNUMS		48
#define FINISHNUMS		57
#define SCHAR1			33  /*!*/
#define SCHAR2			63  /*?*/
#define SCHAR3			58  /*:*/
#define SCHAR4			46  /*.*/
#define SCHAR5			45  /*-*/
#define SCHAR6			59  /*;*/
#define SCHAR7			44  /*,*/
#define SCHAR8			32  /* */
#define SCHARNEXT		62  /*>*/
#define SCHARBACK		60	/*<*/

int checkMayus (unsigned char * ptrArray);
int checkMinus(unsigned char * ptrArray);
int checkNums(unsigned char * ptrArray);
int checkSpecialchars(unsigned char * ptrArray);
int proccesData(unsigned char * ptrinArray,unsigned char * ptroutArray);
static char inputArray[SIZEINPUTARRAY];
static char outputArray[SIZEOUTPUTARRAY];


static void getText(unsigned char * ptrArray)
{
	printf("%s\n","inserta texto:" );
	
	fgets(ptrArray, (SIZEINPUTARRAY) , stdin);
	
}

static int  checkArray4ValidData (unsigned char * ptrArray2)
{	
	unsigned char data2return = 0;
	unsigned int count=0;
	printf("%s\n", "startcheck");
	do{
		if (*ptrArray2 == EOF)
		{
			break;
		}
	
		data2return =	checkMayus( ptrArray2 ) 
						| checkMinus( ptrArray2 ) 
						| checkNums( ptrArray2 )
						| checkSpecialchars( ptrArray2 );
	if (data2return)
	{
		printf("%c\n",data2return );
		putchar(*ptrArray2);
	}
	ptrArray2++;

	}while((count++) < SIZEINPUTARRAY );
	
	return data2return;

}

int main ()
{
	int value= 0;
	getText(inputArray);

	if(checkArray4ValidData(inputArray) )
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


		if ((SCHARBACK == *ptrinArray))
		{	
			if (0 < spacefree )
			{
				spacefree++;
				ptrArrayout2move--;

			}
			
		}
		else if (SCHARNEXT == *ptrinArray)
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




int checkMayus (unsigned char * ptrArray)
{
	unsigned char data2return = 2;

	if (STARTMAYUS <*ptrArray < FINISHMAYUS )
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
	if (STARTMINUS <*ptrArray < FINISHMINUS )
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
	unsigned char data2return = 2;
	if (STARTNUMS <*ptrArray < FINISHNUMS )
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
	unsigned char data2return = 2;

	if (	( SCHAR1 == *ptrArray ) 
		|| 	( SCHAR2 == *ptrArray ) 
		|| 	( SCHAR3 == *ptrArray ) 
		|| 	( SCHAR4 == *ptrArray ) 
		||  ( SCHAR5 == *ptrArray )
		||  ( SCHAR6 == *ptrArray )
		||  ( SCHAR7 == *ptrArray )
		||  ( SCHARNEXT == *ptrArray )
		||  ( SCHARBACK == *ptrArray )
		)
	{
		data2return = 0;
	}
	else
	{
		data2return = 1;
	}
	return data2return;
}

