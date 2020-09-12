#include <stdio.h>
#include <assert.h> 

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *newList = list_alloc();
  printf("\nTests for Add to back\n");
  list_add_to_back(newList, 3);
  list_add_to_back(newList, 9);
  list_add_to_back(newList, 7);
  list_add_to_back(newList, 477);
  list_print(newList);
  printf("\nTests for Add to front\n");
  list_add_to_front(newList, 5);
  list_print(newList);
  printf("\nTests for Add at index\n");
  list_add_at_index(newList, 82, 4);
  list_print(newList);
  printf("\nTests for remove from back\n");
  list_remove_from_back(newList);
  list_print(newList);
  printf("\nTests for remove from front\n");
  list_remove_from_front(newList);
  list_print(newList);
  printf("\nTests for remove at index\n");
  list_remove_at_index(newList, 3);
  list_print(newList);
  printf("\nTests for is in list\n");
  bool x = list_is_in(newList, 36);
  printf("%s\n", x ? "true" : "false");
  bool y = list_is_in(newList, 9);
  printf("\n%s\n", y ? "true" : "false");
  printf("\nTests for get element at\n");
  elem m = list_get_elem_at(newList, 1);
  printf("%d\n", m);
  printf("\nTests get index of \n");
  int r = list_get_index_of(newList, 3);
  printf("%d\n", r);
  printf("\nTests for list length\n");
  list_length(newList);
  list_free(newList);
  return 0;
}