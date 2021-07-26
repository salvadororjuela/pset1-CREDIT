#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long ccn;

    do
    {
        ccn = get_long_long("Please entre your Credit Card Number: "); //Requests credit card number to user
    }
    while (ccn < 0);

    int len = 0;
    long long length = ccn;   //Variables to record ccn length

    while (length > 0)  // Counts digits
    {
        length = length / 10;
        len++;
    }

    // Validtaes if the number has the adeccuate number of digits
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        // Multiply every other digit by 2, starting with the number’s second-to-last digit
        int digit1 = (((ccn % 100) / 10) * 2);
        int digit2 = (((ccn % 10000) / 1000) * 2);
        int digit3 = (((ccn % 1000000) / 100000) * 2);
        int digit4 = (((ccn % 100000000) / 10000000) * 2);
        int digit5 = (((ccn % 10000000000) / 1000000000) * 2);
        int digit6 = (((ccn % 1000000000000) / 100000000000) * 2);
        int digit7 = (((ccn % 100000000000000) / 10000000000000) * 2);
        int digit8 = (((ccn % 10000000000000000) / 1000000000000000) * 2);

        // Add the sum to the sum of the digits that weren’t multiplied by 2.
        int check1 = ((digit1 % 10) + ((digit1 % 100) / 10));
        check1 = (check1 + ((digit2 % 10) + ((digit2 % 100) / 10)));
        check1 = (check1 + ((digit3 % 10) + ((digit3 % 100) / 10)));
        check1 = (check1 + ((digit4 % 10) + ((digit4 % 100) / 10)));
        check1 = (check1 + ((digit5 % 10) + ((digit5 % 100) / 10)));
        check1 = (check1 + ((digit6 % 10) + ((digit6 % 100) / 10)));
        check1 = (check1 + ((digit7 % 10) + ((digit7 % 100) / 10)));
        check1 = (check1 + ((digit8 % 10) + ((digit8 % 100) / 10)));

        // Second checksum digits
        int digit9 = (ccn % 10);
        int digit10 = ((ccn % 1000) / 100);
        int digit11 = ((ccn % 100000) / 10000);
        int digit12 = ((ccn % 10000000) / 1000000);
        int digit13 = ((ccn % 1000000000) / 100000000);
        int digit14 = ((ccn % 100000000000) / 10000000000);
        int digit15 = ((ccn % 10000000000000) / 1000000000000);
        int digit16 = ((ccn % 1000000000000000) / 100000000000000);

        //Adds checksums
        check1 = (check1 + ((digit9 % 10) + ((digit9 % 100) / 10)));
        check1 = (check1 + ((digit10 % 10) + ((digit10 % 100) / 10)));
        check1 = (check1 + ((digit11 % 10) + ((digit11 % 100) / 10)));
        check1 = (check1 + ((digit12 % 10) + ((digit12 % 100) / 10)));
        check1 = (check1 + ((digit13 % 10) + ((digit13 % 100) / 10)));
        check1 = (check1 + ((digit14 % 10) + ((digit14 % 100) / 10)));
        check1 = (check1 + ((digit15 % 10) + ((digit15 % 100) / 10)));
        check1 = (check1 + ((digit16 % 10) + ((digit16 % 100) / 10)));

        //If checksum doesn't end in 0
        if (check1 % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            //Card brand validation
            if ((ccn >= 340000000000000 && ccn < 350000000000000) || (ccn >= 370000000000000 && ccn < 3800000000000000))
            {
                printf("AMEX\n");
            }
            else if (ccn >= 5100000000000000 && ccn < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }
            else if ((ccn >= 4000000000000 && ccn < 5000000000000) || (ccn >= 4000000000000000 && ccn < 5000000000000000))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
