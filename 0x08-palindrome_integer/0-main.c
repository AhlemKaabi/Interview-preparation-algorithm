#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ", n);
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}
/* recursive approach */
/**
*  int is_Palindrome(int aj)
* {
*	static int sum = 0;
*	if(aj != 0)
*	{
*		sum = sum *10 + aj%10;
*		is_Palindrome(aj/10); // recursive call
*	}
*	else if(sum == n)
*		return 1;
*	else
*		return 0;
* }
*/