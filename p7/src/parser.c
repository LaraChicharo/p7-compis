#include "parser.h"
#include <stdio.h>
extern token *yylex();
extern int yylineno;

void eat(int clase) {
  if(equals(tokenActual, clase)) {
    tokenActual = yylex();
  } else {
    error("Error de sintaxis");
  }
}

void parse() {
  //inicializar TS y TT
  A();
  //imprimir TS y TT
}

void A() {
  B();
  G();
  if(equals(tokenActual, FIN)) {
    puts("Fin de análisis sintáctico.");
    return;
  }
}

void B(){
  C();
  F();
  if (equals(tokenActual, PCOMA)) {
    eat(PCOMA);
    B();
  }
}

void C(){
  D();
  E();
}

void D(){
  if (equals(tokenActual, INT)) {
    eat(INT);
  }
  else if (equals(tokenActual, FLOAT)) {
    eat(FLOAT);
  }
  else if (equals(tokenActual, CHAR)) {
    eat(CHAR);
  }
  else if (equals(tokenActual, DOUBLE)) {
    eat(DOUBLE);
  }
  else if (equals(tokenActual, VOID)) {
    eat(VOID);
  }
}

void E(){
  if (equals(tokenActual, PIZQ)) {
    char* valor;
    eat(CIZQ);
    valor = tokenActual.valor;
    eat(NUM);
    eat(CDER);
    E();
  }
}

void F(){
  if (equals(tokenActual, ID)) {
    eat(ID);
    FP();
  }
}

void FP(){
  if (equals(tokenActual, COMA)) {
    eat(COMA);
    eat(ID);
    FP();
  }
}

void G() {
  if (equals(tokenActual, FUNC)) {
    eat(FUNC);
    eat(ID);
    eat(PIZQ);
    H();
    eat(PDER);
    J();
    G();
  }
}

void H() {
  I();
}

void I() {
  C();
  if (equals(tokenActual,ID))
  {
    eat(ID);
    IP();
  }
}

void IP() {
  if (equals(tokenActual, COMA))
  {
    eat(COMA);
    C();
    eat(ID);
    IP();
  }
}

void J() {
  eat(LKEY);
  B();
  K();
  eat(RKEY);
}

void K() {
  L();
  KP();
}

void KP() {
  if (equals(tokenActual,ID) || 
    equals(tokenActual,PIZQ) || 
    equals(tokenActual,IF) || 
    equals(tokenActual,WHILE) || 
    equals(tokenActual,DO) ||
    equals(tokenActual,BREAK) ||
    equals(tokenActual,LKEY) ||
    equals(tokenActual,SWITCH))
  {
    L();
    KP();
  }
}

void L() {
  if (equals(tokenActual, ID) || equals(tokenActual,PIZQ))
  {
    Z();
    eat(ASIG);
    P();
  }
  else if (equals(tokenActual, IF))
  {
    eat(IF);
    eat(PIZQ);
    P();
    eat(PDER);
    L();
    if (equals(tokenActual,ELSE))
    {
      eat(ELSE);
      L();
    }
  }
  else if (tokenActual,WHILE)
  {
    eat(WHILE);
    eat(PIZQ);
    P();
    eat(PDER);
    L();
  }
  else if (equals(tokenActual,DO))
  {
    eat(DO);
    L();
    eat(WHILE);
    eat(PIZQ);
    P();
    eat(PDER);
  }
  else if (equals(tokenActual,BREAK))
  {
    eat(BREAK);
    eat(PCOMA);
  }
  else if (equals(tokenActual,LKEY))
  {
    J();
  }
  else if (equals(tokenActual,SWITCH))
  {
    eat(SWITCH);
    eat(PIZQ);
    P();
    eat(PDER);
    eat(LKEY);
    M();
    eat(RKEY);
  }
}

void M() {
  if (equals(tokenActual,CASE))
  {
    N();
    M();
  }
  else if (tokenActual,DEFAULT)
  {
    O();
  }
}

void N() {
  eat(CASE);
  eat(NUM);
  eat(DDOT);
  K();
}

void O() {
  eat(DEFAULT);
  eat(DDOT);
  K();
}

void P() {
  Q();
  PP();
}

void PP() {
  if (equals(tokenActual,OR))
  {
    eat(OR);
    Q();
    PP();
  }
}

void Q() {
  R();
  QP();
}

void QP() {
  if(equals(tokenActual,AND)){
    eat(AND);
    R();
    QP();
  }
}

void R() {
  S();
  RP();
}

void RP() {
  if(equals(tokenActual,EQ))
  {
    eat(EQ);
    S();
    RP();
  }
  else if (equals(tokenActual,NEQ))
  {
    eat(NEQ);
    S();
    RP();
  }
}

void S() {
  T();
  switch(tokenActual->clase)
  {
    case LESS:
      eat(LESS);
      T();
      break;
    case LEQ:
      eat(LEQ);
      T();
      break;
    case GEQ:
      eat(GEQ);
      T();
      break;
    case GREATER:
      eat(GREATER);
      T();
      break;
  }
}

void T() {
  U();
  TP();
}

void TP() {
  if (equals(tokenActual,PLUS))
  {
    eat(PLUS);
    U();
    TP();
  }
  else if (tokenActual,MINUS)
  {
    eat(MINUS);
    U();
    TP();
  }
}

void U() {
  V();
  UP();
}

void UP() {
  if (equals(tokenActual,MULT))
  {
    eat(MULT);
    V();
    UP();
  }
  else if (tokenActual,DIV)
  {
    eat(DIV);
    V();
    UP();
  }
  else if(equals(tokenActual,MOD))
  {
    eat(MOD);
    V();
    UP();
  }
}

void V() {
  if (equals(tokenActual,MINUS))
  {
    eat(MINUS);
    V();
  }
  else if (equals(tokenActual,NOT))
  {
    eat(NOT);
    V();
  }
  else
  {
    W();
  }
}

void W() {
  switch(tokenActual->clase)
  {
    case PIZQ:
      eat(PIZQ);
      P();
      eat(PDER);
      break;
    case ID:
      eat(ID);
      if (equals(tokenActual,PIZQ))
      {
        eat(PIZQ);
        X();
        eat(PDER);
      }
      else if (equals(tokenActual,CIZQ))
      {
        ZP();
      }
      break;
    case NUM:
      eat(NUM);
      break;
    case STR:
      eat(STR);
      break;
    case TRUE: 
      eat(TRUE);
      break;
    case FALSE:
      eat(FALSE);
      break;
    default:
      error("Error de sintaxis");
      break;
  }
}

void X() {
  if (!equals(tokenActual,PDER))
  {
    Y();
  }
}

void Y() {
  P();
  YP();
}

void YP() {
  if (equals(tokenActual,COMA))
  {
    eat(COMA);
    P();
    YP();
  }
}

//Funcion que cae en desuso
void Z() {
  eat(id);
  ZP();
}

void ZP() {
  if (equals(tokenActual,CIZQ))
  {
    eat(CIZQ);
    P();
    eat(CDER);
    ZP();
  }
}

void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
