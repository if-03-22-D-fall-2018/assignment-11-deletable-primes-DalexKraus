/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <stdbool.h>
#include <stdio.h>

#define DIGIT_BUFFER_SIZE 128

int get_number_length(int number)
{
    int length = 0;
    while (number > 1)
    {
        number /= 10;
        length++;
    }
    return length;
}

void number_to_array(int* buffer, int number)
{
    int num_len = get_number_length(number);
    for (int i = 0; i < num_len; i++)
    {
        buffer[num_len - i - 1] = number % 10;
        number /= 10;
    }
}

bool is_prime_number(int number)
{
    bool isPrime = true;
    for (int i = 2; i <= number / 2; ++i)
    {
        if (number % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int remove_digit(int number, int src)
{
    int digit_buffer[DIGIT_BUFFER_SIZE];
    for (int i = 0; i < DIGIT_BUFFER_SIZE; i++)
        digit_buffer[i] = -1;

    number_to_array(digit_buffer, src);

    //Delete all equal digits
    for (int i = 0; i < DIGIT_BUFFER_SIZE; i++)
    {
        if (digit_buffer[i] != -1 && digit_buffer[i] == number)
            digit_buffer[i]  = -1;
    }

    //Convert back to int
    int result = 0;
    for (int i = 0; i < get_number_length(src); i++)
    {
        if (digit_buffer[i] != -1) 
            result = 10 * result + digit_buffer[i]; 
    }

    return result;
}

int get_ways(int number)
{
    int ways = 0;
    if (number >= 10)
        number = remove_digit(number % 10, number);
    
    if (is_prime_number(number))
    {
        ways += get_ways(number);
    }

    return ways;
}

int main(int argc, const char* argv[])
{
    return 0;
}
