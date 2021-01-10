%{
  #include <stdio.h>
  #include "tokens.h"
  #define YY_DECL token *yylex(void)
%}

%option noyywrap
%option yylineno

num_ent [0-9]+
num_float [0-9]*"."[0-9]+
id [a-zA-Z][a-zA-Z0-9]*
whitespace [ \t\n]

%%

"," { ECHO; return crea_token(COMA, ""); }
";" { ECHO; return crea_token(PCOMA, ""); }
"[" { ECHO; return crea_token(CIZQ, ""); }
"]" { ECHO; return crea_token(CDER, ""); } 
"int" { ECHO; return crea_token(INT, ""); }
"float" { ECHO; return crea_token(FLOAT, "");}
{num_ent} { ECHO; return crea_token_tipo(NUM, yytext, 0); }
{num_float} { ECHO; return crea_token_tipo(NUM, yytext, 1); }
{id} { ECHO; return crea_token(ID, yytext); }
{whitespace} { ECHO; }
<<EOF>> { puts("Fin de análisis léxico."); return crea_token(FIN, ""); }
. { printf("Error léxico en la linea: %i\n", yylineno); exit(1); }

%%


