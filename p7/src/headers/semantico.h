#ifndef SEMANTICO_H
#define SEMANTICO_H

#include <string>
#include "codigoint.h"
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

    struct semantico{
        CodigoInt codigo;
    public:
        int maximo(int tipo1, int tipo2);
        string ampliar(string dir, int menor, int mayor);
        string reducir(string dir, int mayor, int menor);
        string nuevaTemporal();
        string nuevaEtiquta();
        bool equivalentes(int tipo1, int tipo2);
    };

#ifdef __cplusplus
}
#endif

#endif
