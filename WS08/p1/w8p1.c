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
#define SERVIGING 64

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number)
{

    int value = 0;
    int flag = 0;

    do
    {

        flag = 0;

        scanf("%d", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
            flag = 1;
        }

    } while (flag);

    if (number != NULL)
    {
        *number = value;
    }

    return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number)
{

    double value = 0;
    int flag = 0;

    do
    {
        flag = 0;

        scanf("%lf", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
            flag = 1;
        }

    } while (flag);

    if (number != NULL)
    {
        *number = value;
    }

    return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{

    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", NUMBER_OF_CAT_FOOD);
    printf("NOTE: A 'serving' is %dg\n\n", SERVIGING);
}

// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct CatFoodInfo *product, int productNumber)
{

    printf("Cat Food Product #%d\n", productNumber);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&product->sku);

    printf("PRICE         : $");
    getDoublePositive(&product->price);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&product->weight);

    printf("CALORIES/SERV.: ");
    getIntPositive(&product->caloriesPerServing);

    printf("\n");
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const double *weight, const int caloriesPerServing)
{
    printf("%07d %10.2lf %10.1lf %8d\n",
           sku,
           *price,
           *weight,
           caloriesPerServing);
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

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {
        displayCatFoodData(catFoodArray[i].sku, &catFoodArray[i].price, &catFoodArray[i].weight, catFoodArray[i].caloriesPerServing);
    }
}