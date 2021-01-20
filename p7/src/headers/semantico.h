#ifndef SEMANTICO_H
#define SEMANTICO_H

#include "codigoint.h"

typedef struct semantico {
  CodigoInt codigo;
} semantico;

int maximo(int tipo1, int tipo2);

char* ampliar(char* dir, int menor, int mayor);

char* reducir(char* dir, int mayor, int menor);

char* nuevaTemporal();

char* nuevaEtiqueta();

int equivalentes(int tipo1, int tipo2);
