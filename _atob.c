#include "shell.h"


/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checking for alphabetic character
 * @c: The char to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int a)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atob - converts a string to  integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atob(char *a)
{
	int d, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; a[d] != '\0' && flag != 2; i++)
	{
		if (a[d] == '-')
			sign *= -1;

		if (a[d] >= '0' && a[d] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

