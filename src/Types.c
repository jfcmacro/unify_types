#include <string.h>
#include "Types.h"

Var_t
newVar(Var_t var) {
  Var_t ret = (Var_t) malloc(strlen(var) + 1);
  strcpy(ret, var);
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
