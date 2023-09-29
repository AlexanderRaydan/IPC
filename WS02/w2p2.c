/*
////////////////////////////////////////////////////////////////////////////

                             Workshop - #2 (P2)

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

       int x = 10;
       int y = 10;

       x = x + 20;

       y += 20;
       // y = y + 20;

       printf(" x : %d \n", x);
       printf(" y : %d \n", y);

       // Constans
       const double TAX = 0.13;
       const char pattySize = 'S', sallySize = 'M', tomSize = 'L';

       double inputSmallPrice, inputMediumPrice, inputLargePrice = 0.0000;
       int pattyNumberOfShirts, tomNumberOfShirts, sallyNumberOfShirts = 0;

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

       ////////////////////////////////////////////////////////////////

       // Get number of shirt
       printf("Patty's shirt size is \'%c\'\n", pattySize);
       printf("Number of shirts Patty is buying: ");
       scanf("%d", &pattyNumberOfShirts);

       printf("\nTommy's shirt size is \'%c\'\n", tomSize);
       printf("Number of shirts Tommy is buying: ");
       scanf("%d", &tomNumberOfShirts);

       printf("\nSally's shirt size is \'%c\'\n", sallySize);
       printf("Number of shirts Sally is buying: ");
       scanf("%d", &sallyNumberOfShirts);

       // calculating sub total tax and total

       int integerSmallPrice = (int)(inputSmallPrice);
       int integerMediumPrice = (int)(inputMediumPrice * 100);
       int integerLargePrice = (int)(inputLargePrice * 100);

       // Patty
       int pattySubTotal = integerSmallPrice * pattyNumberOfShirts;
       int pattyTaxes = (int)((pattySubTotal * TAX) + 0.5);
       int pattyTotal = pattySubTotal + pattyTaxes;

       // 5 == 5.00

       // Sally
       int sallySubTotal = integerMediumPrice * sallyNumberOfShirts;
       int sallyTaxes = (int)((sallySubTotal * TAX) + 0.5);
       int sallyTotal = sallySubTotal + sallyTaxes;

       // Tommy
       int tomSubTotal = integerLargePrice * tomNumberOfShirts;
       int tomTaxes = (int)((tomSubTotal * TAX) + 0.5);
       int tomTotal = tomSubTotal + tomTaxes;

       // calculate totals

       int subTotalAmout = pattySubTotal + sallySubTotal + tomSubTotal;
       int totalTaxesAmount = pattyTaxes + sallyTaxes + tomTaxes;
       int totalAmount = pattyTotal + sallyTotal + tomTotal;

       // show details

       printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
       printf("-------- ---- ----- --- --------- --------- ---------\n");
       printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
              pattySize,
              inputSmallPrice,
              pattyNumberOfShirts,
              ((double)pattySubTotal / 100),
              ((double)pattyTaxes / 100),
              ((double)pattyTotal / 100));

       printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
              sallySize,
              inputMediumPrice,
              sallyNumberOfShirts,
              ((double)sallySubTotal / 100),
              ((double)sallyTaxes / 100),
              ((double)sallyTotal / 100));

       printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
              tomSize,
              inputLargePrice,
              tomNumberOfShirts,
              ((double)tomSubTotal / 100),
              ((double)tomTaxes / 100),
              ((double)tomTotal / 100));
       printf("-------- ---- ----- --- --------- --------- ---------\n");

       printf("%33.4lf %9.4lf %9.4lf\n\n",
              ((double)subTotalAmout / 100),
              ((double)totalTaxesAmount / 100),
              ((double)(totalAmount / 100)));

       printf("Daily retail sales represented by coins\n");
       printf("=======================================\n\n");

       // calculate coins subtotal

       int totalCoinsBalance = subTotalAmout; // Convert to cents

       // show coins
       printf("Sales EXCLUDING tax\n");
       printf("Coin     Qty   Balance\n");
       printf("-------- --- ---------\n");

       printf("%22.4lf\n", ((double)subTotalAmout / 100));
       int toonies = totalCoinsBalance / 200;

       totalCoinsBalance %= 200;
       // totalCoinsBalance = totalCoinsBalance % 200;

       printf("Toonies  %3d %9.4lf\n", toonies, ((double)totalCoinsBalance / 100));
       int loonies = totalCoinsBalance / 100;
       totalCoinsBalance %= 100;
       printf("Loonies  %3d %9.4lf\n", loonies, ((double)totalCoinsBalance / 100));

       int quarters = totalCoinsBalance / 25;
       totalCoinsBalance %= 25;
       printf("Quarters %3d %9.4lf\n", quarters, ((double)totalCoinsBalance / 100));

       int dimes = totalCoinsBalance / 10;
       totalCoinsBalance %= 10;
       printf("Dimes    %3d %9.4lf\n", dimes, ((double)totalCoinsBalance / 100));

       int nickels = totalCoinsBalance / 5;
       totalCoinsBalance %= 5;
       printf("Nickels  %3d %9.4lf\n", nickels, ((double)totalCoinsBalance / 100));

       int pennies = totalCoinsBalance;
       totalCoinsBalance %= 5;
       printf("Pennies  %3d %9.4lf\n", pennies, 0.0000);

       // calculate average

       int numberOfShirts = pattyNumberOfShirts + sallyNumberOfShirts + tomNumberOfShirts;
       double subTotalAverage = ((double)subTotalAmout / 100) / (numberOfShirts);

       printf("\nAverage cost/shirt: $%.4lf\n\n", subTotalAverage);

       // calculate coins total amount

       totalCoinsBalance = totalAmount; // Convert to cents

       // show coins
       printf("Sales INCLUDING tax\n");
       printf("Coin     Qty   Balance\n");
       printf("-------- --- ---------\n");

       printf("%22.4lf\n", ((double)totalCoinsBalance / 100));
       toonies = totalCoinsBalance / 200;
       totalCoinsBalance %= 200;
       printf("Toonies  %3d %9.4lf\n", toonies, ((double)totalCoinsBalance / 100));
       loonies = totalCoinsBalance / 100;
       totalCoinsBalance %= 100;
       printf("Loonies  %3d %9.4lf\n", loonies, ((double)totalCoinsBalance / 100));

       quarters = totalCoinsBalance / 25;
       totalCoinsBalance %= 25;
       printf("Quarters %3d %9.4lf\n", quarters, ((double)totalCoinsBalance / 100));

       dimes = totalCoinsBalance / 10;
       totalCoinsBalance %= 10;
       printf("Dimes    %3d %9.4lf\n", dimes, ((double)totalCoinsBalance / 100));

       nickels = totalCoinsBalance / 5;
       totalCoinsBalance %= 5;
       printf("Nickels  %3d %9.4lf\n", nickels, ((double)totalCoinsBalance / 100));

       pennies = totalCoinsBalance;
       totalCoinsBalance %= 5;
       printf("Pennies  %3d %9.4lf\n", pennies, 0.0000);

       // calculate average
       double totalAverage = ((double)totalAmount / 100) / (numberOfShirts);

       printf("\nAverage cost/shirt: $%.4lf\n", totalAverage);

       return 0;
}
