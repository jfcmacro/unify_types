#include "List.h"
#include <stdlib.h>


PList_t
addList(PList_t prev, void*elem) {
  PList_t ret;
  ret = (PList_t) malloc(sizeof(List_t));
  ret->elem = elem;
  ret->next = prev;
}

PList_t
joinTwoLists(PList_t firstL, PList_t secondL) {

  PList_t head;
  PList_t prev;

  if (!firstL) {
    return secondL;
  }

  if (!secondL) {
    return firstL;
  }

  for (head = firstL, prev = firstL; head; head = head-> next,
                                           prev = head);

  prev->next = secondL;
  return firstL;
}
