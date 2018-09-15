#include <stdio.h>
#include <stdlib.h>
//#include <gtk/gtk.h>
#include "headers/LinkedStack.h"
#include <curses.h>
#include <string.h>


int main()
{
    char data;
    long temp;


    for(int i =0; i<10;i++)
      {

      printf("\nEnter data");
      scanf(" %c", &data);

      temp = *(char*)&data; //using quake's bit level hacking to convert to ASCII

      printf("%ld",temp);
        }


      return 0;
}
