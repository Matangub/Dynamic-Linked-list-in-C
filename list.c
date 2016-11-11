
#include "list.h"
#include <stddef.h>
#include <malloc.h>

List* newList() {

  List* newList = malloc( sizeof(List) );
  newList->head = NULL;

  return newList;
}

int isEmpty(List* list) {

  return ( list->head == NULL );
}

void printInt(List* list) {

  printf("\n\tLIST CONTENT:");

  Node* chain = list->head;

  int nodeValue = 0;

  while( !isEmpty(list) && (chain != NULL) ) {

    nodeValue = *((int*) chain->data);
    printf(" %d ", nodeValue );
    chain = chain->next;
  }
}

void append(List* list, void* data) {

  Node* chain = list->head;

  while( !isEmpty(list) && chain->next != NULL ) {

    chain = chain->next;
  }

  Node* newNode = malloc( sizeof(Node) );
  newNode->data = data;
  newNode->next = NULL;

  if( isEmpty(list) ) {
    list->head = newNode;
  }
  else {
    chain->next = newNode;
  }

}

void destroy(List* list) {

  Node* chain = list->head;
  Node* previousNode = NULL;

  while( !isEmpty(list) && (chain != NULL) ) {

    previousNode = chain;
    chain = chain->next;
    free(previousNode);
  }

  list->head = NULL;
}

void removeItem(List* list, int index) {

  int listLength = length(list);
  Node* chain = list->head;
  Node* previousNode = NULL;

  if( index > listLength ) {
    printf("given index is too big");
    return;
  }

  for(int i = 0; (chain->next != NULL && i < index); i++) {

    previousNode = chain;
    chain = chain->next;
  }

  if(listLength == 1) { // if list has a single node
    free(chain);
    list->head = NULL;
  }
  else if( previousNode != NULL && chain->next != NULL ) { //between other nodes
    previousNode->next = chain->next;
    free(chain);
  }
  else if(listLength == (index+1) ) { // last node in chain
    free(chain);
    previousNode->next = NULL;
  }
  else if(index == 0) { // first node in chain
    list->head = chain->next;
    free(chain);
  }
}

void* getValueByIndex(List* list, int index) {

  int listLength = length(list);
  Node* chain = list->head;

  if( index > listLength ) {
    printf("given index is too big");
    return NULL;
  }

  for(int i = 0; (chain->next != NULL && i < index); i++) {

    chain = chain->next;
  }

  return chain->data;
}

int length(List* list) {
  Node* chain = list->head;
  int length = 0;

  while( chain != NULL ) {

    ++length;
    chain = chain->next;
  }

  return length;
}
