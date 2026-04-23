#include "palindrome.h"

/**
 * is_palindrome - Checks whether an unsigned long is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original;
	unsigned long reversed;
	unsigned long digit;

	original = n;
	reversed = 0;

	while (n > 0)
	{
		digit = n % 10;
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	return (original == reversed);
}
