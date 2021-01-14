#ifndef TOKENS_H
#define TOKENS_H
#define COMA 1001 // , 
#define PCOMA 1002 // ;
#define CIZQ 1003 // [
#define CDER 1004 // ]
#define INT 1005 // int 
#define FLOAT 1006 // float 
#define NUM 1007 // double 
#define ID 1008 // id 

#define PIZQ 1009 // ()
#define PDER 1010 // )
#define CHAR 1011 // char 
#define DOUBLE 1012  // double
#define VOID 1013 // void 
#define IF 1014 // if 
#define ELSE 1015 // else 
#define DO 1016 // do 
#define WHILE 1017 // while 
#define BREAK 1018 // break 
#define SWITCH 1019 // switch 
#define DEFAULT 1020 // default 
#define CASE 1021 // case 

#define AND 1022 // &&
#define EQ 1023 // ==
#define NEQ 1024 // !=
#define LESS 1025 // <
#define LEQ 1026 // <=
#define GEQ 1027 // >=
#define GREATER 1028 // >
#define PLUS 1029 // +
#define MINUS 1030 // -
#define MULT 1031 // *
#define DIV 1032 // /
#define MOD 1033 // %
#define NOT 1034 // ! 


#define STR 1035 // cadena
#define DDOT 1036 // :
#define ASIG 1037 // =
#define NUM 1038 // numero
#define OR 1039 // || 
#define LKEY 1040 // {
#define RKEY 1041 // }

#define TRUE 1042
#define FALSE 1043

#define FIN 9001 // $ 
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



