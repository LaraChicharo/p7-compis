#ifndef CODIGOINT_H
#define CODIGOINT_H

typedef struct cuadrupla {
  char* op;
  char* arg1;
  char* arg2;
  char* res;
} cuadrupla;

typedef struct CodigoInt {
  Lista *codigo;
} cuadrupla;

void genCod(cuadrupla c);

void mostrar();

void imprimir(char* fileName);
