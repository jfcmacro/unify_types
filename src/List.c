#include "List.h"
#include <stdlib.h>

PList_t
newPList_t(void* elem) {
  PList_t ret = malloc(sizeof(List_t));
  ret->elem = elem;
  ret->next = NULL;
  return ret;
}

PList_t
addPList_t(PList_t prev, void*elem) {
  PList_t ret;
  ret = (PList_t) malloc(sizeof(List_t));
  ret->elem = elem;
  ret->next = prev;
}

PList_t
joinTwoPList_ts(PList_t firstL, PList_t secondL) {

  PList_t head;
  PList_t prev;

  if (!firstL) {
    return secondL;
  }

  if (!secondL) {
    return firstL;
  }

  for (head = firstL, prev = firstL; 
       head; 
       prev = head, head = head-> next);

  prev->next = secondL;
  return firstL;
}

void*
getElemFromPList_t(PList_t head) {
  if (head) {
    return head->elem;
  }
  return NULL;
}

PList_t
getTailFromPList_t(PList_t head) {
  PList_t ret = head ? head->next : head;
  free(head);
  return ret;
}
