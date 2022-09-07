// 5th draft

#include <cs50.h>
#include <stdio.h>

int get_counter(long n);
int get_suml(long n);

int main(void)
{
// prompts for credit card no
    long n = get_long("Credit Card Number: ");
    // accepts only numbers, rejects others
    if (n < 1000000000000 || n > 10000000000000000)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (n >= 10000000000000 && n < 100000000000000)
    {
        printf("INVALID\n");
        return 0;
    }

// Luhn's algorithm
    int suml = get_suml(n);
    if (suml != 0)  // Check last digit of sum is not 0, then invalid credit number.
    {
        printf("INVALID\n");
        return 0;
    }

// Check credit cards
    // start digits
    int c16 = n / 100000000000000;
    int c15 = n / 10000000000000;
    int c13 = n / 1000000000000;

    // check Amex
    if (counter == 15 && (c15 == 34 || c15 == 37))
    {
        printf("AMEX\n");
    }
    // check Mastercard/Visa
    else if (counter == 16)
    {
        if (c16 > 50 && c16 < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (c16 >= 40 && c16 <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else if (counter == 13 && c13 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Digit counter function
int get_counter(long n)
{
    int counter = 0;
    while (n != 0)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}

// Luhn's algorithm function
int get_suml(long n)
{
    int sumy, sumx;
    long a = n;
    long b = n / 10;
    for (int i = 0; i < 16; i++)
    {
        // a - digits to be added
        int x = a % 10;
        a = a / 100;
        sumx = sumx + x;

        // b - digits to be multiplied by 2
        int y = b % 10;
        b = b / 100;
        y = y * 2;
        int d1 = y / 10;
        int d2 = y % 10;
        sumy = sumy + d1 + d2;
    }
    return (sumx + sumy) % 10;
}
