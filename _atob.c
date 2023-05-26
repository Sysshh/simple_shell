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
int is_delim(char c, char *delim) {
  while (*delim) {
    if (c == *delim++) {
      return 1;
    }
  }
  return 0;
}

/**
 * _isalpha - checking for alphabetic character
 * @c: The char to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int isalpha(int c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


/**
 * _atob - converts a string to  integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int atob(char *str) {
  int sign = 1, i;
  unsigned long long result = 0;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '-') {
      sign = -1;
    } else if (str[i] >= '0' && str[i] <= '9') {
      result *= 10;
      result += str[i] - '0';
    }
  }

  return sign * result;
}


