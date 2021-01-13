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
    valor = tokenActual.valor();
    eat(NUM);
    eat(CDER);
    C();
  }
}

void L(){

}

void LP(){

}

void S(){

}

void E(){

}

void EP(){

}

void U(){

}

void UP(){

}

void F(){

}

void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
