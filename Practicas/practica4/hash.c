
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
 if( hash->data[index].elements == NULL) {
 hash->data[index].elements = (Element *)malloc(4*sizeof(Element));
 hash->data[index].count = 0;
 }
 hash->data[index].elements[hash->data[index].count].key = strdup(key);
 hash->data[index].elements[hash->data[index].count].value = value;
 hash->data[index].count += 1; 
};