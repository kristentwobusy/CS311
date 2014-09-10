// =========================================================

//HW1P1 stack
//Your name: Kristen Osborne
//Complier:  g++
//File type: .cpp

//================================================================
#include <iostream>
using namespace std;
#include "stack.h"

//Constructor must initialize top to be -1 to begin with.
//Constructs the class objects
stack::stack()
{ 
  top = -1; // indicate an empty stack
}

// Destructor does not have to do anything since this is a static array.
//Destroys the class ojects
stack::~stack()
  { 
    // nothing to do 
  }
  
//checks top and returns true if empty, false otherwise.
//purpose is to see if an underflow is possible if popping
bool stack::isEmpty()
{ 
  if(top == -1) //indicates an empty stack
    return true; 
  else 
    return false;
}
    
// checks top and returns true if full, false otherwise.
// purpose is to see if an overflow is possible if pushing
bool stack::isFull()
  { 
    if(top == (MAX-1)) //10 elements in array. So if top is 9, it is full
      return true;
    else
      return false;
  }
  
//calls isFull and if true, throws an exception (Overflow)
//Otherwise, adds an element to el after incrementing top.
//purpose is to push elements to the stack
//purpose of parameter is to hold the new value being added
void stack::push(el_t elem)
  { 
    if(isFull())
      throw stack::Overflow();
    else
    { 
      top++;
      el[top] = elem;
    }
  }
  
//pop calls isEmpty and if true, throws an exception (Underflow)
//Otherwise, removes an element from el and gives it back.
//purpose is to pop elements from the stack
//purpose of parameter is to hold the new value being removed
void stack::pop(el_t& elem)
  { 
    if(isEmpty())
      throw stack::Underflow();
    else
    {
      elem = el[top];
      top--;
    }
  }

//topElem calls isEmpty and if true, throws an exception (Underflow)
//Otherwise, gives back the top element from el.
//purpose is to give back the top element of the array with parameter
void stack::topElem(el_t& elem)
  {
    if(isEmpty())
      throw stack::Underflow();
    else
    {
      elem = el[top];
    }
  }

//dislayAll calls isEmpty and if true, displays [ empty ].
//Otherwise, diplays the elements vertically.
//to display, start at top element then work your way down the
//   stack until there are no more elements to display
void stack::displayAll()
  {  
    if(isEmpty()) 
      cout << "[ empty ]" << endl;
    else
    {
      for(int i = top; i >= 0; i--)
        cout << el[i] << endl;
    }
  }

// clearIt pops all elements from the stack to make it empty if it is not empty yet.
//to clear, start with the top element and pop every element
//   along to way until you reach the end of the array. Set top to 0
void stack::clearIt()
{

  if(isEmpty())
    cout << "Nothing to clear." << endl;
  else
  {
    int i;
    for(i = top; i >= 0; i--) //pop all elements starting with top until bottom
    {
      pop(el[i]);
    } 
    top = i;

  }
}