#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

int8_t** crearMat(size_t fila,size_t col);
void eliminarMat(int8_t** mat,size_t fil);
void cargarCeros(int8_t** mat,size_t fil,size_t col);

#endif // MATRIZ_H_INCLUDED
