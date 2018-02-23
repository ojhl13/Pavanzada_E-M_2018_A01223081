
typedef struct e {
 char *key;
 int value;
} Element;

typedef struct d {
 Element *elements;
 int count;
} HashElement;
 
typedef struct h {
 HashElement *data;
 int size;
 ///
} HashInt;

void hashInit(HashInt *,int);
void hashInsert(HashInt *,char *,int);