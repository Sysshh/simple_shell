#include "shell.h"

/**
 * input_buf - buffers chained commands
 *
 * Parameters:
 *   info: The parameter struct.
 *   buf: The address of the buffer.
 *   len: The address of the length variable.
 *
 * Returns:
 *   The number of bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
  ssize_t r = 0;
  size_t len_p = 0;

  if (!*len) /* if nothing left in the buffer, fill it */
  {
    /*bfree((void **)info->cmd_buf);*/
    free(*buf);
    *buf = NULL;
    signal(SIGINT, sigintHandler);
#if USE_GETLINE
    r = getline(buf, &len_p, stdin);
#else
    r = _getline(info, buf, &len_p);
#endif
    if (r > 0)
    {
      if ((*buf)[r - 1] == '\n')
      {
        (*buf)[r - 1] = '\0'; /* remove trailing newline */
        r--;
      }
      info->linecount_flag = 1;
      remove_comments(*buf);
      build_history_list(info, *buf, info->histcount++);
      /* if (_strchr(*buf, ';')) is this a command chain? */
      {
        *len = r;
        info->cmd_buf = buf;
      }
    }
  }
  return (r);
}

/**
 * get_input - gets a line minus the newline
 *
 * Parameters:
 *   info: The parameter struct.
 *
 * Returns:
 *   The number of bytes read.
 */
ssize_t get_input(info_t *info)
{
  static char *buf; /* the ';' command chain buffer */
  static size_t i, j, len;
  ssize_t r = 0;
  char **buf_p = &(info->arg), *p;

  _putchar(BUF_FLUSH);
  r = input_buf(info, &buf, &len);
  if (r == -1) /* EOF */
    return (-1);
  if (len) /* we have commands left in the chain buffer */
  {
    j = i; /* init new iterator to current buf position */
    p = buf + i; /* get pointer for return */

    check_chain(info, buf, &j, i, len);
    while (j < len) /* iterate to semicolon or end */
    {
      if (is_chain(info, buf, &j))
        break;
      j++;
    }

    i = j + 1; /* increment past nulled ';'' */
    if (i >= len) /* reached end of buffer? */
    {
      i = len = 0; /* reset position and length */
      info->cmd_buf_type = CMD_NORM;
    }

    *buf_p = p; /* pass back pointer to current command position */
    return (_strlen(p)); /* return length of current command */
  }

  *buf_p = buf; /* else not a chain, pass back buffer from _getline() */
  return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 *
 * Parameters:
 *   info: The parameter struct.
 *   buf: The buffer.
 *   i: The size.
 *
 * Returns:
 *   The number of bytes read.
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
  ssize_t r = 0;

  if (*i)
    return (0);
  r = read(info->readfd, buf, READ_BUF_SIZE);
  if (r >= 0)
    *i = r;
  return (r);
}
