#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "headers/LinkedStack.h"
#include "headers/Initialize.h"


int main()
{

  initscr();
  clear();
  refresh();
  cbreak();
  noecho();

  int xMax, yMax;

  getmaxyx(stdscr, yMax, xMax);
  MainFrame = newwin(50, xMax - 20, 10, 10);

  //box(MainFrame, 0, 0);
  cbreak();
  noecho();
  keypad(stdscr, true);
  keypad(MainFrame, true);


  int c;
  int x = 1;
  int y = 0;
  char l = 0;
   while(true)
    {
        c = wgetch(MainFrame);
        clear();
        switch(c)
          {
            case KEY_F(1):
            addch((unsigned int)"\n\n");
            l = Pop(0);
            Push(l, 1);
            refresh();
            clear();
            Display(0);
            refresh();


            break;

          case KEY_F(2) :

           l = Pop(1);
           Push(l, 0);
           clear();
           Display(0);
           refresh();
          break;

          case KEY_BACKSPACE:
            l = Pop(0);
            Push(l, 1);
            clear();
            Display(0);
            refresh();
          break;

          case KEY_F(3) :
            main();
          break;

          case KEY_F(4) : Display(1);break;
          default:
          Push((char)c, 0);
          mvwaddch(MainFrame, x, y++, (unsigned int)c);
          break;

          }
    }


   refresh();
   Display(0);

  getch();
  endwin();
}


