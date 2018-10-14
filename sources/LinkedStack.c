#include "headers/LinkedStack.h"
#include "headers/Initialize.h"
#include <ncurses.h>

static LS *RedoBufferTop = NULL;

static LS *UndoBufferTop = NULL;


//If State = 0 push into RedoBuffer and if State = 1 push into UndoBuffer


extern void Push(char Data, unsigned int State_Param)
{

  LS *TempPointer; //Creating a temporary pointer

  TempPointer =(LS*)malloc(sizeof(LS)); //allocating memory

  if(TempPointer == NULL) //Show error and exit if null
    {
    printf("\nMemory not available");
    exit(-1);
    }

  TempPointer->data = Data; //assigning data
  if(0 == State_Param)
  {
    TempPointer->Next = RedoBufferTop; //assigning the next element
  }else
  {
    TempPointer->Next = UndoBufferTop; //assigning the next element
  }



  if(0 == State_Param)
  {
    RedoBufferTop=TempPointer; //changing the Top pointer
  }else
  {
    UndoBufferTop = TempPointer; //changing the Top Pointer
  }

}


extern char Pop(unsigned int State_Param)
{
  long tempdata; //Storage variable for data to return
  LS *temp = NULL;
  if(0 == State_Param )
  {
     temp = RedoBufferTop; //Temp variable points to the same address as the top of the stack
  }else
  {
    temp = UndoBufferTop;
  }

  tempdata = temp->data; //extracting data

  if(0 == State_Param)
  RedoBufferTop = temp->Next; //changing position of the top pointer
  else
    UndoBufferTop = temp->Next;

  //free(temp); //freeing memory

  return (char)tempdata; //returning value
}


extern void Display(unsigned int Param)
{
  LS *temp;

  if(0 == Param)
    {

      temp = RedoBufferTop; //Creating and assigning it the same meory address as top
    }else
    {

      temp = UndoBufferTop;
    }


  //Traversing through the Linked Stack
  while(temp != NULL) //Till temp reaches the last node
    {
      addch((unsigned int)temp->data);
      temp = temp->Next; //moving  temp
    }
  addch((unsigned int)"\n\n");

  refresh();

}


//Empties the list
extern void Empty(void)
{
  LS *Cleaner = RedoBufferTop; //assinging the top of stack

  while(RedoBufferTop!=NULL)
    {
      //Traversing and deleting the elements of the stakc one by one
      RedoBufferTop = RedoBufferTop->Next;
      free(Cleaner);
      Cleaner = RedoBufferTop;
    }
}
