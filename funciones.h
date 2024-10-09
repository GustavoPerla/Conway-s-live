#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "constants.h"

int cuentaVecinos(int8_t** matriz, int i, int j,const size_t fila,const size_t col);

void calculaSiguiente(int8_t** matriz,const size_t fila,const size_t col);

void aplicaSiguiente(int8_t** matriz,const size_t fila,const size_t col);

#endif // FUNCIONES_H_INCLUDED
