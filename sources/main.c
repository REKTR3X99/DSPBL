#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <pthread.h>
#include <ncurses.h>

#include "headers/LinkedStack.h"
#include "headers/Initialize.h"

static WINDOW *MainFrame;


int main()
{
  initscr();
  cbreak();
  noecho();

  int xMax, yMax;
  int c;
  int x = 1;
  int y = 0;

    getmaxyx(stdscr, yMax, xMax);
    MainFrame = newwin(50, xMax - 20, 10, 10);
    box(MainFrame, 0, 0);
    cbreak();
    noecho();
    keypad(stdscr, true);
    keypad(MainFrame, true);


   while(true)
    {

        c = wgetch(MainFrame);
        mvwaddch(MainFrame, x, y++, (unsigned int)c);

        switch(c)
          {
            case KEY_F(1) :
            goto display;
            break;


          default:
          Push((char)c, 0);
          break;

          }

    }

   display :
   refresh();
   Display(0);

  getch();
  endwin();
}


