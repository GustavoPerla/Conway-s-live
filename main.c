#include "constants.h"
#include "precargas.h"
#include "funciones.h"
#include "matriz.h"
#include <stdbool.h>

void drawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int y = -radius; y <= radius; y++)
        for (int x = -radius; x <= radius; x++)
            if (x*x + y*y <= radius*radius)
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
}

int main(int argc, char *argv[]) {
    bool done=1;
    int** MCelulas = crearMat(WIDTH,HEIGHT);
    if(!MCelulas)
        return SIN_MEMO;
    cargarCeros(MCelulas,WIDTH,HEIGHT);
    int k = 0, skip = 0, delay = 100;

    if(argc > 1)
        sscanf(argv[1], "%d", &delay);
    if(argc > 2)
        sscanf(argv[2], "%d", &skip);

    SDL_Window* window      = NULL;
    SDL_Renderer* renderer  = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    cargarGenShip(MCelulas, 0, 0);
    cargarOscilador2(MCelulas, 40, 20);
    cargarOscilador2(MCelulas, 40, 35);
    cargarOscilador2(MCelulas, 40, 50);
    cargarOscilador2(MCelulas, 40, 65);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Juego de la vida",
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                WIDTH*10,
                                                HEIGHT*10,
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

        for(i = 0; i<WIDTH; i++)
            for(j = 0; j<HEIGHT; j++)
                if(MCelulas[i][j]==1) {

                    fillRect.x = (i*10);
                    fillRect.y = (j*10);
                    fillRect.h = 10;
                    fillRect.w = 10;

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

        calculaSiguiente(MCelulas);
        aplicaSiguiente(MCelulas);
    }
    eliminarMat(MCelulas,WIDTH);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


