
#include <stdio.h>

int main(void)
{

   int a[] = {100, 105, 107, 108, 110};

   int b[2];

   int c[3];

   int i = 0;

   int indexB = 0;
   int indexC = 0;

   for (i = 0; i < 5; i++)
   {
      if (i < 2)
      {
         b[indexB] = a[i];
         indexB++;
      }
      else
      {
         c[indexC] = a[i];
         indexC++;
      }
   }

   for (i = 0; i < 5; i++)
   {
      printf("Array a index: %d %d \n", i, a[i]);
   }

   printf("*************************************************\n");

   for (i = 0; i < 2; i++)
   {
      printf("Array b index: %d %d \n", i, b[i]);
   }

   printf("*************************************************\n");

   for (i = 0; i < 3; i++)
   {
      printf("Array c index: %d %d \n", i, c[i]);
   }

   return 0;
}