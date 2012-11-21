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

PType_t
newTInt();

PType_t
newTBool();

PType_t
newTVar(Var_t);

PType_t
newTArrow(PType_t, PType_t);

typedef struct {
  Var_t sVar;
  PType_t pType;
} Sust_t, *PSust_t;

typedef struct {
  PType_t pType1;
  PType_t pType2;
} RConst_t, *PConst_t;

Var_t
newVar(Var_t);

PList_t
fv(PType_t);

PList_t
alfa(PSust_t, PList_t);

PConst_t
alfa1(PSust_t, PConst_t);

PType_t
alfa2(PSust_t, PType_t);


#endif
