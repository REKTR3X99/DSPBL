#include "headers/Initialize.h"
#include "headers/LinkedStack.h"


#include <SDL2/SDL.h>

static SDL_Window *window = NULL;

void CreateWindow(void)
{

      SDL_Renderer *Renderer;

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

        Renderer = SDL_CreateRenderer(window, -1, 0); //BackgroundRenderer
        SDL_SetRenderDrawColor(Renderer, 255,255,0,100); //Set color for the renderer
        SDL_RenderPresent(Renderer); //Rendering the color

        HandleEvents(); //call handle events
}

void DestroyWindow(void)
{

SDL_DestroyWindow(window);
SDL_Quit();

}


//Handle all the given events and keypresses
void HandleEvents(void)
{
  SDL_Event event;

while(1) //while true, run till the end of the window life cycle
  {
    while(SDL_PollEvent(&event) != 0) //polling the to get key presses
      {
        if(SDL_KEYDOWN == event.type) //Debugging purposes
          {
            Push(event.key.keysym.sym);
          }

        //Quit if Ctrl + q is pressed
        if(event.key.keysym.sym == SDLK_q && SDL_GetModState() & KMOD_CTRL)
          {

              DestroyWindow();
          }

      }
   }
}



