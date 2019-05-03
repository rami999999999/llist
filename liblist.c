#include <stdio.h>

typedef struct Node
{
  struct Node* next;
  void* data;
} node;

node*
init()
{
  node* list;
  list = NULL;
  return list;
}

enum loop
{
  ongoing, // evals to zero (TRUE)
  done     // evals to one (FALSE)
};

/*
 * Adds node to the beginning of the list
 */
int
add(node* list, node* new)
{
  new->next = list;
  list = new;
  return 0;
}

/*
 * Adds node to specific place
 */
int
add_inplace(node* list, node* new, int (*is_place)(void* data))
{
  node* aux;
  aux = list;
  enum loop add_node = ongoing;
  while (aux != NULL && add_node == ongoing) {
    if (is_place(aux->data)) {
      new->next = aux->next;
      aux->next = new;
      add_node = done;
    }
    aux = aux->next;
  }

  if (add_node == done) {
    return 0;
  } else {
    return 1;
  }
}
