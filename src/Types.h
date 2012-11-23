#ifndef TYPES_H
#define TYPES_H
#include "List.h"

// Types

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
  PType_t pType;
} Sust_t, *PSust_t;


typedef struct {
  PType_t pType1;
  PType_t pType2;
} Const_t, *PConst_t;

typedef PList_t PListsust_t;

typedef PList_t PListconst_t;
// Functions

PType_t
newTInt();

PType_t
newTBool();

PType_t
newTVar(Var_t);

PType_t
newTArrow(PType_t, PType_t);

PSust_t 
newPSust_t(Var_t, PType_t);

PConst_t
newPConst_t(PType_t, PType_t);

PListsust_t
newPListsust_t(PSust_t);

PListconst_t
newPListconst_t(PConst_t);

PListsust_t
getTailFromPListsust_t(PListsust_t);

PListconst_t
emptyPListconst_t(); 

PSust_t
getSust_tFromPListconst_t(PListsust_t);

PListconst_t
newPListconst_t(PConst_t);

PListsust_t
getTailFromPListconst_t(PListsust_t plist);

PConst_t
getElemFromPListconst_t(PListconst_t);


Var_t
newVar(Var_t);

Var_t
newNVar_t(ssize_t size);

PList_t
fv(PType_t);

PListconst_t
alfa(PSust_t, PListconst_t);

PConst_t
alfa1(PSust_t, PConst_t);

PType_t
alfa2(PSust_t, PType_t);

PListsust_t
composition(PListsust_t,PListsust_t);

PListsust_t
unify(PListconst_t);
#endif
