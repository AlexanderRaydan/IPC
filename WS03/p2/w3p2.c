/*/////////////////////////////////////////////////////////////////////////

                          Workshop - #3 (P2)


Full Name  : Alexander David Raydan Gonzalez
Student ID#: 124348236
Email      : adraydan-gonzalez@myseneca.ca
Section    : ZBB

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{

       const double GRAMS_IN_LBS = 453.5924;

       printf("Take a Break - Coffee Shop\n");
       printf("==========================\n\n");

       // COFFEE-1
       printf("Enter the coffee product information being sold today...\n\n");
       printf("COFFEE-1...\n");

       char coffee1Type, coffe1CreamChoice;
       int coffee1BagWeight;

       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee1Type);
       printf("Bag weight (g): ");
       scanf("%d", &coffee1BagWeight);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &coffe1CreamChoice);

       // COFFEE-2
       printf("\nCOFFEE-2...\n");

       char coffee2Type, coffe2CreamChoice;
       int coffee2BagWeight;

       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee2Type);
       printf("Bag weight (g): ");
       scanf("%d", &coffee2BagWeight);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &coffe2CreamChoice);

       // COFFEE-3
       printf("\nCOFFEE-3...\n");

       char coffee3Type, coffe3CreamChoice;
       int coffee3BagWeight;

       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee3Type);
       printf("Bag weight (g): ");
       scanf("%d", &coffee3BagWeight);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &coffe3CreamChoice);

       // Print coffee data
       printf("\n---+------------------------+---------------+-------+\n");
       printf("   |    Coffee              |   Packaged    | Best  |\n");
       printf("   |     Type               |  Bag Weight   | Served|\n");
       printf("   +------------------------+---------------+ With  |\n");
       printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
       printf("---+------------------------+---------------+-------|\n");

       printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
              ((coffee1Type == 'L' || coffee1Type == 'l')),
              ((coffee1Type == 'M' || coffee1Type == 'm')),
              ((coffee1Type == 'R' || coffee1Type == 'r')),
              coffee1BagWeight,
              coffee1BagWeight / GRAMS_IN_LBS,
              ((coffe1CreamChoice == 'Y' || coffe1CreamChoice == 'y')));
       printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
              ((coffee2Type == 'L' || coffee2Type == 'l')),
              ((coffee2Type == 'M' || coffee2Type == 'm')),
              ((coffee2Type == 'R' || coffee2Type == 'r')),
              coffee2BagWeight,
              coffee2BagWeight / GRAMS_IN_LBS,
              ((coffe2CreamChoice == 'Y' || coffe2CreamChoice == 'y')));

       printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
              ((coffee3Type == 'L' || coffee3Type == 'l')),
              ((coffee3Type == 'M' || coffee3Type == 'm')),
              ((coffee3Type == 'R' || coffee3Type == 'r')),
              coffee3BagWeight,
              coffee3BagWeight / GRAMS_IN_LBS,
              ((coffe3CreamChoice == 'Y' || coffe3CreamChoice == 'y')));

       // User Preferences
       printf("Enter how you like your coffee...\n\n");
       char strength;
       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &strength);

       char creamPreference;
       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &creamPreference);

       int servingsPerDay;
       printf("Typical number of daily servings: ");
       scanf("%d", &servingsPerDay);

       // aviable table one
       printf("\nThe below table shows how your preferences align to the available products:\n\n");
       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");

       printf(" 1|       %d         |      %d      |   %d   |\n",
              (((strength == 'L' || strength == 'l') && (coffee1Type == 'L' || coffee1Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee1Type == 'M' || coffee1Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee1Type == 'R' || coffee1Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee1BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee1BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee1BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe1CreamChoice == 'Y' || coffe1CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe1CreamChoice == 'N' || coffe1CreamChoice == 'n'))));

       printf(" 2|       %d         |      %d      |   %d   |\n",
              (((strength == 'L' || strength == 'l') && (coffee2Type == 'L' || coffee2Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee2Type == 'M' || coffee2Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee2Type == 'R' || coffee2Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee2BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee2BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee2BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe2CreamChoice == 'Y' || coffe2CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe2CreamChoice == 'N' || coffe2CreamChoice == 'n'))));

       printf(" 3|       %d         |      %d      |   %d   |\n\n",
              (((strength == 'L' || strength == 'l') && (coffee3Type == 'L' || coffee3Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee3Type == 'M' || coffee3Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee3Type == 'R' || coffee3Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee3BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee3BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee3BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe3CreamChoice == 'Y' || coffe3CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe3CreamChoice == 'N' || coffe3CreamChoice == 'n'))));

       // aviable table two

       // User Preferences
       printf("Enter how you like your coffee...\n\n");
       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &strength);

       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &creamPreference);

       printf("Typical number of daily servings: ");
       scanf("%d", &servingsPerDay);

       printf("\nThe below table shows how your preferences align to the available products:\n\n");
       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");

       printf(" 1|       %d         |      %d      |   %d   |\n",
              (((strength == 'L' || strength == 'l') && (coffee1Type == 'L' || coffee1Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee1Type == 'M' || coffee1Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee1Type == 'R' || coffee1Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee1BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee1BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee1BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe1CreamChoice == 'Y' || coffe1CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe1CreamChoice == 'N' || coffe1CreamChoice == 'n'))));

       printf(" 2|       %d         |      %d      |   %d   |\n",
              (((strength == 'L' || strength == 'l') && (coffee2Type == 'L' || coffee2Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee2Type == 'M' || coffee2Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee2Type == 'R' || coffee2Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee2BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee2BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee2BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe2CreamChoice == 'Y' || coffe2CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe2CreamChoice == 'N' || coffe2CreamChoice == 'n'))));

       printf(" 3|       %d         |      %d      |   %d   |\n\n",
              (((strength == 'L' || strength == 'l') && (coffee3Type == 'L' || coffee3Type == 'l')) ||
               ((strength == 'M' || strength == 'm') && (coffee3Type == 'M' || coffee3Type == 'm')) ||
               ((strength == 'R' || strength == 'r') && (coffee3Type == 'R' || coffee3Type == 'r'))),

              (((servingsPerDay >= 1 && servingsPerDay <= 4) && coffee3BagWeight == 250) ||
               ((servingsPerDay >= 5 && servingsPerDay <= 9) && coffee3BagWeight == 500) ||
               ((servingsPerDay >= 10) && coffee3BagWeight == 1000)),

              (((creamPreference == 'Y' || creamPreference == 'y') && (coffe3CreamChoice == 'Y' || coffe3CreamChoice == 'y')) ||
               ((creamPreference == 'N' || creamPreference == 'n') && (coffe3CreamChoice == 'N' || coffe3CreamChoice == 'n'))));

       printf("Hope you found a product that suits your likes!\n");

       return 0;
}
