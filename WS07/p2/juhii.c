#include <stdio.h>

#define MAXPATHLENGTH 70
#define MINPATHLENGTH 10
#define SETS 5

struct PlayerInfo
{
    int lives;
    char symbol;
    int numberOfTreasure;
    int position[MAXPATHLENGTH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bomb[MAXPATHLENGTH];
    int treasure[MAXPATHLENGTH];
};

int main(void)
{
    struct PlayerInfo representPlayer;
    struct GameInfo historyGame;
    int flag;
    int i;
    int j;
    int treasures = 0;
    int nextMoves = 0;
    int move = -1;
    char location[MAXPATHLENGTH];

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &representPlayer.symbol);

    do
    {
        flag = 0;
        printf("Set the number of lives: ");
        scanf(" %d", &representPlayer.lives);

        if (representPlayer.lives < 1 || representPlayer.lives > 10)
        {
            printf("     Must be between 1 and 10!\n");
            flag = 1;
        }
        else
        {
            printf("Player configuration set-up is complete\n\n");
        }
    } while (flag == 1);

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        flag = 0;
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &historyGame.pathLength);

        if (historyGame.pathLength < MINPATHLENGTH || historyGame.pathLength > MAXPATHLENGTH || historyGame.pathLength % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
            flag = 1;
        }
    } while (flag == 1);

    do
    {
        flag = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &historyGame.moves);

        if (historyGame.moves < 3 || historyGame.moves > 15)
        {
            printf("    Value must be between 3 and 15\n");
            flag = 1;
        }
    } while (flag == 1);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

    for (i = 0; i < historyGame.pathLength; i += SETS)
    {
        printf("   Positions [%2d-%2d]:", i + 1, i + 5);

        for (j = i; j < i + 5; j++)
        {
            scanf(" %d", &historyGame.bomb[j]);
        }
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < historyGame.pathLength; i += SETS)
    {
        printf("   Positions [%2d-%2d]:", i + 1, i + 5);

        for (j = i; j < i + 5; j++)
        {
            scanf(" %d", &historyGame.treasure[j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", representPlayer.symbol);
    printf("   Lives      : %d\n", representPlayer.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", historyGame.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        printf("%d", historyGame.bomb[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        printf("%d", historyGame.treasure[i]);
    }
    printf("\n");
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    for (i = 0; i < historyGame.pathLength; i++)
    {
        location[i] = '-';
    }
    printf("\n");
    while (representPlayer.lives > 0 && historyGame.moves > 0)
    {
        if (move != -1)
        {
            printf("\n  ");
            for (i = 0; i < historyGame.pathLength; i++)
            {
                if (i != nextMoves)
                {
                    printf(" ");
                }
                else
                {
                    printf("%c", representPlayer.symbol);
                }
            }
        }
        else
        {
            move = 0;
        }

        printf("\n  ");
        for (i = 0; i < historyGame.pathLength; i++)
        {
            printf("%c", location[i]);
        }
        printf("\n  ");
        for (i = 0; i < historyGame.pathLength; i++)
        {
            if ((i + 1) % 10 != 0)
            {
                printf("|");
            }
            else
            {
                printf("%d", (i / 10) + 1);
            }
        }
        printf("\n  ");
        for (i = 0; i < historyGame.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", representPlayer.lives,
               treasures, historyGame.moves);
        printf("+---------------------------------------------------+\n");

        do
        {
            printf("Next Move [1-%d]: ", historyGame.pathLength);
            scanf(" %d", &nextMoves);
            if (nextMoves < 1 || nextMoves > 20)
            {
                printf("  Out of Range!!!\n");
            }
        } while ((nextMoves < 1 || nextMoves > 20));

        nextMoves--;
        if (location[nextMoves] != '-')
        {
            printf("\n===============> Dope! You've been here before!\n");
        }
        else if (historyGame.bomb[nextMoves] == 1 && historyGame.treasure[nextMoves] == 1)
        {
            location[nextMoves] = '&';
            treasures++;
            representPlayer.lives--;
            printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            historyGame.moves -= 1;
        }
        else if (historyGame.bomb[nextMoves] == 1)
        {
            location[nextMoves] = '!';
            representPlayer.lives--;
            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
            historyGame.moves -= 1;
        }
        else if (historyGame.treasure[nextMoves])
        {
            location[nextMoves] = '$';
            treasures++;
            printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
            historyGame.moves -= 1;
        }
        else if (historyGame.bomb[nextMoves] == 0 && historyGame.treasure[nextMoves] == 0)
        {
            location[nextMoves] = '.';
            printf("\n===============> [.] ...Nothing found here... [.]\n");
            historyGame.moves -= 1;
        }
    }
    printf("No more LIVES remaining!\n\n");

    printf("\n  ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        if (i != nextMoves)
        {
            printf(" ");
        }
        else
        {
            printf("%c", representPlayer.symbol);
        }
    }

    printf("\n  ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        printf("%c", location[i]);
    }
    printf("\n  ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        if ((i + 1) % 10 != 0)
        {
            printf("|");
        }
        else
        {
            printf("%d", (i / 10) + 1);
        }
    }
    printf("\n  ");
    for (i = 0; i < historyGame.pathLength; i++)
    {
        printf("%d", (i + 1) % 10);
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", representPlayer.lives,
           treasures, historyGame.moves);
    printf("+---------------------------------------------------+\n");

    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n\n");

    return 0;
}