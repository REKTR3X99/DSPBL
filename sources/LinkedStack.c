#include "headers/LinkedStack.h"
#include "headers/Initialize.h"
#include <ncurses.h>

static LS *RedoBufferTop = NULL;

static LS *UndoBufferTop = NULL;

static LS *DisplayBufferTop = NULL;

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
  }else if(1 == State_Param)
  {
    TempPointer->Next = UndoBufferTop; //assigning the next element
  }else if(2 == State_Param)
    {
      TempPointer->Next = DisplayBufferTop;
    }



  if(0 == State_Param)
  {
    RedoBufferTop=TempPointer; //changing the Top pointer
  }else if(1 == State_Param)
  {
    UndoBufferTop = TempPointer; //changing the Top Pointer
  }else if(2 == State_Param)
  {
     DisplayBufferTop = TempPointer;
   }

}


extern char Pop(unsigned int State_Param)
{
  long tempdata; //Storage variable for data to return
  LS *temp = NULL;
  if(0 == State_Param )
  {
     temp = RedoBufferTop; //Temp variable points to the same address as the top of the stack
  }else if(1 == State_Param)
  {
    temp = UndoBufferTop;
  }else if(2 == State_Param)
    {
      temp = DisplayBufferTop;
    }

  tempdata = temp->data; //extracting data

  if(0 == State_Param)
  RedoBufferTop = temp->Next; //changing position of the top pointer
  else if(1 == State_Param)
    UndoBufferTop = temp->Next;
  else if(2 == State_Param)
    DisplayBufferTop = temp->Next;


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
      if(Param == 0)
        {
          Push(temp->data, 2);
        }else
      {
          addch((unsigned int)temp->data);
       }


      temp = temp->Next; //moving  temp
    }

  if(Param == 0)
    {
      DisplayRedoBuffer();
    }else
    {
  addch((unsigned int)"\n\n");
    }

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

extern void DisplayRedoBuffer(void)
{

  LS *temp = DisplayBufferTop;

  clear();
  while(temp != NULL) //Till temp reaches the last node
    {
      addch((unsigned int)temp->data);
      temp = temp->Next; //moving  temp
    }
  refresh();
}
