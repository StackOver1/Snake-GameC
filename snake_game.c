#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char name[20];
int height = 20;
int width = 20;
int x;
int y;
int foodX;
int foodY;
int score;
int gameOver;
int flag;
int tailX[100];
int tailY[100];
int prev1X;
int prev1Y;
int prev2X;
int prev2Y;
int piece;
int a;
int ch;
int level;
int speeds;

void draw()
{
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf(" #");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf(" O");
                }
                else if (i == foodX && j == foodY)
                {
                    printf(" $");
                }
                else
                {
                    ch = 0;
                    for (int k = 0; k < piece; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            ch = 1;
                            printf(" o");
                        }
                    }
                    if (ch == 0)
                    {
                        printf("  ");
                    }
                }
            }
        }
        printf("\n");
    }
}

void setup()
{
    x = height / 2;
    y = width / 2;
start1:
    srand(time(NULL));
    foodX = rand() % 20;
    if (foodX == 0 || foodX == height - 1)
    {
        goto start1;
    }
start2:
    srand(time(NULL));
    foodY = rand() % 20;
    if (foodY <= 1 || foodY == width - 1)
    {
        goto start2;
    }
    score = 0;
    gameOver = 0;
}

void input()
{

    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            flag = 1;
            break;

        case 's':
            flag = 2;
            break;

        case 'a':
            flag = 3;
            break;

        case 'd':
            flag = 4;
            break;

        default:
            gameOver = 1;
            break;
        }
    }
    if (x == foodX && y == foodY)
    {
    start3:
        srand(time(NULL));
        foodX = rand() % 20;
        if (foodX <= 0 || foodX == height - 1)
        {
            goto start3;
        }
    start4:
        srand(time(NULL));
        foodY = rand() % 20;
        if (foodY == 0 || foodY == width - 1)
        {
            goto start4;
        }
        score += 5;
        piece++;
    }
}

void my_logic()
{
    prev1X = tailX[0];
    prev1Y = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    for (int g = 1; g <= piece; g++)
    {
        prev2X = tailX[g];
        prev2Y = tailY[g];
        tailX[g] = prev1X;
        tailY[g] = prev1Y;
        prev1X = prev2X;
        prev1Y = prev2Y;
    }

    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        ;
        break;
    case 4:
        y++;
        break;

    default:
        gameOver = 1;
        break;
    }
}

int main()
{
    printf("Enter your name\n");
    scanf("%s", &name);

    if (score == 0 && score <= 25)
    {
        speeds = 6000;
    }
    else if (score >= 25 && score <= 100)
    {
        speeds = 5000;
    }
    else if (score >= 100 && score <= 250)
    {
        speeds = 4000;
    }
    else if (score >= 250 && score <= 400)
    {
        speeds = 3000;
    }
    else
    {
        speeds = 2000;
    }

    a = 1;
    setup();
    while (a)
    {
        input();
        draw();
        my_logic();

        printf("%s's score = %d\n", &name, score);

        for (int m = 0; m < speeds; m++)
        {
            for (int n = 0; n < speeds; n++)
            {
            }
        }
        if (x == 0 || y == 0 || x == height - 1 || y == width - 1)
        {
            a = 0;
        }
    }

    return 0;
}
