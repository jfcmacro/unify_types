#include <string.h>
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

PList_t
fv(PType_t type) {
  PList_t ret;
  switch (type->type) {
  case TyBasic:
    ret = NULL;
    break;

  case TyVar: {
    Var_t nVar = newVar(type->uTypes.tVar);
    ret = newList(nVar);
    break;
  }

  case TyArrow: 
    ret = joinTwoLists(fv(type->uTypes.tArrow.fun), 
		       fv(type->uTypes.tArrow.arg));
    break;
  }
}

PList_t
alfa(PSust_t pSust, PList_t head) {
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
