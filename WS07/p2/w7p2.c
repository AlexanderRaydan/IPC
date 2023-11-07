/*
////////////////////////////////////////////////////////////////////////////

                          Workshop - #7 (P2)

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

#define MIN_MOVE 1

#define POSITION_SIZE 5

#include <stdio.h>

struct PlayerConfiguration
{
    int lives;
    int treasuresFound;
    int movesRemaining;
    char name;
    char playerHistory[MAX_PATH_LENGTH + 1];
};

struct GameConfiguration
{
    int pathLength;
    int numberOfMovements;
    int bombPositionsArray[MAX_PATH_LENGTH];
    int treasurePositionsArray[MAX_PATH_LENGTH];
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

        scanf("%d", &gameConfiguration.bombPositionsArray[i]);
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
        scanf("%d", &gameConfiguration.treasurePositionsArray[i]);
        player.playerHistory[i] = '-';
    }

    player.playerHistory[MAX_PATH_LENGTH] = '\0';

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

    for (i = 0; i < gameConfiguration.pathLength; i++)
    {
        printf("%d", gameConfiguration.bombPositionsArray[i]);
    }

    printf("\n");

    printf("   Treasure   : ");

    for (i = 0; i < gameConfiguration.pathLength; i++)
    {
        printf("%d", gameConfiguration.treasurePositionsArray[i]);
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    player.treasuresFound = 0;
    player.movesRemaining = gameConfiguration.numberOfMovements;

    int currentPosition = 0;
    int nextMove = 0;
    int caseCounter = 1;
    int firstMove = 1;

    while (player.lives > 0 && player.movesRemaining > 0)
    {

        // show current position

        if (!firstMove)
        {
            printf("  ");
            for (i = 1; i <= nextMove; i++)
            {
                if (i == nextMove)
                {
                    printf("%c", player.name);
                }
                else
                {
                    printf(" ");
                }
            }
            firstMove = 0;
        }

        printf("\n");
        // show player history
        printf("  ");
        for (i = 0; i < gameConfiguration.pathLength; i++)
        {
            printf("%c", player.playerHistory[i]);
        }
        printf("\n");

        caseCounter = 1;
        firstMove = 0;
        printf("  ");

        for (i = 0; i < gameConfiguration.pathLength; i++)
        {

            if ((i + 1) % 10 == 0)
            {

                printf("%d", caseCounter);
                caseCounter++;
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        caseCounter = 0;

        printf("  ");
        for (i = 0; i < gameConfiguration.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }

        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasuresFound, player.movesRemaining);
        printf("+---------------------------------------------------+\n");

        do
        {
            flag = 0;
            printf("Next Move [%d-%d]: ", MIN_MOVE, gameConfiguration.pathLength);
            scanf("%d", &nextMove);

            if (nextMove < MIN_MOVE || nextMove > gameConfiguration.pathLength)
            {
                printf("  Out of Range!!!\n");
                flag = 1;
                continue;
            }

            currentPosition = nextMove - 1;

        } while (flag);

        printf("\n");

        if (player.playerHistory[currentPosition] != '-')
        {
            printf("===============> Dope! You've been here before!\n\n");
            continue;
        }

        player.movesRemaining--;

        if (gameConfiguration.bombPositionsArray[currentPosition] == 1 && gameConfiguration.treasurePositionsArray[currentPosition] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.playerHistory[currentPosition] = '&';
            player.treasuresFound++;
            player.lives--;
        }
        else if (gameConfiguration.bombPositionsArray[currentPosition] == 1)

        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.lives--;
            player.playerHistory[currentPosition] = '!';
        }
        else if (gameConfiguration.treasurePositionsArray[currentPosition] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.treasuresFound++;
            player.playerHistory[currentPosition] = '$';
        }
        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n");
            player.playerHistory[currentPosition] = '.';
        }

        printf("\n");
    }

    printf("No more LIVES remaining!\n");
    printf("\n");

    // show current position
    printf("  ");
    for (i = 1; i <= nextMove; i++)
    {
        if (i == nextMove)
        {
            printf("%c", player.name);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
    // show player history
    printf("  ");
    for (i = 0; i < gameConfiguration.pathLength; i++)
    {
        printf("%c", player.playerHistory[i]);
    }
    printf("\n");

    caseCounter = 1;
    firstMove = 0;
    printf("  ");

    for (i = 0; i < gameConfiguration.pathLength; i++)
    {

        if ((i + 1) % 10 == 0)
        {

            printf("%d", caseCounter);
            caseCounter++;
        }
        else
        {
            printf("|");
        }
    }
    printf("\n");

    caseCounter = 0;

    printf("  ");
    for (i = 0; i < gameConfiguration.pathLength; i++)
    {
        printf("%d", (i + 1) % 10);
    }

    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasuresFound, player.movesRemaining);
    printf("+---------------------------------------------------+\n");

    printf("\n");

    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}
