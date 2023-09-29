/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #4

Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZBB

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    char loopType;
    int numberIterations;
    int index = 0;

    do
    {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numberIterations);

        if ((loopType == 'Q' && numberIterations != 0))
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
            continue; // next iteration
        }

        if (!(loopType == 'D' || loopType == 'W' || loopType == 'F' || loopType == 'Q'))
        {
            printf("ERROR: Invalid entered value(s)!\n");
            continue; // next iteration
        }

        if (!((numberIterations >= 3 && numberIterations <= 20) || numberIterations == 0))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            continue; // next iteration
        }

        index = numberIterations;

        switch (loopType)
        {
        case 'D':
            printf("DO-WHILE: ");
            do
            {
                printf("D");
                index--;
            } while (index > 0);
            break;
        case 'W':
            printf("WHILE   : ");
            while (index > 0)
            {
                index--;
                printf("W");
            }
            break;
        case 'F':
            printf("FOR     : ");
            for (; index > 0; index--)
            {
                printf("F");
            }
            break;
        }
        printf("\n");

    } while (!(loopType == 'Q' && numberIterations == 0));

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}