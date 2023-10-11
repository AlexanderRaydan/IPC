/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #6 (P1)

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

#define MAX_FORECAST_ITM_NUMBER 10
#define MIN_FORECAST_ITM_NUMBER 1

#define MIN_COST 100.00

#define MIN_PRIORITY 1
#define MAX_PRIORITY 3

#define MIN_MONTHLY_INCOME 500.00
#define MAX_MONTHLY_INCOME 400000.00

#include <stdio.h>

int main(void)
{

    double netMonthlyIncome = 0.0;
    int forecastQuantity = 0;

    int itemPriorityValue = 0;
    char financeOptionValue;
    double itemCostValue = 0.0;

    int itemNumbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int itemPriorities[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char financeOptions[10];
    double itemCosts[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    int error = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        error = 0;
        printf("Enter your monthly NET income: $");
        scanf(" %lf", &netMonthlyIncome);

        if (netMonthlyIncome < MIN_MONTHLY_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_MONTHLY_INCOME);
            error = 1;
        }

        else if (netMonthlyIncome > MAX_MONTHLY_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_MONTHLY_INCOME);
            error = 1;
        }

    } while (error);

    do
    {
        error = 0;
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf(" %d", &forecastQuantity);

        if (forecastQuantity < MIN_FORECAST_ITM_NUMBER || forecastQuantity > MAX_FORECAST_ITM_NUMBER)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n\n",
                   MIN_FORECAST_ITM_NUMBER, MAX_FORECAST_ITM_NUMBER);
            error = 1;
        }

    } while (error);

    int i;
    double totalCost = 0.0;

    for (i = 0; i < forecastQuantity; i++)
    {
        // Item Number Array
        itemNumbers[i] = i + 1;

        printf("\nItem-%d Details:\n", i + 1);
        do
        {
            error = 0;
            printf("   Item cost: $");
            scanf(" %lf", &itemCostValue);
            if (itemCostValue < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
                error = 1;
            }
        } while (error);

        // Item Cost Array

        itemCosts[i] = itemCostValue;

        // Calculate total cost
        totalCost += itemCostValue;

        do
        {
            error = 0;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &itemPriorityValue);
            if (itemPriorityValue < MIN_PRIORITY || itemPriorityValue > MAX_PRIORITY)
            {
                printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
                error = 1;
            }
        } while (error);

        itemPriorities[i] = itemPriorityValue;

        do
        {
            error = 0;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOptionValue);
            if (financeOptionValue != 'y' && financeOptionValue != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                error = 1;
            }
        } while (error);

        financeOptions[i] = financeOptionValue;
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < forecastQuantity; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n",
               itemNumbers[i], itemPriorities[i], financeOptions[i], itemCosts[i]);
    }

    printf("\n---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n\n");
    return 0;
}