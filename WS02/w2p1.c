/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #2

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

int main(void)
{

       // Constans
       const char patSize = 'S';
       const double TAX = 0.13;

       double inputSmallPrice, inputMediumPrice, inputLargePrice = 0.0000;
       int numberOfShirts = 0;

       // Get data from the user
       printf("Set Shirt Prices\n");
       printf("================\n");
       printf("Enter the price for a SMALL shirt: $");
       scanf("%lf", &inputSmallPrice);
       printf("Enter the price for a MEDIUM shirt: $");
       scanf("%lf", &inputMediumPrice);
       printf("Enter the price for a LARGE shirt: $");
       scanf("%lf", &inputLargePrice);

       // Show input information
       printf("\nShirt Store Price List\n");
       printf("======================\n");
       printf("SMALL  : $%.2lf\n", inputSmallPrice);
       printf("MEDIUM : $%.2lf\n", inputMediumPrice);
       printf("LARGE  : $%.2lf\n\n", inputLargePrice);

       // Get number of shirt
       printf("Patty's shirt size is \'%c\'\n", patSize);
       printf("Number of shirts Patty is buying: ");
       scanf("%d", &numberOfShirts);

       int integerSmallPrice = (int)(inputSmallPrice * 100);

       // Calculate subTotal
       int subTotal = integerSmallPrice * numberOfShirts;
       // Calculate Taxes + 0.5 to round up because integer round down for default
       int taxes = (int)((subTotal * TAX) + 0.5);

       int total = subTotal + taxes;

       // Show final result
       printf("\nPatty's shopping cart...\n");
       printf("Contains : %d shirts\n", numberOfShirts);
       printf("Sub-total: $%8.4lf\n", (double)subTotal / 100);
       printf("Taxes    : $%8.4lf\n", (double)taxes / 100);
       printf("Total    : $%8.4lf\n", (double)total / 100);

       return 0;
}