#include <stdio.h>
#include <stdlib.h>
//
// structs
//
typedef struct Node
{
  void* data;
  size_t data_size;
  struct Node* next;

} node;

typedef struct List
{
  node* head;
  node* tail;

} list;

//
// functions start here
//
list
init()
{
  list new;
  new.head = NULL;
  new.tail = NULL;
  return new;
}

//
// adds to the start
//
int
add(list* lst, void* data, size_t data_size)
{
  node* new;
  new = malloc(sizeof(node));
  new->data = data;
  new->data_size = data_size;
  new->next = lst->head;
  lst->head = new;
  if (lst->tail == NULL) {
    lst->tail = new;
  }
  return 0;
}

int
main(int argc, char** argv)
{
  list lst = init();

  int* a;
  a = malloc(sizeof(int));
  *a = 3;

  add(&lst, a, sizeof(int));

  int* to_print = lst.head->data;
  printf("%i", *to_print);
}
