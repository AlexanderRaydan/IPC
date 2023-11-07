/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #8 (P1)

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
#define NUMBER_OF_CAT_FOOD 3
#define NUMBER_TEST_ARRAY_SIZE 3

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number)
{
    int *p;
    int i = 0;

    if (number != NULL)
    {
        p = number;
    }

    int numbers[] = {0, 0, 0};

    scanf("%d %d %d", &numbers[0], &numbers[1], &numbers[2]);

    for (i = 0; i < NUMBER_TEST_ARRAY_SIZE; i++)
    {
        if (numbers[i] > 0)
        {
            *p = numbers[i];
            return *p;
        }
        printf("ERROR: Enter a positive value: ");
    }

    return *p;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number)
{

    double *p;
    int i = 0;

    if (number != NULL)
    {
        p = number;
    }

    double numbers[] = {0.0, 0.0, 0.0};

    scanf("%lf %lf %lf", &numbers[0], &numbers[1], &numbers[2]);

    for (i = 0; i < NUMBER_TEST_ARRAY_SIZE; i++)
    {
        if (numbers[i] > 0)
        {
            *p = numbers[i];
            return *p;
        }
        printf("ERROR: Enter a positive value: ");
    }

    return *p;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{

    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", NUMBER_OF_CAT_FOOD);
    printf("NOTE: A 'serving' is 64g\n");
}

// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct CatFoodInfo *product, int productNumber)
{

    int flag = 0;
    int error = 0;

    printf("Cat Food Product #%d\n", productNumber);
    printf("--------------------\n");

    do
    {
        flag = 0;

        if (!error)
        {
            printf("SKUOR         : ");
        }
        else
        {
            printf("ERROR: Enter a positive value: ");
        }

        scanf("%d", &product->sku);

        if (product->sku <= 0)
        {
            flag = 1;
            error = 1;
        }

    } while (flag);
    error = 0;

    // Validate and prompt for price
    do
    {
        flag = 0;
        if (!error)
        {
            printf("PRICE ($)     : $");
        }
        else
        {
            printf("ERROR: Enter a positive value: $");
        }
        scanf("%lf", &product->price);

        if (product->price <= 0)
        {
            flag = 1;
            error = 1;
        }

    } while (flag);
    error = 0;

    // Validate and prompt for weight
    do
    {
        flag = 0;
        if (!error)
        {
            printf("WEIGHT (LBS)  : ");
        }
        else
        {
            printf("ERROR: Enter a positive value: ");
        }
        scanf("%lf", &product->weight);

        if (product->weight <= 0)
        {
            flag = 1;
            error = 1;
        }

    } while (flag);
    error = 0;

    // Validate and prompt for calories per serving
    do
    {
        flag = 0;
        if (!error)
        {
            printf("CALORIES/SERV.: ");
        }
        else
        {
            printf("ERROR: Enter a positive value: ");
        }
        scanf("%d", &product->caloriesPerServing);

        if (product->caloriesPerServing <= 0)
        {
            flag = 1;
            error = 1;
        }

    } while (flag);

    printf("\n\n");
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo catFoodArray[])
{
    int i = 0;

    for (; i < NUMBER_OF_CAT_FOOD; i++)
    {
        printf("%07d %10.2lf %10.1lf %8d\n",
               catFoodArray[i].sku,
               catFoodArray[i].price,
               catFoodArray[i].weight,
               catFoodArray[i].caloriesPerServing);
    }
}

// 7. Logic entry point
void start(void)
{
    int i = 0;
    struct CatFoodInfo catFoodArray[NUMBER_OF_CAT_FOOD];

    openingMessage();

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {
        getCatFoodInfo(&catFoodArray[i], (i + 1));
    }

    displayCatFoodHeader();
    displayCatFoodData(catFoodArray);
}