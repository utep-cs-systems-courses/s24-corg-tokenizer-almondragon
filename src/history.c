#include "history.h"
#include <stdio.h>
#include <stdlib.h>


List* init_history(){
  List *history = malloc(sizeof(List)); // history points to a structure of list
  if(history == NULL){ // if history is null, memory was not allocated
    printf("Memory was not alloacted to the history linked list");
    return NULL;
  }
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  Item *new_item = malloc(sizeof(Item)); // allocating memory for the item
  if(new_item == NULL){ // checking if memory was in fact allocated
    printf("Memory was not allocated to new item");
    return;
  }
  // finding the length of the str
  int index = 0;
  while(str[index] != '\0'){
    index++;
  }
  // allocating memory for the copy of str
  new_item->str = malloc(index+1);
  if(new_item->str == NULL){
    printf("Memory was not allocated to the str of new item");
    return;
  }
  for(int i=0; i<index;i++){
    new_item->str[i] = str[i];
  }
  new_item->str[index] = '\0'; // str has a zero terminator set to it's last index
  new_item->next = NULL; // the next value of new_item is null as there is no next value

  //ADDING ITEM
  // adding if list is empty
  if(list->root == NULL){
    new_item->id = 1; // as list is empty, new item becomes the first item in the list
    list->root = new_item; // the root of the list is now to the new item
  }else{ // adding if list is not empty
    Item *temporary = list->root; // temporary is set to the head of the list
    while(temporary->next != NULL){ // traversing to end of list
      temporary = temporary->next; // temporary is set to next item in list until end
    }
    new_item->id = temporary->id + 1; // id of new item is set to one plus the id of temp
    temporary->next = new_item; // the next value of temp is set to new_item
  }
  
  
}

char *get_history(List *list, int id){
  Item *temporary = list->root;
  // locating the item with the indicated string
  while(temporary != NULL && temporary->id != id){
    temporary = temporary->next;
  }
  // case if the id is not is list
  if(temporary == NULL){
    printf("!%d not found in history\n", id);
    return NULL;
  }
  // returning item that has the id
  char *history_string = temporary->str;
  return history_string;
}

void print_history(List *list){
  // if list is empty and there is no history
  if(list == NULL){
    printf("No history is available");
    return;
  }
  Item *temporary = list->root; // current root
  while(temporary != NULL){ // traverses list until reaches null
    printf("%5d %s\n", temporary->id, temporary->str); // prints the id and str of each item
    temporary = temporary->next; // temporary is set to the next item in the list
  }
}

void free_history(List *list){
  // checks if list is empty to begin with
  if(list == NULL){
    return; // if so, nothing to free
  }
  Item *temporary = list->root;
  while(temporary != NULL){
    Item *to_free = temporary; // a pointer to what is to be freed
    temporary = temporary->next; // temporary is set to the next item in the list
    free(to_free->str); // frees the str of the current item
    free(to_free); // frees the current item
  }
  free(list); // frees the entire list
}


