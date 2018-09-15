#include <stdio.h>
#include <stdlib.h>
//#include <gtk/gtk.h>
#include "headers/LinkedStack.h"


int main()
{
    char data;
    long temp;


    for(int i =0; i<10;i++)
      {

      printf("\nEnter data");
      scanf(" %c", &data);

      //Method of storing any character :
      /*
      convert the given character to ASCII
      store the ASCII value
      When required reconvert backs
      */
      temp = *(char*)&data; //Quake's bit level hacking modified to convert char to its ASCII value

      printf("%ld",temp); //debugging purpose
       }


      return 0;
}
