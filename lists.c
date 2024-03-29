#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 *
 * Parameters:
 *   head: The address of the pointer to the head node.
 *   str: The string field of the node.
 *   num: The node index used by history.
 *
 * Returns:
 *   The pointer to the new head node.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
  list_t *new_head;

  if (!head) {
    return NULL;
  }

  new_head = malloc(sizeof(list_t));
  if (!new_head) {
    return NULL;
  }

  memset((void *)new_head, 0, sizeof(list_t));
  new_head->num = num;
  if (str) {
    new_head->str = strdup(str);
    if (!new_head->str) {
      free(new_head);
      return NULL;
    }
  }

  new_head->next = *head;
  *head = new_head;

  return new_head;
}

/**
 * add_node_end - adds a node to the end of the list
 *
 * Parameters:
 *   head: The address of the pointer to the head node.
 *   str: The string field of the node.
 *   num: The node index used by history.
 *
 * Returns:
 *   The pointer to the new node.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
  list_t *new_node, *node;

  if (!head) {
    return NULL;
  }

  node = *head;
  new_node = malloc(sizeof(list_t));
  if (!new_node) {
    return NULL;
  }

  memset((void *)new_node, 0, sizeof(list_t));
  new_node->num = num;
  if (str) {
    new_node->str = strdup(str);
    if (!new_node->str) {
      free(new_node);
      return NULL;
    }
  }

  if (node) {
    while (node->next) {
      node = node->next;
    }

    node->next = new_node;
  } else {
    *head = new_node;
  }

  return new_node;
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 *
 * Parameters:
 *   h: The pointer to the first node.
 *
 * Returns:
 *   The size of the list.
 */
size_t print_list_str(const list_t *h)
{
  size_t i = 0;

  while (h) {
    puts(h->str ? h->str : "(nil)");
    puts("\n");
    h = h->next;
    i++;
  }

  return i;
}

/**
 * delete_node_at_index - deletes node at given index
 *
 * Parameters:
 *   head: The address of the pointer to the first node.
 *   index: The index of the node to delete.
 *
 * Returns:
 *   1 on success, 0 on failure.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
  list_t *node, *prev_node;
  unsigned int i = 0;

  if (!head || !*head) {
    return 0;
  }

  if (!index) {
    node = *head;
    *head = (*head)->next;
    free(node->str);
    free(node);
    return 1;
  }

  node = *head;
  while (node) {
    if (i == index) {
      prev_node->next = node->next;
      free(node->str);
      free(node);
      return 1;
    }

    i++;
    prev_node = node;
    node = node->next;
  }

  return 0;
}

/**
 * free_list - frees
