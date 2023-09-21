#include "shell.h"

/**
 * _memset - fills a block of memory with a constant value
 *
 * Parameters:
 *   s: A pointer to the memory block to fill.
 *   b: The value to fill the memory block with.
 *   n: The number of bytes to fill.
 *
 * Returns:
 *   A pointer to the filled memory block.
 */
char *_memset(char *s, char b, unsigned int n)
{
  for (unsigned int i = 0; i < n; i++) {
    s[i] = b;
  }
  return s;
}

/**
 * ffree - frees an array of strings
 *
 * Parameters:
 *   pp: A pointer to the array of strings to free.
 */
void ffree(char **pp)
{
  if (!pp) {
    return;
  }

  while (*pp) {
    free(*pp);
    pp++;
  }

  free(pp);
}

/**
 * _realloc - reallocates a block of memory
 *
 * Parameters:
 *   ptr: A pointer to the previously allocated block of memory.
 *   old_size: The size of the previously allocated block of memory in bytes.
 *   new_size: The new size of the block of memory in bytes.
 *
 * Returns:
 *   A pointer to the reallocated block of memory, or NULL if an error occurred.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
  void *p;

  if (!ptr) {
    return malloc(new_size);
  }

  if (!new_size) {
    free(ptr);
    return NULL;
  }

  if (new_size == old_size) {
    return ptr;
  }

  p = malloc(new_size);
  if (!p) {
    return NULL;
  }

  unsigned int size_to_copy = old_size < new_size ? old_size : new_size;
  memcpy(p, ptr, size_to_copy);
  free(ptr);
  return p;
}
