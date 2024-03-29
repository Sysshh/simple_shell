#include "shell.h"

/**
 * _strncpy - copies a string
 *
 * Parameters:
 *   dest: The destination string to be copied to.
 *   src: The source string.
 *   n: The number of characters to be copied.
 *
 * Returns:
 *   A pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
  int i, j;
  char *s = dest;

  i = 0;
  while (src[i] != '\0' && i < n - 1) {
    dest[i] = src[i];
    i++;
  }
  if (i < n) {
    j = i;
    while (j < n) {
      dest[j] = '\0';
      j++;
    }
  }
  return (s);
}

/**
 * _strncat - concatenates two strings
 *
 * Parameters:
 *   dest: The first string.
 *   src: The second string.
 *   n: The maximum number of bytes to be used.
 *
 * Returns:
 *   A pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
  int i, j;
  char *s = dest;

  i = 0;
  j = 0;
  while (dest[i] != '\0') {
    i++;
  }
  while (src[j] != '\0' && j < n) {
    dest[i] = src[j];
    i++;
    j++;
  }
  if (j < n) {
    dest[i] = '\0';
  }
  return (s);
}

/**
 * _strchr - locates a character in a string
 *
 * Parameters:
 *   s: The string to be parsed.
 *   c: The character to look for.
 *
 * Returns:
 *   A pointer to the first occurrence of the character in the string, or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
  do {
    if (*s == c) {
      return (s);
    }
  } while (*s++ != '\0');

  return (NULL);
}
