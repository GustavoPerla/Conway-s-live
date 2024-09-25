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

#define WIDTH 160
#define HEIGHT 90

#define SIN_MEMO -2

#define MURIENDO 2
#define NACIENDO 3
#define VIVO 1
#define MUERTO 0

#endif // CONSTANTS_H_INCLUDED