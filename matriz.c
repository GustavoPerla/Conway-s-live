#include <stdlib.h>

#define forsn(i,s,n) for(int i=(s);i<(n);i++)
#define forn(i,n) forsn(i,0,n)

void eliminarMat(int** mat,size_t fil){
    int** ult= mat+fil-1;
    for(int** i=mat; i<=ult;i++)
        free(*i);
    free(mat);
}

int** crearMat(size_t fila,size_t col){
    int** mat=malloc(fila*sizeof(int*));
    if(!mat)
        return NULL;

    int** ult= mat+fila;

    for(int** i=mat;i<=ult;i++){
        *i=malloc(col*sizeof(int));
        if(!*i){
            eliminarMat(mat,i-mat);
            return NULL;
        }
    }
    return mat;
}

void cargarCeros(int** mat,size_t fil,size_t col){
    forn(i,fil)
        forn(j,col)
            mat[i][j]=0;
}
