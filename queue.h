// =======================================================

// HW1P1
// Your name: Kristen Osborne
// Compiler:  g++ compiler
// File type: queue header file queue.h

//=====================================================

#include <string>
using namespace std;

  typedef string el_t; // el_t is an alias for the data type

  const int MAX_SIZE = 25; // this is the max number of elements

class queue
{
  private:
  // Data members are:
    el_t el[MAX_SIZE]; // an array called el.
                      //  Elements will be found between front and rear but
                      // front may be behind rear since the queue wraps around
    int  count;          // how many elements do we have right now?
    int  front;          // where the front element of the queue is.
    int  rear;           // where the rear element of the queue is.

  public:    // prototypes to be used by the client

    // exception handling classes
    class Overflow{};
    class Underflow{};

    // constructor 
    queue(); 

    //destructor 
    ~queue();

    // PURPOSE: returns true if queue is empty, otherwise false
    // HOW TO CALL: no parameters
    bool isEmpty();

    // PURPOSE: returns true if queue is full, otherwise false
    // HOW TO CALL: no parameters
    bool isFull();

    // PURPOSE: if full, throws an exception Overflow
    // if not full, enters an element at the rear 
    // HOW TO CALL: provide the element to be added
    void add(el_t);

    // PURPOSE: if empty, calls an emergency exit routine
    // if not empty, removes the front element to give it back 
    // HOW TO CALL: provide a holder for the element removed (pass by ref)
    void remove(el_t&);

    // PURPOSE: if empty, throws an exception Underflow
    // if not empty, give back the front element (but does not remove it)
    // HOW TO CALL: provide a holder for the element (pass by ref)
    void frontElem(el_t&);

    // PURPOSE: returns the current size to make it 
    // accessible to the client caller
    // HOW TO CALL: no parameters
    int getSize();

    // PURPOSE: display everything in the queue from front to rear
    //  enclosed in []
    // if empty, displays [ empty ]
    // HOW TO CALL: no parameters
    void displayAll();

    // PURPOSE: if empty, throws an exception Underflow
    //if queue has just 1 element, does nothing
    //if queue has more than 1 element, moves the front one to the rear
    // HOW TO CALL: no parameters
    void goToBack();


};