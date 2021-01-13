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
 * Función para paso de prueba y empate del No-terminal P
 */
void P();

/**
 * Función para paso de prueba y empate del No-terminal D
 */
void D();

/**
 * Función para paso de prueba y empate del No-terminal T
 */
void T();

/**
 * Función para prueba y empate del No-terminal B
 */
void B();

/**
* Función para prueba y empate del No-terminal C
*/
void C();

/**
 * Función para prueba y empate del No-terminal L
 */
void L();

/**
 * Función para prueba y empate del No-terminal LP (L prima)
 */
void LP();

/**
 * Función para prueba y empate del No-terminal S
 */
void S();

/**
 * Función para prueba y empate del No-terminal E
 */
void E();

/**
 * Función para prueba y empate del No-terminal EP (E prima)
 */
void EP();

/**
 * Función para prueba y empate del No-terminal U
 */
void U();

/**
 * Función para prueba y empate del No-terminal UP (U prima)
 */
void UP();

/**
 * Función para prueba y empate del No-terminal F
 */
void F();


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
