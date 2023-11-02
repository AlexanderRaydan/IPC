#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 10

/*************************************************************************************
* In-Class Exercise
* This is an exercise to demonstrate how to use structs to replace parallel arrays.
**************************************************************************************/

/*************************************************************************************/
/* A struct can be used to respresent the same information as parallel arrays. The   */
/* struct contains the same information as 1 column from the parallel arrays. We can */
/* the make an array of these structs so that it contains the same information as the*/
/* parallel arrays.                                                                  */
/*************************************************************************************/
struct ProductInfo
{
	int productID;
	double price;
};

int main(void)
{
	/*********************************************************************************/
	/* Parallel arrays line up information that is related in the same position in   */
	/* two or more arrays. The following arrays contain product identifiers and      */
	/* corresponding prices.                                                         */
	/*********************************************************************************/
	
	int		prductID[MAX_PRODUCTS]		= { 97,		89,		48,		24 };
	double	productPrice[MAX_PRODUCTS]	= { 2.98,	7.45,	6.50,	7.99 };
	int numProducts = 4;

	/*********************************************************************************/
	/* TODO: Complete the code below to initialize the array of structs with the     */
	/* same data that is stored in the parallel arrays above.                        */
	/*********************************************************************************/

	struct ProductInfo info[MAX_PRODUCTS] = {/* initial values copied from parallel arrays */ };
	int i = 0, posn = -1, id = 0;

	/*********************************************************************************/
	/* TODO: Complete the code below to find the price of the product requested.     */
	/*********************************************************************************/
	printf("Enter the product to find: ");
	scanf("%d", &id);
	for (i = 0; i < numProducts; i++)
	{
		if (/* expression to match the id we are looking for */)
		{
			posn = i;
		}
	}
	if (/* posn is valid to have found the id */)
	{
		printf("The price of %d is %.2lf\n", /* id */, /* price*/);
	}
	else
	{
		printf("%d was not found\n", id);
	}

	return 0;
}

