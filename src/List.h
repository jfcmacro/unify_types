#ifndef LIST_H
#define LIST_H

typedef struct List {
  void* elem;
  struct List* next;
} List_t, *PList_t;


PList_t
newList(void*);
PList_t
addList(PList_t,void*);

PList_t
joinTwoLists(PList_t, PList_t);

#endif



