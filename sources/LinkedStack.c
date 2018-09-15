#include "headers/LinkedStack.h"


static LS *Top= NULL;

extern void Push(long Data)
{

  LS *TempPointer;

  TempPointer =(LS*)malloc(sizeof(LS));

  if(TempPointer == NULL)
    {
    printf("\nMemory not available");
    exit(-1);
    }

  TempPointer->data = Data;
  TempPointer->Next = Top;
  Top=TempPointer;

}

extern long Pop()
{
  long tempdata;
  LS *temp = Top;


  tempdata = temp->data;

  Top = temp->Next;

  free(temp);

  return tempdata;
}

extern void Display(void)
{
  LS *temp = Top;

  while(temp != NULL)
    {
      printf("%ld",temp->data);

      temp = temp->Next;
    }
}


extern void Clean(void)
{
  LS *Cleaner = Top;

  while(Cleaner!=NULL)
    {

    }
}
