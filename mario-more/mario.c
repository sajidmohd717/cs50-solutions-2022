#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int user_input;
    do
    {
        user_input = get_int("Height: ");
    }
    while(user_input<1 || user_input>8);

    for (int x = user_input; x > 0; x--)
    {
        for (int y = 1; y < x; y++)
        {
            printf(" ");
        }
        for (int y = 0;y<(user_input-x+1);y++)
        {
            printf("#");
        }
        printf("  ");
        for (int y = 0;y<(user_input-x+1);y++)
        {
            printf("#");
        }
        printf("\n");
    }
}