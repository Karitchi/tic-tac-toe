#include <stdio.h>
#include <stdlib.h>

void printBoard(char boxes[3][3])
{
    system("clear");
    printf("         |         |          \n");
    printf("         |         |          \n");
    printf("    %c    |    %c    |    %c    \n", boxes[0][0], boxes[0][1], boxes[0][2]);
    printf("         |         |          \n");
    printf("_________|_________|__________\n");
    printf("         |         |          \n");
    printf("         |         |          \n");
    printf("    %c    |    %c    |    %c    \n", boxes[1][0], boxes[1][1], boxes[1][2]);
    printf("         |         |          \n");
    printf("_________|_________|__________\n");
    printf("         |         |          \n");
    printf("         |         |          \n");
    printf("    %c    |    %c    |    %c    \n", boxes[2][0], boxes[2][1], boxes[2][2]);
    printf("         |         |          \n");
    printf("         |         |          \n");
}

void askPlayerBox(char boxes[3][3], int *player, int *x, int *y)
{
    int chosenBox;
    do
    {
        *player ? printf("Player O, chose a box to play on: ") : printf("Player X, chose a box to play on: ");
        scanf("%d", &chosenBox);
        *x = (chosenBox - 1) % 3;
        *y = (chosenBox - 1) / 3;
    } while (boxes[*y][*x] == 'O' || boxes[*y][*x] == 'X' || chosenBox < 1 || chosenBox > 9);
}

void storePlay(char boxes[3][3], int *player, int *x, int *y)
{
    if (*player)
    {
        boxes[*y][*x] = 'O';
        *player = *player - 1;
    }
    else
    {
        boxes[*y][*x] = 'X';
        *player = *player + 1;
    }
}

int findWinner(char boxes[3][3], int player)
{
    int count = 0;

    // search winner horizontally
    for (int y = 0; y < 3; y++)
    {
        count = 0;

        for (int x = 0; x < 2; x++)
        {
            if (boxes[y][x] == boxes[y][x + 1])
            {
                count++;

                if (count == 2)
                {
                    return 0;
                }
            }
        }
    }

    // search winner vertically
    for (int x = 0; x < 3; x++)
    {
        count = 0;

        for (int y = 0; y < 2; y++)
        {
            if (boxes[y][x] == boxes[y + 1][x])
            {
                count++;

                if (count == 2)
                {
                    return 0;
                }
            }
        }
    }

    // search winner diagonally
    count = 0;

    for (int xy = 0; xy < 2; xy++)
    {

        if (boxes[xy][xy] == boxes[xy + 1][xy + 1])
        {
            count++;

            if (count == 2)
            {
                return 0;
            }
        }
    }

    // search winner diagonally
    count = 0;

    for (int i = 0; i < 2; i++)
    {
        int x = 2;
        int y = 0;

        if (boxes[y][x] == boxes[y + 1][x - 1])
        {
            count++;
            x--;
            y++;

            if (count == 2)
            {
                return 0;
            }
        }
    }
}

int main(void)
{
    int x, y, chosenBox;
    char boxes[3][3] = {"123", "456", "789"};
    int player = 0;
    int isFinished = 9;

    while (isFinished)
    {
        printBoard(boxes);
        askPlayerBox(boxes, &player, &x, &y);
        storePlay(boxes, &player, &x, &y);
        if (isFinished < 6 && findWinner(boxes, player) == 0)
        {
            printBoard(boxes);
            player ? printf("Player X win\n") : printf("Player O win\n");
            return 0;
        }
        isFinished--;
    }
    printBoard(boxes);
    printf("Tie\n");
}