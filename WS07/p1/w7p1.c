/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #7 (P1)

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

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70

#define POSITION_SIZE 5
#define MAX_ARRAY_POSITION_SIZE (MAX_PATH_LENGTH / POSITION_SIZE)

#include <stdio.h>

struct Positions
{
    int bombPositionsArray[POSITION_SIZE];
    int treasurePositionsArray[POSITION_SIZE];
};

struct PlayerConfiguration
{
    int lives;
    char name;
};

struct GameConfiguration
{
    struct Positions positionsArray[MAX_ARRAY_POSITION_SIZE];
    int pathLength;
    int numberOfMovements;
};

int main(void)
{

    struct PlayerConfiguration player;
    struct GameConfiguration gameConfiguration;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    int numLives;
    int flag = 0;

    // Player lives

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.name);
    do
    {
        flag = 0;

        printf("Set the number of lives: ");
        scanf(" %d", &numLives);

        if (numLives < 1 || numLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
            flag = 1;
        }
    } while (flag);

    player.lives = numLives;

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    // Path length

    int pathLength, numberOfMovements;

    do
    {
        flag = 0;

        printf("Set the path length (a multiple of %d between %d-%d): ", POSITION_SIZE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &pathLength);

        if (pathLength < MIN_PATH_LENGTH || pathLength > MAX_PATH_LENGTH || pathLength % POSITION_SIZE != 0)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", POSITION_SIZE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            flag = 1;
        }
    } while (flag);

    gameConfiguration.pathLength = pathLength;

    // Number of movements

    int minMovements = player.lives;
    int maxMovements = gameConfiguration.pathLength * 0.75;

    do
    {
        flag = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &numberOfMovements);

        if (numberOfMovements < minMovements || numberOfMovements > maxMovements)
        {
            printf("    Value must be between %d and %d\n", minMovements, maxMovements);
            flag = 1;
        }
    } while (flag);

    gameConfiguration.numberOfMovements = numberOfMovements;

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", POSITION_SIZE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfiguration.pathLength);

    int i = 0;

    for (i = 0; i < gameConfiguration.pathLength; i++)
    {

        if (i % POSITION_SIZE == 0)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + POSITION_SIZE);
        }

        scanf("%d", &gameConfiguration.positionsArray[i / POSITION_SIZE].bombPositionsArray[i % POSITION_SIZE]);
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", POSITION_SIZE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameConfiguration.pathLength);

    for (i = 0; i < gameConfiguration.pathLength; i++)
    {
        if (i % POSITION_SIZE == 0)
        {
            printf("   Positions [%2d-%2d]: ", i + 1, i + POSITION_SIZE);
        }
        scanf("%d", &gameConfiguration.positionsArray[i / POSITION_SIZE].treasurePositionsArray[i % POSITION_SIZE]);
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.name);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", gameConfiguration.pathLength);
    printf("   Bombs      : ");

    int j = 0;

    for (i = 0; i < gameConfiguration.pathLength / POSITION_SIZE; i++)
    {
        for (j = 0; j < POSITION_SIZE; j++)
        {
            printf("%d", gameConfiguration.positionsArray[i].bombPositionsArray[j]);
        }
    }
    printf("\n");

    printf("   Treasure   : ");

    for (i = 0; i < gameConfiguration.pathLength / POSITION_SIZE; i++)
    {
        for (j = 0; j < POSITION_SIZE; j++)
        {
            printf("%d", gameConfiguration.positionsArray[i].treasurePositionsArray[j]);
        }
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}
