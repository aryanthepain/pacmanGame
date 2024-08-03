//author:Aryanthepain
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "globals.h"
#include "init.h"
#include "loadMedia.h"
#include "close.h"
using namespace std;

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            cout << "Failed to load media!" << endl;
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            
            //Update the surface
            SDL_UpdateWindowSurface( gWindow );
            
            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
