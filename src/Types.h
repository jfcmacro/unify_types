#ifndef TYPES_H
#define TYPES_H
#include "List.h"

enum TBasic { TInt, TBool };
enum TTypes { TyBasic, TyVar, TyArrow };

typedef enum TBasic TBasic_t;
typedef enum TTypes TTypes_t;
typedef char * Var_t;

typedef struct Type {
  TTypes_t type;
  union {
    TBasic_t tbasic;
    Var_t tVar;
    struct Arrow {
      struct Type* fun;
      struct Type* arg;
    } tArrow;
  } uTypes;
} Type_t, *PType_t; 

typedef struct {
  Var_t sVar;
  Type_t type;
} Sust_t, *PSust_t;

typedef struct {
  Type_t type1;
  Type_t type2;
} Const_t, *PConst_t;

Var_t
newVar(Var_t);

PList_t
fv(PType_t);


#endif
