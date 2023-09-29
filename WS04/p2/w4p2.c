/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #4 (P2)

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
    int applesNumber, orangesNumber, pearsNumber, tomatoesNumber, cabbagesNumber;
    int continueShopping;

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        // Input for the quantity of each item
        printf("How many APPLES do you need? : ");
        scanf("%d", &applesNumber);
        while (applesNumber < 0)
        {
            printf("ERROR: Value must be 0 or more. How many APPLES do you need? : ");
            scanf("%d", &applesNumber);
        }

        printf("How many ORANGES do you need? : ");
        scanf("%d", &orangesNumber);
        while (orangesNumber < 0)
        {
            printf("ERROR: Value must be 0 or more. How many ORANGES do you need? : ");
            scanf("%d", &orangesNumber);
        }

        printf("How many PEARS do you need? : ");
        scanf("%d", &pearsNumber);
        while (pearsNumber < 0)
        {
            printf("ERROR: Value must be 0 or more. How many PEARS do you need? : ");
            scanf("%d", &pearsNumber);
        }

        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoesNumber);
        while (tomatoesNumber < 0)
        {
            printf("ERROR: Value must be 0 or more. How many TOMATOES do you need? : ");
            scanf("%d", &tomatoesNumber);
        }

        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbagesNumber);
        while (cabbagesNumber < 0)
        {
            printf("ERROR: Value must be 0 or more. How many CABBAGES do you need? : ");
            scanf("%d", &cabbagesNumber);
        }

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");

        // Picking items loop
        int pickedApples, pickedPears, pickedCabbages = 0;

        int needApples = applesNumber;
        int needPears = pearsNumber;
        int needCabbages = cabbagesNumber;

        int picked;

        // Pick Apples
        while (needApples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &picked);

            if (picked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }

            if (picked > needApples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed. ", needApples);
                continue;
            }

            pickedApples = pickedApples + picked;
            needApples = needApples - picked;
            picked = 0;

            if (needApples > 0)
            {
                printf("Looks like we still need some APPLES...\n");
            }
            else
            {
                printf("Great, that's the applesNumber done!\n");
            }
        }

        // Pick Pears
        while (needPears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &picked);

            if (picked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (picked > needPears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed. ", needPears);
                continue;
            }

            pickedPears = pickedPears + picked;
            needPears = needPears - picked;
            picked = 0;

            if (needPears > 0)
            {
                printf("Looks like we still need some PEARS...\n");
            }
            else
            {
                printf("Great, that's the pearsNumber done!\n");
            }
        }

        // Pick Cabbages

        while (needCabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &picked);

            if (picked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
                continue;
            }
            if (picked > needCabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed. ", needCabbages);
                continue;
            }

            pickedCabbages += picked;
            needCabbages -= picked;
            picked = 0;

            if (needCabbages > 0)
            {
                printf("Looks like we still need some CABBAGES...\n");
            }
            else
            {
                printf("Great, that's the cabbagesNumber done!\n");
            }
        }

        printf("All the items are picked!\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);

    } while (continueShopping != 0);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
