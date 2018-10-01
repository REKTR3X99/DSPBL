#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <pthread.h>


#include "headers/LinkedStack.h"
#include "headers/Initialize.h"

static unsigned int quit = 0;

int main()
{
    pthread_t WindowThread;
    //pthread_t EventThread;
    int state;
    SDL_Event Event;


    state = pthread_create(&WindowThread,NULL, CreateWindow, NULL);
    //state = pthread_create(&EventThread,NULL, HandleEvents, NULL);

    SDL_WaitEvent(&Event);

    while(quit != 1)
      {
        if(SDL_Quit == Event.type)
          {
          quit = 1;
          }
      }

    if(state!=0)
      {
        printf("\nWindow cannot be created");
        exit(-1);
      }

    pthread_join(WindowThread, NULL);

   //for(int i =0; i<10;i++)
   //  {
   //
   //  printf("\nEnter data");
   //  scanf(" %c", &data);
   //
   //  //Method of storing any character :
   //
   //  /*convert the given character to ASCII
   //  store the ASCII value
   //  When required reconvert backs*/
   //
   //  temp = *(char*)&data; //Quake's bit level hacking modified to convert char to its ASCII value
   //
   //  Push(temp);
   //}

   //Display();
   //Empty();
   //printf("\nStack Empty");
   //Display();


   //DestroyWindow();


      return 0;
}


