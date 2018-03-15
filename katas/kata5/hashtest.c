
#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "hash.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;


static char * testHashInit() {
int sizeHash = 100;
HashInt hash;
hashInit(&hash,sizeHash);
muAssert("error, hash size unexpected", hash.size == sizeHash );
muAssert("error, hash data shouldn't be NULL", hash.data != NULL );
return 0;
}

static char * testHashInsert() {
unsigned sizeHash = 1;
HashInt hash;
hashInit(&hash,sizeHash);
hashInsert(&hash,"cuarenta",40);
hashInsert(&hash,"cincuenta",50);
printf("hash.data = %p\n",hash.data[0].elements);
muAssert("error, first key cuarenta", strcmp(hash.data[0].elements[0].key,"cuarenta") == 0);
muAssert("error, second key cincuenta", strcmp(hash.data[0].elements[1].key,"cincuenta") == 0);
muAssert("error, first key cuarenta", hash.data[0].elements[0].value == 40);
muAssert("error, second key cincuenta", hash.data[0].elements[1].value == 50);
return 0;
}

static char * testHashGet() {
int sizeHash = 1;
int *value;
int *noValue;
HashInt hash;
hashInit(&hash,sizeHash);
hashInsert(&hash,"cuarenta",40);
hashInsert(&hash,"cincuenta",50);
value = hashGet(&hash,"cincuenta");
noValue = hashGet(&hash,"cien");
muAssert("error, value must be 50", *value == 50);
muAssert("error, novalue must be NULL", noValue == NULL);
return 0;
}

static char * testHashUpsert() {
unsigned sizeHash = 1;
HashInt hash;
hashInit(&hash,sizeHash);
hashInsert(&hash,"cuarenta",40);
hashInsert(&hash,"cuarenta",80);
muAssert("error, first key cuarenta", strcmp(hash.data[0].elements[0].key,"cuarenta") == 0);
muAssert("error, first value 80", hash.data[0].elements[0].value == 80);
return 0;
}

static char * allTests() {
muRunTest(testHashInit);
muRunTest(testHashInsert);
muRunTest(testHashGet);
muRunTest(testHashUpsert);
return 0;
}

int main(int argc, char **argv) {
 char *result = allTests();
 if (result != 0) {
printf("░░░░░░░░░░░░░░░░░░░░░░█████████\n");
printf("░░░░░░░░░░░░░░░░░░░░███▒▒▒▒▒▒▒▒███\n");
printf("░░░░░░░░░░░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███\n");
printf("░░░░░░░░░░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░░░░░█████░░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███\n");
printf("░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██\n");
printf("░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("██▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██\n");
printf("██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒██\n");
printf("░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█\n");
printf("░░████████████░░░█████████████████\n");
printf(KRED "✗ %s \n" RESET, result);
 }
 else {

printf("░░░░░░░░░░░░░░░░░░░░░░█████████\n");
printf("░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███\n");
printf("░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███\n");
printf("░░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███\n");
printf("░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██\n");
printf("░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██\n");
printf("██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██\n");
printf("█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██\n");
printf("██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
printf("░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█\n");
printf("░░████████████░░░█████████████████\n");
 printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
 }
 printf("Tests run: %d\n", testsRun);
 return result != 0;
}