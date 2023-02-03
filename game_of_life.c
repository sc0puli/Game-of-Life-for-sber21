#include <stdio.h>
#include <stdlib.h>

void output(int **matrix, int W, int L);
int input(int **matrix, int W, int L);
void game_sim(int **matrix, int W, int L);

void welcome()
{
    printf("%s", "This is implementation of Conway's Game of Life made by:\n");
    printf("%s", "blazenig, kynesrha, wolfganl\n");
    printf("%s", "Rules:\n");
    printf("%s", "The universe of the Game of Live is limited 80 units horizontally & 25 units vertically\n");
    printf("%s", "The universe is 2-dim grid of cells, each of which has 2 states: live or dead\n");
    printf("%s", "Every cell interacts with its eight neighbours,\n");
    printf("%s", "which are the cells that are horizontally, vertically, or diagonally adjacent\n");
    printf("%s", "1. Any live cell with two or three live neighbours survives.\n");
    printf("%s", "Any dead cell with three live neighbours becomes a live cell.\n");
    printf("%s", "All other live cells die in the next generation. Similarly, all other dead cells stay dead.\n");
    printf("%s", "To move to next generation hit any key\n");
    printf("%s", "Hit any key to continue!");
}

int main(int argc, char *argv[])
{
    const int LENGTH = 80;
    const int WIDTH = 25;
    int **matrix = malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++) {
        matrix[i] = malloc(LENGTH * sizeof(int));
    }

    welcome();
    char c = getchar();
    system("cls");

    input(matrix, WIDTH, LENGTH);

    while (1)
    {
        game_sim(matrix, WIDTH,LENGTH);
        output(matrix, WIDTH, LENGTH);
        char c = getchar();
        system("cls");
    }

    return 0;
}

void game_sim(int **matrix, int W, int L) //rewrite for cycled field!!
{
    
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < L; j++)
        {
            int neighbours = 0;
            if (i > 0 && matrix[i - 1][j] == 1)
                neighbours++;
            if (i > 0 && j > 0 && matrix[i - 1][j - 1] == 1)
                neighbours++;
            if (i > 0 && j < 20 && matrix[i - 1][j + 1] == 1)
                neighbours++;
            if (i < 20 && matrix[i + 1][j] == 1)
                neighbours++;
            if (j > 0 && matrix[i][j - 1] == 1)
                neighbours++;
            if (j < 20 && matrix[i][j + 1] == 1)
                neighbours++;
            if (j > 0 && i < 20 && matrix[i + 1][j - 1] == 1)
                neighbours++;
            if (i < 20 && j < 20 && matrix[i + 1][j + 1] == 1)
                neighbours++;
            if (matrix[i][j] == 1)
            {
                if (neighbours == 2 || neighbours == 3)
                    matrix[i][j] = 1;
                    else
                    matrix[i][j] = 0;
            }
            else
            {
                if (neighbours == 3)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
    }
}

int input(int **matrix, int W, int L)//how to redirect input from stdin??
{

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return -1;
            }
        }
    }

    return 0;
}

void output(int **matrix, int W, int L)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            switch (matrix[i][j])
            {
            case 1:
            {
                printf("X");
                break;
            }
            case 0:
            {
                printf("O");
                break;
            }
            default:
                break;
            }
            if (j != W - 1)
            {
                printf(" ");
            }
        }
        if (i != L - 1)
        {
            printf("\n");
        }
    }
    return;
}