// list/list.c
// 
// Implementation for linked list.
//
// Aaron Garner @02849833

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


list_t *list_alloc(){
  list_t *new_list = malloc(sizeof(list_t));
  new_list->head = NULL;
  return new_list;
}

void node_free(node_t *n){
  if (n->next != NULL){
    node_free(n->next);
  }
  else{
    free(n);
  }
}

void list_free(list_t *l){
  node_t *curr_node = l->head;
  
  if (curr_node != NULL){
    node_free(curr_node);
  }
}

void list_print(list_t *l){
  node_t *curr_node = l->head;
  
  while (curr_node != NULL){
    printf("%d -> ", curr_node->value);
    curr_node = curr_node->next;
  }
  
  printf("\n");
}

int list_length(list_t *l){ 
  int list_length = 0;
  node_t *curr_node = l->head;
  
  if (curr_node == NULL){
    return 0;
  }
   
  while (curr_node != NULL){
    list_length++;
    curr_node = curr_node->next;
  }
  
  return list_length; 
}

void list_add_to_back(list_t *l, elem value){
  node_t *curr_node = l->head;
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  
  if (curr_node == NULL){
    l->head = new_node;
    return;
  }
  
  while (curr_node->next != NULL){
    curr_node = curr_node->next;
  }
  
  curr_node->next = new_node;
}

void list_add_to_front(list_t *l, elem value){
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index){
  if ((index <= 0) || (index >= list_length(l))){
    return;
  }
  
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *curr_node = l->head;
  
  for (int curr_index = 0; curr_index < index - 1; curr_index++){
    curr_node = curr_node->next;
  }

  if (curr_node == NULL){
    l->head = new_node;
  }
  else{
    new_node->next = curr_node->next;
    curr_node->next = new_node;
  }

}

elem list_remove_from_back(list_t *l){
  node_t *curr_node = l->head;
  node_t *returned_node = curr_node;

  while ((curr_node != NULL) && (curr_node->next != NULL)){
    
    if (curr_node->next->next == NULL){
      returned_node = curr_node->next;
      curr_node->next = NULL;
    }
    else{
      curr_node = curr_node->next;
    }

  }

  return returned_node->value;
}

elem list_remove_from_front(list_t *l){
  if (l->head == NULL){
    printf("Cannot remove from empty list.\n");
    return 0;
  }
  else{
    int returned_val = l->head->value;
    l->head = l->head->next;
    
    return returned_val;
  }
}

elem list_remove_at_index(list_t *l, int index) {
  if ((index < 0) || (index >= list_length(l))){
    return 0;
  }
  
  node_t *curr_node = l->head;
  
  for (int curr_index = 0; curr_index < index - 1; curr_index++){
    curr_node = curr_node->next;
  }

  int returned_val = curr_node->next->value;
  curr_node->next = curr_node->next->next;
  
  return returned_val;
}


bool list_is_in(list_t *l, elem value) {
  if (l->head == NULL){
    printf("Cannot search empty list.\n");
    return false;
  }
  
  node_t *curr_node = l->head;
  
  while (curr_node != NULL){
    if (curr_node->value == value){
      return true;
    }
    
    curr_node = curr_node->next;
  }
  
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if ((index < 0) || (index >= list_length(l))){
    return 0;
  }
  
  node_t *curr_node = l->head;
  
  for (int curr_index = 0; curr_index  < index; curr_index++){
    curr_node = curr_node->next;
  }

  return curr_node->value;
}

int list_get_index_of(list_t *l, elem value) {
  if (l->head == NULL){
    printf("Cannot search empty list.\n");
    return -1;
  }
  
  node_t *curr_node = curr_node = l->head;
  int curr_index = 0;

  while (curr_node != NULL){
    if (curr_node->value == value){
      return curr_index;
    }
   
    curr_node = curr_node->next;
    curr_index++;
  }
  
  return -1;
}

