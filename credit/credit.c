#include <cs50.h>
#include <stdio.h>

bool check_sum(long num);

int main(void)
{
    int digits = 0, single_digit = 0, two_digit = 0;
    bool checksum;
    long user_input = get_long("Number: ");
    checksum = check_sum(user_input);
    if (checksum == false)
        return 0;
    while(user_input > 0)
    {
        if (user_input < 10)
        {
            single_digit = user_input;
        }
        if (user_input > 10 && user_input < 100)
        {
            two_digit = user_input;
        }
        user_input /= 10;
        digits ++;
    }
    printf("digits: %i\n", digits);
    printf("single_digit: %i\n", single_digit);
    printf("two_digit: %i\n", two_digit);
    if ((two_digit == 34 || two_digit == 37) && digits == 15)
    {
        printf("AMEX\n");
        return 0;
    }
    else if ((two_digit == 51 || two_digit == 52 || two_digit == 53 || two_digit == 54 || two_digit == 55) && digits == 16)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if (single_digit == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
        return 0;
    }
    else
        printf("INVALID\n");
    return 0;
}

bool check_sum(long num)
{
    int total = 0, buffer = 0;
    bool var = true;
    while(num > 0)
    {
        if (var == true)
        {
            total += num % 10;
            num /= 10;
            var = false;
        }
        else
        {
            buffer = num % 10;
            buffer *= 2;
            if (buffer >= 10)
            {
                total += buffer % 10;
                total += buffer / 10;
            }
            else
            {
                total += buffer;
            }
            var = true;
            num /= 10;
        }
    }
    printf("total: %i\n", total);
    if (total % 10 == 0)
        return true;
    printf("INVALID\n");
    return false;
}