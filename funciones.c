#include "constants.h"

int cuentaVecinos(int8_t** matriz, int i, int j){
    int f, c, cont = 0;
    for (f = i - 1; f <= i + 1; f++)
        for (c = j - 1; c <= j + 1; c++)
            if (f >= 0 && f < WIDTH && c >= 0 && c < HEIGHT)
                if (!(f == i && c == j))
                    if (matriz[f][c] == VIVO || matriz[f][c] == MURIENDO)
                        cont++;

    return cont;
}

void calculaSiguiente(int8_t** matriz){
    int i, j;
    for (i = 0; i < WIDTH; i++)
        for (j = 0; j < HEIGHT; j++) {
            int cont = cuentaVecinos(matriz, i, j);
            if (matriz[i][j] == MUERTO && cont == NACIENDO)
                matriz[i][j] = NACIENDO;
            if (matriz[i][j] == VIVO && (cont < MURIENDO || cont > NACIENDO))
                matriz[i][j] = MURIENDO;
        }
    return;
}

void aplicaSiguiente(int8_t** matriz){
    int i, j;
    for (i = 0; i < WIDTH; i++)
        for (j = 0; j < HEIGHT; j++) {
            if (matriz[i][j] == MURIENDO) matriz[i][j] = MUERTO;
            if (matriz[i][j] == NACIENDO) matriz[i][j] = VIVO;
        }
    return;
}
