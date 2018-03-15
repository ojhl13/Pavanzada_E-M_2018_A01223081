#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "hash.h"

/* Add function signatures here */
void printFrequencies( char *key, int value)
{
	printf("%s %d \n", key, value);
}
int main(int argc, char **argv) {
  /* Start your code here */
	int character;
	char word[256];
	int j;
	HashInt hash;
	int *value;
	int realvalue;

	hashInit( &hash , 100);

	while( !feof(stdin))//( (chacarter = fgetc(stdin) ) == 'EOF' ) /*idioms */
	{	
		
		character = fgetc(stdin);
		if (isalnum(character)) 
		{
			word[j] = (char) tolower(character) ;
			j++;
		}
		else
		{
			word[j] = '\0';	
			if ( j > 0 )
			{
				//printf("%s\n",word);
				value = hashGet(&hash,word);
				if (NULL == value)
				{
					realvalue = 1;
					
				}
				else
				{
					realvalue = *value + 1;
				}
				
				hashInsert(&hash,word,realvalue);

			}
			j=0;
			//printf("%d\n", '\0' );

		}
		//putc (chacarter, stdout);
	}
	forEach( &hash , &printFrequencies);	
  return 0;
}
