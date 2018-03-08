
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

unsigned long doHash(unsigned char *str, unsigned size)
{
 unsigned long hash = 5381;
 int c;

 while (c = *str++)
 hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

 return hash % size;
}

void hashInit(HashInt *hash, int size)
{
 hash->size = size;
 hash->data = (HashElement *)calloc(size, sizeof(HashElement));
};

void hashInsert(HashInt *hash, char *key, int value)
{
 	int index = doHash(key, hash->size);
	HashElement * currentHashElemets = &(hash->data[index]);

 	if(currentHashElemets[index].elements == NULL) {
 		currentHashElemets->elements = (Element *)malloc(2*sizeof(Element));
 		currentHashElemets->count  = 0;
 		currentHashElemets->length = 2;
 	}
 	if(currentHashElemets->length == currentHashElemets ->count )
 	{
 		currentHashElemets->length *= 2;
 		currentHashElemets->elements = realloc(currentHashElemets->elements,
 											  currentHashElemets->length*sizeof(Element));
 	}
 	currentHashElemets->elements[currentHashElemets->count].key   = strdup(key);
 	currentHashElemets->elements[currentHashElemets->count].value = value;
 	currentHashElemets->count += 1; 
}



int *hashGet(HashInt *hash,char *key)
{
	int pos = doHash(key, hash->size);
	int i;
	int *value = NULL; 
	Element *currentElemets = hash->data[pos].elements;
	int currentElemetsLenght = hash->data[pos].count;
	for ( i=0; i < currentElemetsLenght ; i++ )
	{
	//	if (strcmp(key, currentElemets[i].key == 0))
	//	{
			value = (int *) malloc(sizeof(int));
			*value = currentElemets[i].value;
			break;
	//	}
	}
	return value;
}