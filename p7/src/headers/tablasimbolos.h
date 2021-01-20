#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "simbolo.h"
/**
 * Estructura para modelar la tabla de simbolos
 */
typedef struct tabla_simbolos {
  Lista *tabla;
} tabla_simbolos;

int buscar(char* id);

int insertar(simbolo s);

int getTipo(char* id);

typedef struct pila_simbolos {
  Lista *pila;
} pila_simbolos;

void push();

void pop();

tabla_simbolos top();
