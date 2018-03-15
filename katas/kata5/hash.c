
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#define HASH_DEBUG "HASH_DEBUG"

void printDebug(char *msg)
{
	char *hashDebug = getenv(HASH_DEBUG);
	if (hashDebug != NULL && strcmp(hashDebug, "y") == 0)
	{
		printf("%s\n", msg);
	}
}

unsigned
doHash(unsigned char *str, unsigned size)
{
unsigned hash = 5381;
int c;

while (c = *str++)
hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

return hash % size;
}

void hashInit(HashInt *hash, unsigned size)
{
hash->size = size;
hash->data = (HashElement *)calloc(size, sizeof(HashElement));
};

static void hashDoInsert(HashInt *hash, char *key, int value)
{
char errorMessage[255];
printDebug("dohash");
unsigned index = doHash(key, hash->size);
printDebug("dohash2");
HashElement *currentHashElement = &(hash->data[index]);
sprintf(errorMessage, "index %d", index);
printDebug(errorMessage);
if (currentHashElement->elements == NULL)
{
printDebug("CHECKING DATA");
currentHashElement->elements = (Element *)malloc(2 * sizeof(Element));
currentHashElement->count = 0;
currentHashElement->length = 2;
}
if (currentHashElement->length == currentHashElement->count)
{
currentHashElement->length *= 2;
currentHashElement->elements = (Element *)realloc(currentHashElement->elements,
currentHashElement->length * sizeof(Element));
}
printDebug("Assigning");
currentHashElement->elements[currentHashElement->count].key = strdup(key);
currentHashElement->elements[currentHashElement->count].value = value;
currentHashElement->count += 1;
printDebug("Completed");
}

static void hashDoUpdate(HashInt *hash, char *key, int value)
{
int pos = doHash(key, hash->size);
int i;
Element *currentElements = hash->data[pos].elements;
int currentElementsLength = hash->data[pos].count;

for (i = 0; i < currentElementsLength; i++)
{
if (strcmp(key, currentElements[i].key) == 0)
{
currentElements[i].value = value;
break;
}
}
}

void hashInsert(HashInt *hash, char *key, int value)
{
int *oldValue = hashGet(hash, key);
if (oldValue == NULL)
{
hashDoInsert(hash, key, value);
}
else
{
hashDoUpdate(hash,key,value);
}
};

int *hashGet(HashInt *hash, char *key)
{
int pos = doHash(key, hash->size);
int i;
Element *currentElements = hash->data[pos].elements;
int currentElementsLength = hash->data[pos].count;
int *value = NULL;

for (i = 0; i < currentElementsLength; i++)
{
if (strcmp(key, currentElements[i].key) == 0)
{
value = (int *)malloc(sizeof(int));
*value = currentElements[i].value;
break;
}
}
return value;
};


void forEach ( HashInt *hash, void(* func)(char *key, int value))
{
	int i;
	int j;
	for ( i=0 ; i < hash->size; i++)
	{
		if ( NULL != hash->data[i].elements)
		{
			for ( j = 0 ;  j < hash->data[i].count ; j++  )
			{
				func(hash->data[i].elements[j].key , hash->data[i].elements[j].value);
			}
		}
	}
}