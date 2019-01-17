/*----------------------------------------------------------
 *				HTBLA-Leonding / 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			David Kraus
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <math.h>

bool is_prime_number(unsigned long number)
{
    if (number == 1) return false;

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}

int get_length(unsigned long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

unsigned long remove_digit(int i, unsigned long number)
{
    long left = 0, right = 0;
    
    if (i == 0) return number / 10;

    left  = number / pow(10, i + 1);
    right = number % (unsigned long) pow(10, i);

    return left * pow(10, i) + right;
}

int get_ways(unsigned long number)
{
    int ways = 0;
    for (int i = 0; i < get_length(number); i++)
    {
        if (get_length(number) == 1 && is_prime_number(number)) return 1;
        
        if (is_prime_number(remove_digit(i, number)))
        {
            ways += get_ways(remove_digit(i, number));
        }
    }
    return ways;
}
