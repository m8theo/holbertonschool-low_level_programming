#include "main.h"

/**
 * _prime_helper - checks if n has a divisor starting from i
 * @n: number to check
 * @i: current divisor candidate
 *
 * Return: 1 if no divisor is found, 0 otherwise
 */
int _prime_helper(int n, int i)
{
	if (i > n / i)
		return (1);
	if (n % i == 0)
		return (0);
	return (_prime_helper(n, i + 1));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (_prime_helper(n, 2));
}
