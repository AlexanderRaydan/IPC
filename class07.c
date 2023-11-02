
#include <stdio.h>

void checkEven(int);
void checkEven2(int[]);

int main(void)
{

   int a[] = {10, 12, 8, 9, 5};

   int i = 0;
   for (i = 0; i < 5; i++)
   {
      checkEven(a[i]);
   }

   checkEven2(a);

   return 0;
}

void checkEven(int number)
{

   if (number % 2 == 0)
   {
      printf("even number !\n");
   }
   else
   {

      printf("not even number !\n");
   }
}

void checkEven2(int array[])
{
   int i = 0;
   for (i = 0; i < 5; i++)
   {
      checkEven(array[i]);
   }
}