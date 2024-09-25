#include "precargas.h"

void cargarOscilador(int** matriz, int i, int j) {

    matriz[i-1][j-3] = 1;
    matriz[i][j-3] = 1;
    matriz[i+1][j-3] = 1;

    matriz[i-1][j+3] = 1;
    matriz[i][j+3] = 1;
    matriz[i+1][j+3] = 1;

    matriz[i-3][j+1] = 1;
    matriz[i-3][j] = 1;
    matriz[i-3][j-1] = 1;

    matriz[i+3][j+1] = 1;
    matriz[i+3][j] = 1;
    matriz[i+3][j-1] = 1;
    return;
}

void cargarOscilador2(int** matriz, int i, int j) {

    matriz[j-4][i-4] = 1;
    matriz[j-4][i-3] = 1;
    matriz[j-4][i-2] = 1;
    matriz[j-4][i-1] = 1;
    matriz[j-4][i] = 1;
    matriz[j-4][i+1] = 1;

    matriz[j-3][i-4] = 1;
    matriz[j-3][i-3] = 1;
    matriz[j-3][i-2] = 1;
    matriz[j-3][i-1] = 1;
    matriz[j-3][i] = 1;
    matriz[j-3][i+1] = 1;

    matriz[j+4][i+4] = 1;
    matriz[j+4][i+3] = 1;
    matriz[j+4][i+2] = 1;
    matriz[j+4][i+1] = 1;
    matriz[j+4][i] = 1;
    matriz[j+4][i-1] = 1;

    matriz[j+3][i+4] = 1;
    matriz[j+3][i+3] = 1;
    matriz[j+3][i+2] = 1;
    matriz[j+3] [i+1]= 1;
    matriz[j+3][i] = 1;
    matriz[j+3][i-1] = 1;

    matriz[j-1][i-4] = 1;
    matriz[j][i-4] = 1;
    matriz[j+1][i-4] = 1;
    matriz[j+2][i-4] = 1;
    matriz[j+3][i-4] = 1;
    matriz[j+4][i-4] = 1;

    matriz[j-1][i-3] = 1;
    matriz[j][i-3] = 1;
    matriz[j+1][i-3] = 1;
    matriz[j+2][i-3] = 1;
    matriz[j+3][i-3] = 1;
    matriz[j+4][i-3] = 1;

    matriz[j-4][i+4] = 1;
    matriz[j-3][i+4] = 1;
    matriz[j-2][i+4] = 1;
    matriz[j-1][i+4] = 1;
    matriz[j][i+4] = 1;
    matriz[j+1][i+4] = 1;

    matriz[j-4][i+3] = 1;
    matriz[j-3][i+3] = 1;
    matriz[j-2][i+3] = 1;
    matriz[j-1][i+3] = 1;
    matriz[j][i+3] = 1;
    matriz[j+1][i+3] = 1;
    return;
}

void cargarShip(int** matriz, int i, int j){
    matriz[i][j+1] = 1;
    matriz[i+1][j+2] = 1;
    matriz[i+2][j] = 1;
    matriz[i+2][j+1] = 1;
    matriz[i+2][j+2] = 1;
}

void cargarGenShip(int** matriz, int j, int i){
    matriz[i][j+4] = 1;
    matriz[i+1][j+4] = 1;
    matriz[i][j+5] = 1;
    matriz[i+1][j+5] = 1;

    matriz[i+10][j+4] = 1;
    matriz[i+10][j+5] = 1;
    matriz[i+10][j+6] = 1;

    matriz[i+11][j+3] = 1;
    matriz[i+11][j+7] = 1;

    matriz[i+12][j+2] = 1;
    matriz[i+12][j+8] = 1;
    matriz[i+13][j+2] = 1;
    matriz[i+13][j+8] = 1;

    matriz[i+14][j+5] = 1;

    matriz[i+15][j+3] = 1;
    matriz[i+15][j+7] = 1;

    matriz[i+16][j+4] = 1;
    matriz[i+16][j+5] = 1;
    matriz[i+16][j+6] = 1;

    matriz[i+17][j+5] = 1;

    matriz[i+20][j+2] = 1;
    matriz[i+20][j+3] = 1;
    matriz[i+20][j+4] = 1;

    matriz[i+21][j+2] = 1;
    matriz[i+21][j+3] = 1;
    matriz[i+21][j+4] = 1;

    matriz[i+22][j+1] = 1;
    matriz[i+22][j+5] = 1;

    matriz[i+24][j+0] = 1;
    matriz[i+24][j+1] = 1;
    matriz[i+24][j+5] = 1;
    matriz[i+24][j+6] = 1;

    matriz[i+34][j+2] = 1;
    matriz[i+35][j+2] = 1;
    matriz[i+34][j+3] = 1;
    matriz[i+34][j+3] = 1;
}
