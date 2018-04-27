/******************************************************************************

Online C Compiler.
Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
/*this code work for little endian*/
#define NUMELEMS(x)  (sizeof(x) / sizeof((x)[0]))
typedef struct
{
  unsigned int NibbleL:4;
  unsigned int NibbleH:4;
} Nibbles_t;
typedef struct
{
  unsigned int B7:1;
  unsigned int B6:1;
  unsigned int B5:1;
  unsigned int B4:1;
  unsigned int B3:1;
  unsigned int B2:1;
  unsigned int B1:1;
  unsigned int B0:1;

} Bits_t;
typedef struct
{



  unsigned int PLow:2;
  unsigned int PMiddle:2;
  unsigned int PHigh:2;
  unsigned int PUpper:2;

} B_IN_Pairs_t;
typedef union I
{
  unsigned int data;
  Nibbles_t Nibble;
  Bits_t Bits;
  B_IN_Pairs_t PairsofB;

} Integer_t;

#define TRUE 1
#define FALSE 0


unsigned int
validUTF8Format (unsigned int *ptrarray,unsigned int sizearray)
{
  unsigned int byte2ret;
  unsigned int lenght;
  unsigned int i;
  byte2ret = 0;
  lenght = 0;
  i = 0;
  if (1 == ((*ptrarray).Bits.B7))
  {
    byte2ret = TRUE;
    if (1 == ((*ptrarray).Bits.B6))	/*0b11XXXXXX */
    {
      if (1 == ((*ptrarray).Bits.B5))	/*0b111XXXXX */
      {
        if (1 == ((*ptrarray).Bits.B4))	/*0b1111XXXX */
        {
          if (0 == ((*ptrarray).Bits.B4))	/*0b11110XXX */
          {

            lenght = 4;
          }
        }
        else		/*3 bytes */
        {
          lenght = 3;
        }
      }
      else			/*2 bytes */
      {
        lenght = 2;
      }
      ptrarray++;
    }
    else			/*only one byte for th format */
    {
      if(1 == sizearray)
      {
      byte2ret = TRUE;
      }
    }
    if ((0 != lenght) && (sizearray == lenght))
    {
      do
      {
        if ((0b10) != ((*ptrarray).PairsofB.PUpper))
        {
            byte2ret = FALSE;
            break;
        }
      }

      while (i++ < lenght);
    }
    else
    {
          byte2ret = FALSE;
    }
    return byte2ret;
  }



  int main (int argc, char const *argv[])
  {
    /* code */
    Integer_t data[4];
    integers
    int n;
    n=scanf("%s\n","Number of integers" );
    while (n-- >= 0) {

    }
  }
