// =======================================================

// HW1P1
// Your name: Kristen Osborne
// Compiler:  g++ 
// File type: header file stack.h

//=======================================================

const int MAX = 10;   // The MAX number of elements for the stack
                       // MAX is unknown to the client

typedef int el_t;      // the el_t type is type int
                      // el_t is unknown to the client


class stack
{
  private: // to be hidden from the client

  el_t el[MAX];       // el is  an array of el_t's
  int top;           // top is index to the top of stack

  public: // prototypes to be used by the client

  // exception handling classes  
  class Overflow{};
  class Underflow{};

  stack();   // constructor
  ~stack();  // destructor  

  // HOW TO CALL: pass the element to be pushed
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
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
  // PURPOSE: checks if there are open spaces in stack
  //          otherwise throws an exception - Overflow
  bool isFull();

  // HOW TO CALL: does not receive an input parameter
  // PURPOSE: prints all elements in stack to the screen
  void displayAll();

  // HOW TO CALL: does not receive an input parameter
  // PURPOSE: empties the stack
  void clearIt();
      
};