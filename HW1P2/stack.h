// =======================================================

// HW1P2
// Your name: Kristen Osborne
// Compiler:  g++ 
// File type: header file stack.h

//=======================================================

#include <vector>
using namespace std;

typedef int el_t;      // the el_t type is type int
                      // el_t is unknown to the client


class stack
{
  private: // to be hidden from the client

  vector<el_t> vec; // vec is a vector of el_t's

  public: // prototypes to be used by the client

  // exception handling classes  
  class Overflow{};  //this won't be need for vector
  class Underflow{};

  stack();   // constructor
  ~stack();  // destructor  

  // HOW TO CALL: pass the element to be pushed
  // PURPOSE: if not full, enters an element at the top;
  //          uses vector push_back()
  void push(el_t);

  // HOW TO CALL: provide variable to receive the popped element
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  void pop(el_t&);

  // HOW TO CALL: pass the element to be at the top
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  void topElem(el_t&);

  // HOW TO CALL: does not receive an input parameter
  // PURPOSE: checks if there are elements in stack.
  //          otherwise throws an exception - Underflow
  bool isEmpty();

  // HOW TO CALL: does not receive an input parameter
  // PURPOSE: prints all elements in stack to the screen
  void displayAll();

  // HOW TO CALL: does not receive an input parameter
  // PURPOSE: empties the stack
  void clearIt();
      
};