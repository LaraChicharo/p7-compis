#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stack>
#include <vector>
#include <string>
#include "simbolo.h"

    using namespace std;

    struct simbolo{
        string id;
        int tipo;
        int dir;
        int var;
        vector<int> args;
    };

    struct tabla_simbolos{
        vector<simbolo> tabla;    
    public:
        bool buscar(string id);
        bool insertar(simbolo s);
        int getTipo(string id);
    };



    struct pila_simbolos{
        stack<tabla_simbolos> pila;
    public:
        void push() ;
        void pop();
        tabla_simbolos top();
    };



#ifdef __cplusplus
}
#endif

#endif
