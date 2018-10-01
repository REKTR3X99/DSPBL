#include "headers/Initialize.h"
#include <SDL2/SDL.h>

static SDL_Window *window = NULL;

void CreateWindow(void)
{


       SDL_Init(SDL_INIT_EVERYTHING);//Initializing SDL

        // Create window
        window = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            640,                               // width, in pixels
            480,                               // height, in pixels
            SDL_WINDOW_OPENGL                  //flag
        );

        //Chec kif window is created
        if (window == NULL) {
           //Window couldn't be made
            printf("Could not create window: %s\n", SDL_GetError());
            exit(-1);
        }

        HandleEvents();
}

void DestroyWindow(void)
{

SDL_DestroyWindow(window);
SDL_Quit();

}


void HandleEvents(void)
{
  SDL_Event event;

while(1)
  {
    while(SDL_PollEvent(&event) != 0)
      {
        if(SDL_KEYDOWN == event.type)
          {
            printf("%c",event.key.keysym.sym);
          }

        if(event.key.keysym.sym == SDLK_q)
          {
              DestroyWindow();
          }

      }
   }
}



