#include "headers/LinkedStack.h"


static LS *Top= NULL;

extern void Push(long Data)
{

  LS *TempPointer; //Creating a temporary pointer

  TempPointer =(LS*)malloc(sizeof(LS)); //allocating memory

  if(TempPointer == NULL) //Show error and exit if null
    {
    printf("\nMemory not available");
    exit(-1);
    }

  TempPointer->data = Data; //assigning data
  TempPointer->Next = Top; //assigning the next element
  Top=TempPointer; //changing the Top pointer

}

extern long Pop()
{
  long tempdata; //Storage variable for data to return
  LS *temp = Top; //Temp variable points to the same address as the top of the stack


  tempdata = temp->data; //extracting data

  Top = temp->Next; //changing position of the top pointer

  free(temp); //freeing memory

  return tempdata; //returning value
}

extern void Display(void)
{
  LS *temp = Top; //Creating and assigning it the same meory address as top

  //Traversing through the Linked Stack
  while(temp != NULL) //Till temp reaches the last node
    {
      printf("%ld",temp->data); //print data

      temp = temp->Next; //moving temp
    }
}


//Need to implement
extern void Clean(void)
{
  LS *Cleaner = Top;

  while(Cleaner!=NULL)
    {

    }
}
