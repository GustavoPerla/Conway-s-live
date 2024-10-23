#include "precargas.h"

int cargarDeArch(int8_t** mat,char* nomArch,const int x,const int y){
    FILE* arch=fopen(nomArch,"rt");
    if(arch==NULL)
        return ERROR_ARCH;

    int f,c;
    while(fscanf(arch,"%d;%d",&f,&c)==2){
        mat[x+f][y+c]=VIVO;
    }
    fclose(arch);
    return TODO_OK;
}

void cargarOscilador(int8_t** matriz, int i, int j) {

    matriz[i-1][j-3] = VIVO;
    matriz[i][j-3] = VIVO;
    matriz[i+1][j-3] = VIVO;

    matriz[i-1][j+3] = VIVO;
    matriz[i][j+3] = VIVO;
    matriz[i+1][j+3] = VIVO;

    matriz[i-3][j+1] = VIVO;
    matriz[i-3][j] = VIVO;
    matriz[i-3][j-1] = VIVO;

    matriz[i+3][j+1] = VIVO;
    matriz[i+3][j] = VIVO;
    matriz[i+3][j-1] = VIVO;
}

void cargarOscilador2(int8_t** matriz, int i, int j) {

    matriz[j-4][i-4] = VIVO;
    matriz[j-4][i-3] = VIVO;
    matriz[j-4][i-2] = VIVO;
    matriz[j-4][i-1] = VIVO;
    matriz[j-4][i] = VIVO;
    matriz[j-4][i+1] = VIVO;

    matriz[j-3][i-4] = VIVO;
    matriz[j-3][i-3] = VIVO;
    matriz[j-3][i-2] = VIVO;
    matriz[j-3][i-1] = VIVO;
    matriz[j-3][i] = VIVO;
    matriz[j-3][i+1] = VIVO;

    matriz[j+4][i+4] = VIVO;
    matriz[j+4][i+3] = VIVO;
    matriz[j+4][i+2] = VIVO;
    matriz[j+4][i+1] = VIVO;
    matriz[j+4][i] = VIVO;
    matriz[j+4][i-1] = VIVO;

    matriz[j+3][i+4] = VIVO;
    matriz[j+3][i+3] = VIVO;
    matriz[j+3][i+2] = VIVO;
    matriz[j+3] [i+1]= VIVO;
    matriz[j+3][i] = VIVO;
    matriz[j+3][i-1] = VIVO;

    matriz[j-1][i-4] = VIVO;
    matriz[j][i-4] = VIVO;
    matriz[j+1][i-4] = VIVO;
    matriz[j+2][i-4] = VIVO;
    matriz[j+3][i-4] = VIVO;
    matriz[j+4][i-4] = VIVO;

    matriz[j-1][i-3] = VIVO;
    matriz[j][i-3] = VIVO;
    matriz[j+1][i-3] = VIVO;
    matriz[j+2][i-3] = VIVO;
    matriz[j+3][i-3] = VIVO;
    matriz[j+4][i-3] = VIVO;

    matriz[j-4][i+4] = VIVO;
    matriz[j-3][i+4] = VIVO;
    matriz[j-2][i+4] = VIVO;
    matriz[j-1][i+4] = VIVO;
    matriz[j][i+4] = VIVO;
    matriz[j+1][i+4] = VIVO;

    matriz[j-4][i+3] = VIVO;
    matriz[j-3][i+3] = VIVO;
    matriz[j-2][i+3] = VIVO;
    matriz[j-1][i+3] = VIVO;
    matriz[j][i+3] = VIVO;
    matriz[j+1][i+3] = VIVO;
}

void cargarShip(int8_t** matriz, int i, int j){
    matriz[i][j+1] = VIVO;
    matriz[i+1][j+2] = VIVO;
    matriz[i+2][j] = VIVO;
    matriz[i+2][j+1] = VIVO;
    matriz[i+2][j+2] = VIVO;
}

void cargarGenShip(int8_t** matriz, int j, int i){
    matriz[i][j+4] = VIVO;
    matriz[i+1][j+4] = VIVO;
    matriz[i][j+5] = VIVO;
    matriz[i+1][j+5] = VIVO;

    matriz[i+10][j+4] = VIVO;
    matriz[i+10][j+5] = VIVO;
    matriz[i+10][j+6] = VIVO;

    matriz[i+11][j+3] = VIVO;
    matriz[i+11][j+7] = VIVO;

    matriz[i+12][j+2] = VIVO;
    matriz[i+12][j+8] = VIVO;
    matriz[i+13][j+2] = VIVO;
    matriz[i+13][j+8] = VIVO;

    matriz[i+14][j+5] = VIVO;

    matriz[i+15][j+3] = VIVO;
    matriz[i+15][j+7] = VIVO;

    matriz[i+16][j+4] = VIVO;
    matriz[i+16][j+5] = VIVO;
    matriz[i+16][j+6] = VIVO;

    matriz[i+17][j+5] = VIVO;

    matriz[i+20][j+2] = VIVO;
    matriz[i+20][j+3] = VIVO;
    matriz[i+20][j+4] = VIVO;

    matriz[i+21][j+2] = VIVO;
    matriz[i+21][j+3] = VIVO;
    matriz[i+21][j+4] = VIVO;

    matriz[i+22][j+1] = VIVO;
    matriz[i+22][j+5] = VIVO;

    matriz[i+24][j+0] = VIVO;
    matriz[i+24][j+1] = VIVO;
    matriz[i+24][j+5] = VIVO;
    matriz[i+24][j+6] = VIVO;

    matriz[i+34][j+2] = VIVO;
    matriz[i+35][j+2] = VIVO;
    matriz[i+34][j+3] = VIVO;
    matriz[i+34][j+3] = VIVO;
}
