#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 *
 * Parameters:
 *   str: The string to print.
 *
 * Returns:
 *   Nothing.
 */
void _eputs(char *str)
{
  int i = 0;

  if (!str) {
    return;
  }
  while (str[i] != '\0') {
    _eputchar(str[i]);
    i++;
  }
}

/**
 * _eputchar - writes the character c to stderr
 *
 * Parameters:
 *   c: The character to print.
 *
 * Returns:
 *   1 on success, -1 on error.
 */
int _eputchar(char c)
{
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(2, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH) {
    buf[i++] = c;
  }
  return (1);
}

/**
 * _putfd - writes the character c to the given file descriptor
 *
 * Parameters:
 *   c: The character to print.
 *   fd: The file descriptor to write to.
 *
 * Returns:
 *   1 on success, -1 on error.
 */
int _putfd(char c, int fd)
{
  static int i;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(fd, buf, i);
    i = 0;
  }
  if (c != BUF_FLUSH) {
    buf[i++] = c;
  }
  return (1);
}

/**
 * _putsfd - prints an input string to the given file descriptor
 *
 * Parameters:
 *   str: The string to print.
 *   fd: The file descriptor to write to.
 *
 * Returns:
 *   The number of characters printed.
 */
int _putsfd(char *str, int fd)
{
  int i = 0;

  if (!str) {
    return (0);
  }
  while (*str) {
    i += _putfd(*str++, fd);
  }
  return (i);
}
