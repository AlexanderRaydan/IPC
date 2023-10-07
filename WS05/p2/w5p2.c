/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #5 (P2)

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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define MAX_RAITING 5.0
#define MIN_RAITING 0.0
#define LOG_DAYS 3
#include <stdio.h>

int main(void)
{

    const int JAN = 1;
    const int DEC = 12;
    int year, month = 0;
    double morningRaiting, eveningRaiting = 0.0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        // wrong year case
        if ((year < MIN_YEAR) || (year > MAX_YEAR))
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        // wrong month case
        if ((month < JAN) || (month > DEC))
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

    } while (!((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC)));

    printf("\n*** Log date set! ***\n");

    double value = 0.0;
    int i = 1;

    for (; i <= LOG_DAYS; i++)
    {

        printf("\n");

        if (month == 1)
        {
            printf("%d-JAN-0%d\n", year, i);
        }
        else if (month == 2)
        {
            printf("%d-FEB-0%d\n", year, i);
        }
        else if (month == 3)
        {
            printf("%d-MAR-0%d\n", year, i);
        }
        else if (month == 4)
        {
            printf("%d-APR-0%d\n", year, i);
        }
        else if (month == 5)
        {
            printf("%d-MAY-0%d\n", year, i);
        }
        else if (month == 6)
        {
            printf("%d-JUN-0%d\n", year, i);
        }
        else if (month == 7)
        {
            printf("%d-JUL-0%d\n", year, i);
        }
        else if (month == 8)
        {
            printf("%d-AGO-0%d\n", year, i);
        }
        else if (month == 9)
        {
            printf("%d-SEP-0%d\n", year, i);
        }
        else if (month == 10)
        {
            printf("%d-OCT-0%d\n", year, i);
        }
        else if (month == 11)
        {
            printf("%d-NOV-0%d\n", year, i);
        }
        else
        {
            printf("%d-DEC-0%d\n", year, i);
        }

        do
        {
            printf("   Morning rating (%.1lf-%.1lf): ", MIN_RAITING, MAX_RAITING);
            scanf("%lf", &value);

            if ((value < MIN_RAITING) || (value > MAX_RAITING))
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RAITING, MAX_RAITING);
            }
            else
            {
                morningRaiting += value;
            }

        } while (!(value >= MIN_RAITING && value <= MAX_RAITING));

        value = 0.0;

        do
        {
            printf("   Evening rating (%.1lf-%.1lf): ", MIN_RAITING, MAX_RAITING);
            scanf("%lf", &value);

            if ((value < MIN_RAITING) || (value > MAX_RAITING))
            {
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RAITING, MAX_RAITING);
            }
            else
            {
                eveningRaiting += value;
            }

        } while (!(value >= MIN_RAITING && value <= MAX_RAITING));
    }

    double overallTotalRating = morningRaiting + eveningRaiting;

    double averageMorningRating = (morningRaiting / (double)LOG_DAYS);
    double averageEveningRating = (eveningRaiting / (double)LOG_DAYS);
    double averageOverallRating = (overallTotalRating / ((double)(LOG_DAYS * 2)));

    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningRaiting);
    printf("Evening total rating:  %.3lf\n", eveningRaiting);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", overallTotalRating);

    printf("Average morning rating:  %.1lf\n", averageMorningRating);
    printf("Average evening rating:  %.1lf\n", averageEveningRating);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", averageOverallRating);

    return 0;
}