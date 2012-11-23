#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "Types.h"

static PType_t
newPType_t() {
  return malloc(sizeof(Type_t));
}

Var_t
newVar(Var_t var) {
  Var_t ret = (Var_t) malloc(strlen(var) + 1);
  strcpy(ret, var);
  return ret;
}

PType_t
newTInt() {
  PType_t ret = newPType_t();
  ret->type = TyBasic;
  ret->uTypes.tbasic = TInt;
  return ret;
}

PType_t
newTBool() {
  PType_t ret = newPType_t();
  ret->type = TyBasic;
  ret->uTypes.tbasic = TBool;
  return ret;
}

PType_t
newTVar(Var_t var) {
  PType_t ret = newPType_t();
  ret->type = TyVar;
  ret->uTypes.tVar = var;
  return ret;
}

PType_t
newTArrow(PType_t fun, PType_t arg) {
  PType_t ret = newPType_t();
  ret->type = TyArrow;
  ret->uTypes.tArrow.fun = fun;
  ret->uTypes.tArrow.arg = arg;
  return ret;
}

PSust_t
newPSust_t(Var_t var, PType_t type) {
  PSust_t ret = (PSust_t) malloc(sizeof(Sust_t));
  ret->sVar = var;
  ret->pType = type;
  return ret;
}

PConst_t
newPConst_t(PType_t type1, PType_t type2) {
  PConst_t ret = (PConst_t) malloc(sizeof(Const_t));
  ret->pType1 = type1;
  ret->pType2 = type2;
  return ret;
}

PListsust_t
newPListsust_t(PSust_t elem) {
  return (PListsust_t) newPList_t(elem);
}

PListsust_t
emptyPListsust_t() {
  return (PListsust_t) emptyPList_t();
}

PListsust_t
getTailFromPListsust_t(PListsust_t plist) {
  return getTailFromPList_t(plist);
}

PListconst_t
newPListconst_t(PConst_t elem) {
  return (PListconst_t) newPList_t(elem);
}

PListconst_t
emptyPListconst_t() {
  return (PListconst_t) emptyPList_t();
}

PListsust_t
getTailFromPListconst_t(PListsust_t plist) {
  return (PListconst_t) getTailFromPList_t(plist);
}

PConst_t
getElemFromPListconst_t(PListconst_t plist) {
  return (PConst_t) getElemFromPList_t(plist);
}

Var_t
newVar_t(Var_t var) {
  char* ret = (Var_t) malloc(strlen(var) + 1);
  strcpy(ret, var);
  return ret;
}

Var_t
newNVar_t(ssize_t size) {
  return (Var_t) malloc(size);
}

PList_t
fv(PType_t type) {
  PList_t ret;
  switch (type->type) {
  case TyBasic:
    ret = NULL;
    break;

  case TyVar: {
    Var_t nVar = newVar(type->uTypes.tVar);
    ret = newPList_t(nVar);
    break;
  }

  case TyArrow:
    ret = joinTwoPList_ts(fv(type->uTypes.tArrow.fun),
			  fv(type->uTypes.tArrow.arg));
    break;
  }
}

PListconst_t
alfa(PSust_t pSust, PListconst_t head) {
  PList_t cur;
  for (cur = head; cur; cur = cur->next) {
    cur->elem = alfa1(pSust, (PConst_t) cur->elem);
  }
  return head;
}

PConst_t
alfa1(PSust_t pSust, PConst_t pConst) {

  pConst->pType1 = alfa2(pSust, pConst->pType1);
  pConst->pType2 = alfa2(pSust, pConst->pType2);
  return pConst;
}

PType_t
alfa2(PSust_t pSust, PType_t pType) {
  PType_t ret = NULL;

  switch(pType->type) {
  case TyBasic:
    ret = pType;
    break;

  case TyVar:
    if (strcmp(pType->uTypes.tVar, pSust->sVar) == 0) {
      ret = pSust->pType;
    }
    else {
      ret = pType;
    }
    break;

  case TyArrow:
    pType->uTypes.tArrow.fun = alfa2(pSust, pType->uTypes.tArrow.fun);
    pType->uTypes.tArrow.arg = alfa2(pSust, pType->uTypes.tArrow.arg);
    ret = pType;
    break;
  }

  return ret;
}

PListsust_t
composition(PListsust_t head, PListsust_t tail) {
  return joinTwoPList_ts(head, tail);
}

PListsust_t
unify(PListconst_t plconst) {

  if (plconst == NULL) {
    return emptyPListconst_t();
  }
  else {
    PConst_t     pconst_t    = getElemFromPListconst_t(plconst);
    PListconst_t plconstTail = getTailFromPListconst_t(plconst);
  }
}
