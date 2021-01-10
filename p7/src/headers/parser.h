#include "tokens.h"
#include "lista.h"

/* Token actual en la lectura */
token *tokenActual;
/* Dirección disponible en la TT */
int dir;
/* Tabla de símbolos */
Lista *tablaSimbolos;
/* Tabla de tipos */
Lista *tablaTipos;

/**
 * Función para paso de prueba y empate del No-terminal D
 */
void D();

/**
 * Función para paso de prueba y empate del No-terminal T
 */
int T();

/**
 * Función para prueba y empate del No-terminal B
 */
int B();

/**
 * Función para prueba y empate del No-terminal C
 */
int C(int base);

/**
 * Función para prueba y empate del No-terminal L
 */
void L(int tipo);

/**
 * Función para prueba y empate del No-terminal LP (L prima)
 */
void LP(int tipo);


/**
 * Función para consumo de componente léxico actual al hacer empate
 */
void eat(int clase);

/**
 * Función principal de análisis sintáctico. 
 * Debe llamar a función de símbolo inicial de la gramática.
 * También inicializar las tablas de símbolos y tipos.
 */
void parse();

/**
 * Función para reporte de errores sintácticos y semánticos.
 */
void error(char *msg);

/**
 * (opcional) Función para buscar símbolos en la tabla de símbolos
 */
int buscar(char *simbolo);

/**
 * Obtener tamaño de elemento de la tabla de tipos
 */
int getTam(int id);

/**
 * Función para imprimir Tabla de tipos
 */
void printTT(Lista *TT);

/**
 * Función para imprimir Tabla de símbolos
 */
void printTS(Lista *TS);


