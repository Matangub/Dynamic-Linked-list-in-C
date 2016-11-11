
#include <stdio.h>

typedef struct Node {
  void* data;
  void* next;
} Node;

typedef struct List {
  Node* head;
} List;

List* newList(); // initialize a new list

int isEmpty(List* list); //check if the list is empty

void printInt(List* list); // prints a given list(integers only)

void append(List* list, void* data); //append an item to a given list

void destroy(List* list); //frees from memory all items in the given list

void removeItem(List* list, int index); //remove an item at a specific index

void* getValueByIndex(List* list, int index); //remove an item at a specific index

int length(List* list); //returns length of list
