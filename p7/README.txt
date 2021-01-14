Instrucciones para compilación y ejecución
1. Hacer `make` desde el directorio src/
2. Ejecutar: ./parser prueba.in

Actividades
1. Adecuar el analizador lexico lexer.lex de acuerdo a la gramatica del proyecto final.
2. Completar lista.c
3. Completar parser.c (con descenso recursivo) por el momento haciendo caso omiso de las reglas semanticas.

Gramática:

programa = A
declaraciones = B
tipo = C
basico = D
compuesto = E
lista_var = F
funciones = G
argumentos = H
lista_args = I
bloque = J
instrucciones = K
sentencia = L
casos = M
caso = N
predeterminado = O
bool = P
comb = Q
igualdad = R
rel = S
exp = T
term = U
unario = V
factor = W
parametros = X
lista_param = Y
localizacion = Z

A -> B G
B -> C F ; B
  | eps
C -> D E
D -> int
  | float
  | char
  | double
  | void
E -> [ numero ] E
  | eps
F -> id F'
F' -> , id F' | eps
G -> func id ( H ) J G
  | eps
H -> I
  | eps
I -> C id I'
I' -> , C id I' | eps
J -> { B K }
K -> L K'
K' -> L K' | eps
L -> Z = P
  | if( P ) L
  | if( P ) L else L
  | while ( P ) L
  | do L while ( P )
  | break ;
  | J
  | switch( P ) { M }
M -> N M
  | eps
  | O
N -> case numero: K
O -> default: K
P -> Q P'
P' -> "||" Q P'
  | eps
Q -> R Q'
Q' -> && R Q'
  | eps
R -> S R'
R' -> == S R'
  | != S R'
  | eps
S -> T < T
  | T <= T
  | T >= T
  | T > T
  | T
T -> U T'
T' -> + U T'
  | - U T'
  | eps
U -> V U'
U' -> * V U'
  | / V U'
  | % V U'
  | eps
V -> ! V
  | - V
  | W
W -> (P)
  | Z
  | numero
  | cadena
  | true
  | false
  | id( X )
X -> Y
  | eps
Y -> P Y'
Y' -> , P Y'
  | eps
Z -> id Z'
Z' -> [ P ] Z' | eps

FIRST:

A -> B G
B -> C -> D -> int
        | float
        | char
        | double
        | void
  | eps
C -> D -> int
        | float
        | char
        | double
        | void
D -> int
  | float
  | char
  | double
  | void
E -> [
  | eps
F -> id
F' -> ,
  | eps
G -> func
  | eps
H -> I -> C -> D -> int
        | float
        | char
        | double
        | void
  | eps
I -> C -> D -> int
        | float
        | char
        | double
        | void
I' -> ,
  | eps
J -> {
K -> L -> Z -> id
      | if
      | while
      | do
      | break
      | J -> {
      | switch
K' -> L -> Z -> id
        | if
        | while
        | do
        | break
        | J -> {
        | switch
  | eps
L -> Z -> id
  | if
  | while
  | do
  | break
  | J -> {
  | switch
M -> N -> case
  | eps
  | O -> default
N -> case
O -> default
P -> Q -> R -> S -> T -> U -> V -> !
                    | -
                    | W -> (
                    | Z -> id
                    | numero
                    | cadena
                    | true
                    | false
                    | id
P' -> "||"
  | eps
Q -> R -> S -> T -> U -> V -> !
                | -
                | W -> (
                | Z -> id
                | numero
                | cadena
                | true
                | false
                | id
Q' -> &&
  | eps
R -> S -> T -> U -> V -> !
            | -
            | W -> (
            | Z -> id
            | numero
            | cadena
            | true
            | false
            | id
R' -> ==
  | !=
  | eps
S -> T -> U -> V -> !
        | -
        | W -> (
        | Z -> id
        | numero
        | cadena
        | true
        | false
        | id
T -> U -> V -> !
    | -
    | W -> (
    | Z -> id
    | numero
    | cadena
    | true
    | false
    | id
T' -> +
  | -
  | eps
U -> V -> !
  | -
  | W -> (
    | Z -> id
    | numero
    | cadena
    | true
    | false
    | id
U' -> *
  | /
  | %
  | eps
V -> !
  | -
  | W -> (
    | Z -> id
    | numero
    | cadena
    | true
    | false
    | id
W -> (
  | Z -> id
  | numero
  | cadena
  | true
  | false
  | id
X -> Y -> P -> Q -> R -> S -> T -> U -> V -> !
                            | -
                            | W -> (
                            | Z -> id
                            | numero
                            | cadena
                            | true
                            | false
                            | id
  | eps
Y -> P -> Q -> R -> S -> T -> U -> V -> !
                        | -
                        | W -> (
                        | Z -> id
                        | numero
                        | cadena
                        | true
                        | false
                        | id
Y' -> ,
  | eps
Z -> id
Z' -> [
  | eps
