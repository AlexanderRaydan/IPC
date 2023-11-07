#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 10

/*************************************************************************************
* In-Class Exercise
* This is an exercise to demonstrate how to create functions.
**************************************************************************************/

/*************************************************************************************/
/* A function contains code which can be called multiple times. Each time it is      */
/* called, we can change the parameters passed to it to get it to do different       */
/* calculations.                                                                     */
/*************************************************************************************/

int stringLength(const char str[])
{
	int result = 0;
	for (result = 0; str[result] != '\0'; result++);
	return result;
}

/*************************************************************************************/
/*The following function is void, because it does not compute a value to return but  */
/* has a side-effect where it prints the string s centered in the indicated fill     */
/* character. For example, if you called centerText("Dog", 10, '*') it should print  */
/* ***Dog****                                                                        */
/* TODO: Complete the code below to use the stringLength function to calculate the   */
/* required spacing for the text and print it out.                                   */
/*************************************************************************************/
void centerText(const char s[], int desiredWidth, char fillChar)
{
	int i = 0, stringWidth = 0, fillWidth = 0;

	stringWidth = /* calculate length of s */;
	fillWidth = /* calculate width of fill string on each end */;

	for (i = 0; /* How far */; i++)
	{
		printf("%c", fillChar);
	}
	printf("%s", s);
	for (i = 0; i < /* when do I stop */; i++)
	{
		printf("%c", fillChar);
	}
	/* we do not print a newline here because the caller might not want one */
}

int main(void)
{
	char filler = '-';
	char str[] = "Tiger";

	/*********************************************************************************/
	/* TODO: Call the function to print str in field 10 chars wide filled with dashes*/
	/*********************************************************************************/

	centerText(/* arguments go here */);
	printf("\n");

	/*********************************************************************************/
	/* TODO: Call the function again to print "1,000,000" in field 20 chars wide     */
	/* filled with dollar signs.                                                     */
	/*********************************************************************************/

	return 0;
}

