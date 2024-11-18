
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

void setup()
{
    gameover = 0;

    x = height / 2;
    y = width / 2;

    do
    {
        fruitx = rand() % height;
    } while (fruitx == 0 || fruitx == height - 1);

    do
    {
        fruity = rand() % width;
    } while (fruity == 0 || fruity == width - 1);

    score = 0;
}

void draw()
{
    int i, j;
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("O");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Score = %d\n", score);
    printf("Press X to quit the game\n");
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
        case 'A':
            flag = 1;
            break;
        case 's':
        case 'S':
            flag = 2;
            break;
        case 'd':
        case 'D':
            flag = 3;
            break;
        case 'w':
        case 'W':
            flag = 4;
            break;
        case 'x':
        case 'X':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    Sleep(100);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1)
        gameover = 1;

    if (x == fruitx && y == fruity)
    {
        score += 10;

        do
        {
            fruitx = rand() % height;
        } while (fruitx == 0 || fruitx == height - 1);

        do
        {
            fruity = rand() % width;
        } while (fruity == 0 || fruity == width - 1);
    }
}

int main()
{

    setup();

    while (!gameover)
    {

        draw();
        input();
        logic();
    }
    return 0;
}
