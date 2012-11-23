#ifndef LIST_H
#define LIST_H

typedef struct List {
  void* elem;
  struct List* next;
} List_t, *PList_t;

PList_t
newPList_t(void*);

PList_t
emptyPList_t();

PList_t
addPList_t(PList_t,void*);

PList_t
joinTwoPList_ts(PList_t, PList_t);

PList_t
getTailFromPList_t(PList_t);

void*
getElemFromPList_t(PList_t);
#endif



