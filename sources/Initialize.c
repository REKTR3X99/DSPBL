#include "headers/Initialize.h"
#include "headers/LinkedStack.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_test_images.h>
#include <ncurses.h>
#include <menu.h>


static SDL_Window *window = NULL;


/*void CreateWindow(void)
{


      SDL_Renderer *BackgroundRenderer;

       SDL_Init(SDL_INIT_EVERYTHING);//Initializing SDL
       SDL_StartTextInput();

        // Create window
        window = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            640,                               // width, in pixels
            480,                               // height, in pixels
            SDL_WINDOW_RESIZABLE               //flag
        );

        //Chec kif window is created
        if (window == NULL) {
           //Window couldn't be made
            printf("Could not create window: %s\n", SDL_GetError());
            exit(-1);
        }

        BackgroundRenderer = SDL_CreateRenderer(window, -1, 0); //BackgroundRenderer
        SDL_SetRenderDrawColor(BackgroundRenderer, 255,255,0,100); //Set color for the renderer
        SDL_RenderPresent(BackgroundRenderer); //Rendering the color

        HandleEvents(); //call handle events
}
*/

void CreateWindow(void)
{

}



void DestroyWindow(void)
{

SDL_DestroyWindow(window);
SDL_Quit();

}

/*
//Handle all the given events and keypresses
void HandleEvents(void)
{
  char temp;

  SDL_Event event;
  SDL_Renderer *TextRenderer;

  TextRenderer = SDL_CreateRenderer(window, -1, 0);

while(1) //while true, run till the end of the window life cycle
  {
    while(SDL_PollEvent(&event) != 0) //polling the to get key presses
      {

        if(SDL_KEYUP == event.type) //Debugging purposes
          {
            Push((char)event.key.keysym.sym,0);
            printf("\nRedo Stack");
            Display(0);
             //gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
          }else if(event.key.keysym.sym == SDLK_q && SDL_GetModState() & KMOD_CTRL)
          {
              printf("\nRedo Stack");
              Display(0);
              printf("\n\n\n\n");
              printf("\nUndo Stack");
              Display(1);
              DestroyWindow();
          }else if(event.key.keysym.sym == SDLK_z && (SDL_GetModState() & KMOD_CTRL))
          {
              temp = Pop(0);
              Push(temp, 1);
              printf("\nUndo Stack");
              Display(1);
          }else if(event.key.keysym.sym  == SDLK_z && SDL_GetModState() & KMOD_CTRL & KMOD_SHIFT)
          {
            temp = Pop(1);
            Push(temp, 0);

          }

      }
   }
}

*/




