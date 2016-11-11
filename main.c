
#include <stdio.h>
#include "list.h"

int main() {
  List* myList = newList();

  int z = 10;

  append(myList, &z);

  int a = 5;

  append(myList, &a);

  int c = 15;

  append(myList, &c);

  printInt(myList);

  // destroy(myList);
  //
  // printInt(myList);

  removeItem(myList, 0);

  printInt(myList);

  int* value = (int*) (getValueByIndex(myList, 1));
  printf("\n\n\n%d\n", *value );

  return 0;
}
