// =========================================================

//HW1P2 stack
//Your name: Kristen Osborne
//Complier:  g++
//File type: .cpp

//================================================================
#include <iostream>
using namespace std;
#include "stack.h"

//Constructs the class objects
stack::stack()
{ 
  //does nothing
}

// Destructor destroys all elements of the vector before destroying itself
//Destroys the class ojects
stack::~stack()
  { 
    if(!vec.empty())
      vec.clear();

  }

  
//Returns true if empty, false otherwise.
//purpose is to see if an underflow is possible if popping
//there is already a function in the vector class: empty()
bool stack::isEmpty()
{ 
  if(vec.empty()) //indicates an empty stack
    return true; 
  else 
    return false;
}
  
//there will never be an overflow so no exception
//purpose is to push elements to the stack
//purpose of parameter is to hold the new value being added
//vector class already has push_back().
void stack::push(el_t elem)
  { 
    vec.push_back(elem);
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
      elem = vec.back();
      vec.pop_back(); //this destroys the last element in vector which is elem
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
      elem = vec.back(); //top element is the last element
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
      for(int i = 0; i < vec.size(); i ++)
        cout << vec[i] << endl;
    }
  }

// clearIt pops all elements from the stack to make it empty if it is not empty yet.
//vector class has clear() which clears all elements in vector
void stack::clearIt()
{

  if(isEmpty())
    cout << "Nothing to clear." << endl;
  else
  {
    vec.clear();
  }
}