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
    eat(PIZQ);
    valor = tokenActual.valor;
    eat(NUM);
    eat(PDER);
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
  
}

void I() {

}

void IP() {

}

void J() {

}

void K() {

}

void KP() {

}

void L() {

}

void M() {

}

void N() {

}

void O() {

}

void P() {

}

void PP() {

}

void Q() {

}

void QP() {

}

void R() {

}

void RP() {

}

void S() {

}

void T() {

}

void TP() {

}

void U() {

}

void UP() {

}

void V() {

}

void W() {

}

void X() {

}

void Y() {

}

void YP() {

}

void Z() {

}

void ZP() {

}

void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
