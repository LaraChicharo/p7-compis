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



