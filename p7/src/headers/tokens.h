#ifndef TOKENS_H
#define TOKENS_H
#define COMA 1001
#define PCOMA 1002
#define CIZQ 1003
#define CDER 1004
#define INT 1005
#define FLOAT 1006
#define NUM 1007
#define ID 1008

#define PIZQ 1009
#define PDER 1010
#define CHAR 1011
#define DOUBLE 1012
#define VOID 1013
#define IF 1014
#define ELSE 1015
#define DO 1016
#define WHILE 1017
#define BREAK 1018
#define SWITCH 1019
#define DEFAULT 1020

#define AND 1021
#define EQ 1022
#define NEQ 1023
#define LESS 1024
#define LEQ 1025
#define GEQ 1026
#define GREATER 1027
#define PLUS 1028
#define MINUS 1029
#define MULT 1030
#define DIV 1031
#define MOD 1032
#define FACT 1033

#define STR 1034


#define FIN 9001
/* 
 * podemos definir más o cambiar las definiciones 
 * siempre y cuando actualicemos el lexer 
 */
#endif

#include <string.h>
#include <stdlib.h>


/**
 * Estructura para modelar tokens (componentes léxicos)
 */
typedef struct token {
  int clase; //léxica
  char *valor; //lexema
  int tipo; //para diferenciar entre diferentes lexemas de una misma clase léxica
} token;

/**
 * Inicialización de tokens sin tipo
 */
token *crea_token(int clase, char *valor);

/**
 * Inicialización de tokens con tipo
 */
token *crea_token_tipo(int clase, char *valor, int tipo);

/**
 * Verificación de token perteneciente a una clase léxica
 */
int equals(token *t1, int clase);

/**
 * Liberación de memoria de un token
 */
void libera(token *t);



