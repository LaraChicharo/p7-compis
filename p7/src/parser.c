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
  D();
  //imprimir TS y TT
}

void D() {
  if(equals(tokenActual, FIN)) {
    puts("Fin de análisis sintáctico.");
    return;
  }
  //implementa
}

int T() {
  //implementa
  return 0; //cambiar
}

int B() {
  //implementa
  return 0;
}

int C (int base) { 
  //implementa
  return 0; 
}

void L(int tipo) {
  //implementa
}

void LP(int tipo) {
  //implementa
}



void error(char *msg) {
  printf(msg);
  printf(": línea %i\n", yylineno);
  exit(1);
}
