#include "lista.h"
#include "tokens.h"

/**
 * Estructura para modelar símbolos de la TS
 */
typedef struct simbolo {
  int tipo;
  int dir; //dirección
  string id; //identificador
  int var; 
  Lista *args; //argumentos
} simbolo ;

/**
 * Inicialización de símbolos
 */
simbolo *crea_simbolo(string id, int dir, int type, int var, Lista *args);
