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
  P();
  //imprimir TS y TT
}

void P() {
  D();
  S();
  if(equals(tokenActual, FIN)) {
    puts("Fin de análisis sintáctico.");
    return;
  }
}

void D(){
  if(equals(tokenActual, INT) || equals(token
  , FLOAT)) {
    T();
    L();
    eat(PCOMA);
    D();
  }
}

void T(){
  B();
  C();
}

void B(){
  if (equals(tokenActual, INT)) {
    eat(INT);
  }
  else if (equals(tokenActual, FLOAT)) {
    eat(FLOAT);
  }
}

void C(){
  if (equals(tokenActual, CIZQ)) {
    char* valor;
    eat(CIZQ);
    valor = tokenActual.valor;
    eat(NUM);
    eat(CDER);
    C();
  }
}

void L(){
  if (equals(tokenActual, ID)) {
    eat(ID);
    LP();
  }
}

void LP(){
  if (equals(tokenActual, COMA)) {
    eat(COMA);
    eat(ID);
    LP();
  }
}

void S(){
  if (equals(tokenActual, ID)) {
    eat(ID);
    eat(EQ);
    E();
    eat(PCOMA);
  }
  // duda con
  // S -> id = E; S | id = E;
}

void E(){
  U();
  EP();
}

void EP(){
  if (equals(tokenActual, PLUS)) {
    eat(PLUS);
    U();
    EP();
  }
  else if (equals(tokenActual, MINUS)) {
    eat(MINUS);
    U();
    EP();
  }
}

void U(){
  F();
  UP();
}

void UP(){
  if (equals(tokenActual, MULT)) {
    eat(MULT);
    F();
    UP();
  }
  else if (equals(tokenActual, DIV)) {
    eat(DIV);
    F();
    UP();
  }
  else if (equals(tokenActual, MOD)) {
    eat(MOD);
    F();
    UP();
  }
}

void F(){
  if (equals(tokenActual, PIZQ)) {
    eat(PIZQ);
    E();
    eat(PDER);
  }
  else if (equals(tokenActual, ID)) {
    eat(ID);
  }
  else if (equals(tokenActual, NUM)) {
    eat(NUM);
  }
}

void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
