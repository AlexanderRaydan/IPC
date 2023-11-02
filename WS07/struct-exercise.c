#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRING_MAX 40
#define MAX_AUTHORS 20
#define MAX_BOOKS 20

struct Author
{
	char firstName[STRING_MAX + 1];
	char lastName[STRING_MAX + 1];
};

struct Book
{
	char title[STRING_MAX + 1];
	int authorIndex;
};

int main(void)
{
	struct Author authors[MAX_AUTHORS] =
	{
		{{"Charlotte"}, {"Bronte"}},
		{{"George"}, {"Orwell"}},
		{{"Jane"}, {"Austen"}},
		{{"J.R.R."}, {"Tolkien"}}
	};

	struct Book books[MAX_BOOKS] =
	{
		{{"Jane Eyre"}, 0},
		{{"1984"}, 1},
		{{"Pride and Prejudice"}, 2},
		{{"The Hobbit or there and back again"}, 3},
		{{"The Lord of the Rings"}, 3},
		{{"Animal Farm"}, 1},
	};

	int numAuthors = 4, numBooks = 6, action = 0, numRead = 0, badAction = 0;

	// The following is a list of variables you might want to use to fill in the missing code
	int i = 0, j = 0, k = 0;	// loop iterators
	int posn = -1, authPosn = -1, titlePosn = -1, found1 = 0, found2 = 0; // for searching
	char auth[STRING_MAX + 1] = { 0 };	// temporary for author name
	char authFirst[STRING_MAX + 1] = { 0 };	// temporary for author first name
	char authLast[STRING_MAX + 1] = { 0 };	// temporary for author last name
	char title[STRING_MAX + 1] = { 0 };	// temporary for title

	printf("*** Personal Library Manager ***\n");

	do
	{
		do
		{
			printf("Select an action to perform\n");
			printf("1 - show all books and their authors\n");
			printf("2 - show all books by a single author\n");
			printf("3 - show all authors and the books they have written\n");
			printf("4 - add a new book\n");
			printf("4 - remove a book\n");
			printf("0 - exit\n");

			numRead = scanf("%d%*c", &action);
			badAction = numRead != 1 || action < 0 || action > 3;
			if (badAction)
			{
				printf("Enter a number from 0 - 3\n");
			}

		} while (badAction);
		
		switch (action)
		{
		case 0:
			/* exit the program */
			break;
		case 1:	// show all books and their authors
			break;
		case 2:	// show all books by a single author
			break;
		case 3:	// show all authors and the books they have written
			break;
		case 4:	// add a new book
			break;
		case 5:	// remove a book
			break;
		default:
			break;
		}

	} while (action != 0);
	return 0;
}