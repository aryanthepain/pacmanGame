//author:Aryanthepain
#include <SDL2/SDL.h>
#include "loadMedia.h"
#include "globals.h"


bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "sample_640×426.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "sample_640×426.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

