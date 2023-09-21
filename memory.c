/**
 * bfree - frees a pointer and NULLs the address
 *
 * Parameters:
 *   ptr: The address of the pointer to free.
 *
 * Returns:
 *   1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
  if (ptr && *ptr) {
    free(*ptr);
    *ptr = NULL;
    return 1;
  }
  return 0;
}
