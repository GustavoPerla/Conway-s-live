#include "constants.h"
#include "precargas.h"
#include "funciones.h"
#include "matriz.h"
#include <stdbool.h>
#include <stdint.h>

void drawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int y = -radius; y <= radius; y++)
        for (int x = -radius; x <= radius; x++)
            if (x*x + y*y <= radius*radius)
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
}

int main(int argc, char *argv[]) {
    bool done=1;
    int k = 0, skip = 0, delay = 100,fila,col;

    if(argc==1){
        fila=WIDTH;
        col=HEIGHT;
    }else
        if(argc==6){
            sscanf(argv[1], "%d", &fila);
            sscanf(argv[2], "%d", &col);
            sscanf(argv[3], "%d", &delay);
            sscanf(argv[4], "%d", &skip);
        }else
            return ERROR_ARGUMENTOS;

    if(fila<1 || col<1)
        return ARGUMENTOS_ERRONEOS;

    int8_t** MCelulas = crearMat(fila,col);
    if(!MCelulas)
        return SIN_MEMO;
    cargarCeros(MCelulas,fila,col);

    SDL_Window* window      = NULL;
    SDL_Renderer* renderer  = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    if(argc==6){
        cargarDeArch(MCelulas,argv[5],50,50);
//        cargarDeArch(MCelulas,argv[5],75,50);
//        cargarDeArch(MCelulas,argv[5],50,75);
//        cargarDeArch(MCelulas,argv[5],75,75);
//        cargarDeArch(MCelulas,argv[5],75,100);
//        cargarDeArch(MCelulas,argv[5],100,100);
//        cargarDeArch(MCelulas,argv[5],50,100);
//        cargarDeArch(MCelulas,argv[5],100,50);
//        cargarDeArch(MCelulas,argv[5],100,75);
    }
//    cargarGenShip(MCelulas, 0, 0);
//    cargarOscilador2(MCelulas, 40, 20);
//    cargarOscilador2(MCelulas, 40, 35);
//    cargarOscilador2(MCelulas, 40, 50);
//    cargarOscilador2(MCelulas, 40, 65);
//    cargarOscilador2(MCelulas, 80, 80);
//    cargarOscilador2(MCelulas, 100, 100);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Juego de la vida",
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                TAM_PANTALLA_H,
                                                TAM_PANTALLA_V,
                                                SDL_WINDOW_SHOWN);
    if (!window){
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    while (done) {
        int i=0, j=0;
        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                done = 0;

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        for(i = 0; i<fila; i++)
            for(j = 0; j<col; j++)
                if(MCelulas[i][j]==VIVO) {

                    fillRect.x = (i*TAM_CUADROS);
                    fillRect.y = (j*TAM_CUADROS);
                    fillRect.h = TAM_CUADROS;
                    fillRect.w = TAM_CUADROS;

                    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                }

        SDL_RenderPresent(renderer);
        k++;

        char aux[40] = "";

        sprintf(aux, "Conway's Game of Life. Cycles: %d", k);
        SDL_SetWindowTitle(window, aux);
        if(skip<k)
            SDL_Delay(delay);

        calculaSiguiente(MCelulas,fila,col);
        aplicaSiguiente(MCelulas,fila,col);
    }
    eliminarMat(MCelulas,fila);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


