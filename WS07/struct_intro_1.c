#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*********************************************************************************
In-Class Exercise
This is an exercise to show how to work with structures.
**********************************************************************************/
#define NAME_MAX 30

/*********************************************************************************/
/* Like arrays, structs gather several variables under one variable. The         */
/* difference is that, with an array, all values are of the same type while with */
/* a struct the values can be of different types. Structs are normally declared  */
/* before all the functions so that they are visible to all functions in the     */
/* program.                                                                      */
/*********************************************************************************/
struct Person
{
	char name[NAME_MAX + 1];
	int age;
};

struct Employee
{
	double salary;
	struct Person personalInfo;
};

int main(void)
{
	struct Person fred = {"Fred Flintstone", 41};
	struct Person mido;

	int manaos[5];
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &manaos[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", manaos[i]);
	}

	mido.age = 35;

	printf(" %d", mido.age);

	/*********************************************************************************/
	/* TODO: Complete the following declaration for Barney Rubble who is 40 years old*/
	/* and earns $47,000 per year                                                    */
	/*********************************************************************************/
	struct Employee barney = {47000.00, {"Barney ", 40}};

	/*********************************************************************************/
	/* TODO: Use the dot notation to complete the printf below to print the data from*/
	/* the variable fred.                                                            */
	/*********************************************************************************/

	printf("%s is %d years old\n", fred.name, fred.age);

	/*********************************************************************************/
	/* TODO: Use the dot notation to complete the printf below to print the data from*/
	/* the variable barney.                                                          */
	/*********************************************************************************/

	printf("%s is %d years old and earns %.2lf per year\n", barney.personalInfo.name, barney.personalInfo.age, barney.salary);

	return 0;
}
