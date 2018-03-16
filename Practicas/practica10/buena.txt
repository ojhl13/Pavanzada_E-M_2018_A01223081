#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef PRINTDEBUG
#define PRINTDEBUG(...) do{											\
						char *debug;								\
						debug = getenv("DEBUG");					\
						if( debug != NULL && !strcmp(debug,"y") ) {	\
							fprintf(stderr, __VA_ARGS__ );			\
						}											\
							}while(0)
						
#endif

int main()
{
	int character;
	while(1)
	{
		character = fgetc(stdin);
		if( feof(stdin))
		{
			break;
		}
		//fputc(character,stdout);
		fputc(character,stdout);
		PRINTDEBUG("character = %c\n", character );

	}
	return 0;
}