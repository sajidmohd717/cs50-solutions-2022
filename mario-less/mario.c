#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i < height+1; i++)
    {
        for (int z = height; z > i; z--)
        {
            printf(" ");
        }
        for (int y = 0; y < i; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}