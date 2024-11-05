#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
    #include <SDL_main.h>
#endif

#include <SDL.h>

#define TAM_PANTALLA_H 800
#define TAM_PANTALLA_V 700

#define WIDTH 160
#define HEIGHT 90

#define TAM_CUADROS 5

#define SIN_MEMO -2
#define ERROR_ARGUMENTOS -1
#define ARGUMENTOS_ERRONEOS -9
#define ERROR_ARCH -3
#define TODO_OK 0

#define MURIENDO 2
#define NACIENDO 3
#define VIVO 1
#define MUERTO 0

#endif // CONSTANTS_H_INCLUDED
