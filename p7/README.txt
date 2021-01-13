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
E -> ( numero ) E
  | eps
F -> F , id
  | id
G -> func id ( H ) J G
  | eps
H -> I
  | eps
I -> I, C id
  | C id
J -> { B K }
K -> K L
  | L
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
P -> P "||" Q
  | Q
Q -> Q && R
  | R
R -> R == S
  | R != S
  | S

S -> T < T
  | T <= T
  | T >= T
  | T > T
  | T
T -> T + U
  | T - U
  | U
U -> U * V
  | U / V
  | U % V
  | V
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
Y -> Y , P
  | P
Z -> Z ( P )
  | id
