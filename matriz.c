#include <stdlib.h>
#include <stdint.h>
#define forsn(i,s,n) for(int i=(s);i<(n);i++)
#define forn(i,n) forsn(i,0,n)

#define CEROS 0

void eliminarMat(int8_t** mat,size_t fil){
    int8_t** ult= mat+fil-1;
    for(int8_t** i=mat; i<=ult;i++)
        free(*i);
    free(mat);
}

int8_t** crearMat(size_t fila,size_t col){
    int8_t** mat=malloc(fila*sizeof(int8_t*));
    if(!mat)
        return NULL;

    int8_t** ult= mat+fila;

    for(int8_t** i=mat;i<=ult;i++){
        *i=malloc(col*sizeof(int8_t));
        if(!*i){
            eliminarMat(mat,i-mat);
            return NULL;
        }
    }
    return mat;
}

void cargarCeros(int8_t** mat,size_t fil,size_t col){
    forn(i,fil)
        forn(j,col)
            mat[i][j]=CEROS;
}
