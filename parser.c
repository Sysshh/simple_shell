/**
 * is_cmd - checks if a file is executable
 *
 * Parameters:
 *   path: The path to the file.
 *
 * Returns:
 *   1 if the file is executable, 0 otherwise.
 */
int is_cmd(char *path)
{
  struct stat st;

  if (!path || stat(path, &st)) {
    return 0;
  }

  if (st.st_mode & S_IFREG) {
    return 1;
  }
  return 0;
}

/**
 * dup_chars - creates a new buffer containing the characters from the specified start and stop indices
 *
 * Parameters:
 *   pathstr: The string to copy from.
 *   start: The starting index.
 *   stop: The stopping index.
 *
 * Returns:
 *   A pointer to the new buffer, or NULL if an error occurred.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
  static char buf[1024];
  int i = 0, k = 0;

  for (k = 0, i = start; i < stop; i++) {
    if (pathstr[i] != ':') {
      buf[k++] = pathstr[i];
    }
  }
  buf[k] = 0;
  return buf;
}

/**
 * find_path - finds the full path of a command in the PATH string
 *
 * Parameters:
 *   pathstr: The PATH string.
 *   cmd: The command to find.
 *
 * Returns:
 *   The full path of the command, or NULL if the command is not found.
 */
char *find_path(char *pathstr, char *cmd)
{
  int i = 0, curr_pos = 0;
  char *path;

  if (!pathstr) {
    return NULL;
  }

  if ((_strlen(cmd) > 2) && starts_with(cmd, "./")) {
    if (is_cmd(cmd)) {
      return cmd;
    }
  }

  while (1) {
    if (!pathstr[i] || pathstr[i] == ':') {
      path = dup_chars(pathstr, curr_pos, i);
      if (!*path) {
        _strcat(path, cmd);
      } else {
        _strcat(path, "/");
        _strcat(path, cmd);
      }
      if (is_cmd(path)) {
        return path;
      }
      if (!pathstr[i]) {
        break;
      }
      curr_pos = i;
    }
    i++;
  }
  return NULL;
}
