#ifndef MAKESTUFF_H
#define MAKESTUFF_H

#endif // MAKESTUFF_H

#include "processing.h"
#include <stdlib.h>
#include <stdio.h>
struct LinkedStack
{
  long data;
  struct LinkedStack *Next;
};

typedef struct LinkedStack LS;

void Push(long);

long Pop(void);

void Display(void);

void Clean(void);


