/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Midori Sasahara
Student ID#: 132466236
Email      : msasahara@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{

    // int repeats, i;
    // char loopType;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    if ('W' == 'W')
    {
        printf("true\n");
    }

    if (0)
    {
        printf("also true\n");
    }

    if (('W' == 'Q') || 'AAA')
    {
        printf("also true\n");
    }

    // do
    // {
    //     printf("D = do/while | W = while | F = for | Q = quit\n");
    //     printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    //     scanf(" %c%d", &loopType, &repeats);

    //     if ((loopType == 'D' || loopType == 'W' || loopType == 'F') && (repeats < 3 || repeats > 20))
    //     {
    //         printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
    //     }
    //     else
    //     {
    //         if (loopType == 'D')
    //         {
    //             printf("DO-WHILE: ");
    //             do
    //             {
    //                 printf("%c", loopType);
    //             } while (--repeats);
    //         }

    //         printf("\n\n");

    //         if (loopType == 'W')
    //             printf("WHILE   : ");
    //         while (repeats--)
    //         {
    //             printf("%c", loopType);
    //         }
    //         printf("\n\n");

    //         if (loopType == 'F')
    //             printf("FOR     : ");
    //         for (i = 0; i < repeats; repeats++)
    //         {
    //             printf("%c", loopType);
    //         }

    //         if (loopType != 'D' || 'W' || 'F')
    //         {
    //             printf("ERROR: Invalid entered value(s)!\n");
    //         }

    //         if ((loopType == 'Q' && repeats != 0))
    //         {
    //             printf("ERROR: To quit, the number of iterations should be 0!\n");
    //         }
    //         printf("\n\n");
    //     }

    // } while (!(loopType == 'Q' && repeats == 0)); //(condition to q)

    // // ptintf("\n\n");
    // printf("\n\n");

    // printf("+--------------------+\n");
    // printf("Loop application ENDED\n");
    // printf("+--------------------+\n");

    return 0;
}

/*do {
    statements ...:
}while ( condition )


while ( condition )
{

}

int x = 0 // same thing as putting initiarization in ()
for ( initiarizaion// runs once); condition ; compertment)
for (int x = 0; x < 10; x++)
{
   printf("Hello world");
}*/

/*slices = 4;
while (condition)
{
slices--;
printf("Gulp! Slices left %d\n", slices);
}*/

/*int number;

char letter;

printf("+----------------------+\n");
printf("Loop application STARTED\n");
printf("+----------------------+\n\n");

printf("D = do/while | W = while | F = for | Q = quit\n");
printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
scanf(" %c%d", &letter, &number);

//ifとelseの終わりは？？

if ((letter == ('D' || 'W' || 'F' || 'Q')) && (number <= 3 || number >= 20))
    printf("");

else if ((letter == ('D' || 'W' || 'F' || 'Q')) && (number > 3 || number < 20))
    printf("ERROR: The number of iterations must be between 3-20 inclusive!");

else if (letter == 'Q' && number != 0)
    printf("ERROR: To quit, the number ofs iterations should be 0!");

else if (letter == 'D' && number <= 3 || number >= 20)
    printf("DO-WHILE: %c", letter); // 入力された数字を表示する方法？

else if (letter == 'W' && number <= 3 || number >= 20)
    printf("WHILE : %c", letter);

else if (letter == 'F' && number <= 3 || number >= 20)
    printf("FOR : %c", letter);*/

// printf("\n letter: %c number: %d\n" , letter , number);