/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #7 (P2)

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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

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
void openingMessage(const int numberOfProducts)
{

    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numberOfProducts);
    printf("NOTE: A 'serving' is %dg\n\n", SERVIGING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNumber)
{

    struct CatFoodInfo product;

    printf("Cat Food Product #%d\n", productNumber);
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&product.sku);

    printf("PRICE         : $");
    getDoublePositive(&product.price);

    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&product.weight);

    printf("CALORIES/SERV.: ");
    getIntPositive(&product.caloriesPerServing);

    printf("\n");

    return product;
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double *lbs, double *result)
{
    double value = *lbs / LBS_TO_KG;
    if (result != NULL)
    {
        *result = value;
    }

    return value;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double *lbs, int *result)
{

    int value = (int)(convertLbsKg(lbs, NULL) * G_TO_KG);

    if (result != NULL)
    {
        *result = value;
    }

    return value;
}

// 10. convert lbs: kg and g

void convertLbs(const double *lbs, double *kgResult, int *gResult)
{
    if (kgResult != NULL)
    {
        *kgResult = convertLbsKg(lbs, kgResult);
    }

    if (gResult != NULL)
    {
        *gResult = convertLbsG(lbs, gResult);
    }
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingGrams, const int weightGrm, double *serving)
{
    double value = ((double)weightGrm / servingGrams);

    if (serving != NULL)
    {
        *serving = value;
    }

    return value;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double *price, const double *totalService, double *CostPerServing)
{
    double value = *price / *totalService;

    if (CostPerServing != NULL)
    {
        *CostPerServing = value;
    }

    return value;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const int *cal, const double *totalService, double *costPerCal)
{

    double value = (*price / *cal) / *totalService;

    if (costPerCal != NULL)
    {
        *costPerCal = value;
    }

    return value;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo product)
{
    struct ReportData report;
    report.sku = product.sku;
    report.price = product.price;
    report.caloriesPerServing = product.caloriesPerServing;
    report.weightLbs = product.weight;

    convertLbsKg(&product.weight, &report.weightKg);
    convertLbsG(&product.weight, &report.weightGrm);

    calculateServings(SERVIGING, report.weightGrm, &report.totalServing);
    calculateCostPerServing(&product.price, &report.totalServing, &report.costPerServing);
    calculateCostPerCal(&product.price, &product.caloriesPerServing, &report.totalServing, &report.costPerCal);

    return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg\n", SERVIGING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData report, const int isChepest)
{

    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
           report.sku,
           report.price,
           report.weightLbs,
           report.weightKg,
           report.weightGrm,
           report.caloriesPerServing,
           report.totalServing,
           report.costPerServing,
           report.costPerCal);

    if (isChepest)
    {
        printf(" ***");
    }

    printf("\n");
}

// 17. Display the findings (cheapest)

void diplayFinalAnalysis(const struct ReportData product)
{
    printf("\nFinal Analysis");
    printf("\n--------------");
    printf("\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:00%d Price: $%.2lf\n\nHappy shopping!\n", product.sku, product.price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    int i = 0;
    struct CatFoodInfo catFoodArray[NUMBER_OF_CAT_FOOD];
    struct ReportData reportArray[NUMBER_OF_CAT_FOOD];

    int cheapestServiceIndex = 0;
    double cheapestServiceValue = 0;

    openingMessage(NUMBER_OF_CAT_FOOD);

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {
        catFoodArray[i] = getCatFoodInfo(i + 1);
        reportArray[i] = calculateReportData(catFoodArray[i]);
    }

    printf("\n");

    displayCatFoodHeader();

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {
        displayCatFoodData(catFoodArray[i].sku, &catFoodArray[i].price, &catFoodArray[i].weight, catFoodArray[i].caloriesPerServing);
    }

    printf("\n");

    displayReportHeader();

    // Get chepest index
    cheapestServiceValue = reportArray[0].costPerServing;

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {

        if (reportArray[i].costPerServing < cheapestServiceValue)
        {
            cheapestServiceIndex = i;
            cheapestServiceValue = reportArray[i].costPerServing;
        }
    }

    for (i = 0; i < NUMBER_OF_CAT_FOOD; i++)
    {
        displayReportData(reportArray[i], i == cheapestServiceIndex);
    }

    printf("\n");

    diplayFinalAnalysis(reportArray[cheapestServiceIndex]);
}