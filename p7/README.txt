Instrucciones para compilación y ejecución
1. Hacer `make` desde el directorio src/
2. Ejecutar: ./parser prueba.in

Actividades
1. Adecuar el analizador lexico lexer.lex de acuerdo a la gramatica del proyecto final.
2. Completar lista.c
3. Completar parser.c (con descenso recursivo) por el momento haciendo caso omiso de las reglas semanticas.

Gramática:

P -> D S
D -> T L ; D | eps
T -> B C
C -> [num] C | eps
B -> int | float
L -> L, id | id
S -> id = E; S | id = E;
E -> E + U | E - U | U
U -> U * F | U / F | U % F | F
F -> (E) | id | num

Eliminando recursividad izquierda:

P -> D S
D -> T L ; D | eps
T -> B C
C -> [num] C | eps
B -> int | float
L -> id L'
L' -> , id L' | eps
S -> id = E; S | id = E;
E -> U E'
E' -> + U E' | - U E' | eps
U -> F U'
U' -> * F U' | / F U' | % F U' | eps
F -> (E) | id | num
