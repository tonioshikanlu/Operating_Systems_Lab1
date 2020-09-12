// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() { 
 list_t *newList = malloc(sizeof(list_t));   
 return newList;   
};

void list_free(list_t *l) {
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  while (current->next != NULL) {
    free(current);
    current = current->next;
  };
}

void list_print(list_t *l) {
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  if (current->next == NULL){
    printf("%d\n", current->value);
    return;
  }
  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  };
}

int list_length(list_t *l) { 
  int counter = 0;
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  while (current != NULL) {
    counter ++;
    current = current->next;
  }
  printf("%d\n", counter);
  return counter;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* current = malloc(sizeof(node_t));
  node_t* newNode = malloc(sizeof(node_t));
  newNode->value = value;
  if (l->head == NULL){
    l->head = newNode;
    return;
  }
  current = l->head;
  while (current->next != NULL) {
    current = current->next;
  };
  current->next = newNode;
}

void list_add_to_front(list_t *l, elem value) {
  node_t* current = malloc(sizeof(node_t));
  node_t* temp = malloc(sizeof(node_t));
  node_t* newNode = malloc(sizeof(node_t));
  newNode->value = value;
  if (l->head == NULL){
    l->head = newNode;
    return;
  }
  temp->next = l->head->next;
  temp = l->head;
  l->head = newNode;
  l->head->next = temp;
}

void list_add_at_index(list_t *l, elem value, int index) {
  int counter = 0;
  node_t* current = malloc(sizeof(node_t));
  node_t* temp = malloc(sizeof(node_t));
  node_t* newNode = malloc(sizeof(node_t));
  newNode->value = value;
  current = l->head;
  if (index == 0) {
    if (l->head == NULL){
       l->head = newNode;
       return;
    }
    temp->next = l->head->next;
    temp = l->head;
    l->head = newNode;
    l->head->next = temp;
  }
  while (current->next != NULL) {
    if (counter + 1 == index){
      newNode->next = current->next;
      current->next = newNode;
      current = current->next;
    }
    counter ++;
    current = current->next;
  };
}

elem list_remove_from_back(list_t *l) { 
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  };
  elem ans;
  ans = current->next->value;
  current->next = NULL;
  return ans;
}

elem list_remove_from_front(list_t *l) { 
  node_t* temp = malloc(sizeof(node_t));
  elem ans = l->head->value;
  l->head = l->head->next;
  return ans;
}

elem list_remove_at_index(list_t *l, int index) {
  int counter = 0;
  node_t* current = malloc(sizeof(node_t));
  node_t* temp = malloc(sizeof(node_t));
  elem ans;
  current = l->head;
  if (index == 0) {
    ans = l->head->value;
    l->head = l->head->next;
    return ans;
  }
  while (current != NULL) {
    if (counter + 1 == index){
      ans = current->next->value;
      current->next = current->next->next;
    }
    counter ++;
    current = current->next;
  };
  return ans;
}

bool list_is_in(list_t *l, elem value) { 
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  while (current != NULL) {
    if (current->value == value){
      return true;
    }
    current = current->next;
  };
  return false;
}

elem list_get_elem_at(list_t *l, int index) { 
  int counter = 0;
  elem ans;
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  if (index == 0) {
    return l->head->value;
  }
  while (current->next != NULL) {
    if (counter + 1 == index){
      return current->next->value;
    }
    counter ++;
    current = current->next;
  };
  return -1;
}

int list_get_index_of(list_t *l, elem value) { 
  int counter = 0;
  node_t* current = malloc(sizeof(node_t));
  current = l->head;
  while (current != NULL) {
    if (current->value == value){
      return counter;
    }
    counter ++;
    current = current->next;
  };
  return -1;
}