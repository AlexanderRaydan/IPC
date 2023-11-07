#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n = 42;
	/******************************************************************************/
	/* This creates a pointer to the variable n. Note that & generates the address*/
	/* at which a variable is located in memory.                                  */
	/******************************************************************************/
	int *ptrToN = &n;

	/******************************************************************************/
	/* TODO: Complete the printf below to print out the value of n but use ptrToN */
	/* to access the value of n.                                                  */
	/******************************************************************************/
	printf("n=%d\n", *ptrToN);

	/******************************************************************************/
	/* TODO: Create an expression that will increment the value of n by 1 without */
	/* using the variable n in the expression. Just use ptrToN.                   */
	/******************************************************************************/
	/* expression to increment n without using n in the expression */

	(*ptrToN)++;

	printf("After increment, n=%d\n", n);

	return 0;
}
