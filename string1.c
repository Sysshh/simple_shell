#include "shell.h"

/**
 * _strcpy - copies a string
 *
 * Parameters:
 *   dest: the destination buffer
 *   src: the source string
 *
 * Returns:
 *   a pointer to the destination buffer
 */
char *_strcpy(char *dest, char *src)
{
  int i = 0;

  if (dest == src || src == NULL) {
    return (dest);
  }
  while (src[i]) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

/**
 * _strdup - duplicates a string
 *
 * Parameters:
 *   str: the string to duplicate
 *
 * Returns:
 *   a pointer to the duplicated string, or NULL if there is an error
 */
char *_strdup(const char *str)
{
  int length = 0;
  char *ret;

  if (str == NULL) {
    return (NULL);
  }
  while (*str++) {
    length++;
  }
  ret = malloc(sizeof(char) * (length + 1));
  if (!ret) {
    return (NULL);
  }
  for (length++; length--;) {
    ret[length] = *--str;
  }
  return (ret);
}

/**
 * _puts - prints a string
 *
 * Parameters:
 *   str: the string to print
 *
 * Returns:
 *   void
 */
void _puts(char *str)
{
  int i = 0;

  if (!str) {
    return;
  }
  while (str[i] != '\0') {
    _putchar(str[i]);
    i++;
  }
}

/**
 * _putchar - writes a character to stdout
 *
 * Parameters:
 *   c: the character to print
 *
 * Returns:
 *   1 on success, -1 on error
 */
int _putchar(char c)
{
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(1, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH) {
    buf[i++] = c;
  }
  return (1);
}
