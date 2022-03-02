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
                    printf("winner finded.\n");
                    break;
                }
            }
        }
    }
}

void main(void)
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
        if (isFinished < 6)
        {
            findWinner(boxes);
        }
        isFinished--;
    }
    printBoard(boxes);
}