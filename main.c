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

    do
    {
        printf("Player %d, chose a box to play on: ", *player);
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

void main(void)
{
    int x, y, chosenBox;
    char boxes[3][3] = {"123", "456", "789"};
    int player = 0;
    int isFinished = 9;

    while (isFinished)
    {
        printBoard(boxes);
        askPlayerBox(boxes, &player, &chosenBox);
        storePlay(boxes, &player, chosenBox);
        isFinished--;
    }
    printBoard(boxes);
}