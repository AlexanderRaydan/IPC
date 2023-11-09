#include <stdio.h>

void printChars(char ch, int howMany)
{
	int i;

	for (i = 0; i < howMany; i++)
	{
		printf("%c", ch);
	}
	printf("\n");
}

int positiveNumber(int number)
// number = 5
{
	printf("number = %d\n", number);
	printf("operation %d > 0 = %d\n", number, number > 0);

	return number > 0;
}

int positiveDoubleNumber(double number)
{
	printf("number = %lf\n", number);
	printf("operation %d > 0 = %d\n", number, number > 0);

	return number > 0;
}

int printMidoName()
{
	printf("Your name is Midori\n");
}

int main(void)
{
	// printChars('-', 40);
	// printf("An example of a simple function\n");
	// printChars('*', 40);

	int result = positiveNumber(5);
	printf("result: %d\n\n", result);

	result = positiveNumber(-1);
	printf("result: %d\n\n", result);

	result = positiveNumber(10);
	printf("result: %d\n\n", result);

	printMidoName();

	return 0;
}