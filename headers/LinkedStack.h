#ifndef MAKESTUFF_H
#define MAKESTUFF_H

#endif // MAKESTUFF_H

#include <stdlib.h>
#include <stdio.h>

//Linked stack basic structure
struct LinkedStack
{
  char data; //variable to hold data
  struct LinkedStack *Next;  //Holds the enext address
};

typedef struct LinkedStack LS; //typedef because I'm too lazy to type the whole name



//defining the function prototypes for all the function in LinkedStack.c
void Push(char, unsigned int);

char Pop(unsigned int);

void Display(unsigned int);

void Empty(void);


