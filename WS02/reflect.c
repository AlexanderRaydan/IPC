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

       float price1 = 17.96f, price3 = 17.98f;
       double price2 = 17.96, price4 = 17.98;
       printf("********************************\n\n");

       printf("1. 17.96 = %f (as cents:%d)\n", price1, (int)(price1 * 100));
       printf("2. 17.96 = %lf (as cents:%d)\n", price2, (int)(price2 * 100));
       printf("3. 17.98 = %f (as cents:%d)\n", price3, (int)(price3 * 100));
       printf("4. 17.98 = %lf (as cents:%d)\n", price4, (int)(price4 * 100));

       printf("********************************\n\n");

       int money = 7245;
       printf("1. $%.2lf\n", money / 100.0);
       printf("2. $%.2lf\n", money / (double)100);
       printf("3. $%.2lf\n", (double)money / 100);

       printf("********************************\n\n");

       int result, money2 = 7245;
       result = money2 / 100;
       printf("1. $%.2lf\n", money2 / 100);
       printf("2. $%d\n", money2 / 100);
       printf("3. $%.2lf\n", result);
       printf("4. $%d\n", result);

       return 0;
}
