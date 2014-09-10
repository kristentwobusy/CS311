// =========================================================

//HW1P1 queue client
//Your name: Kristen Osborne
//Complier:  gcc
//File type: .cpp

//================================================================

#include <iostream>
using namespace std;

#include "queue.h"

//Purpose of program is to generate all strings using A, B, and C using a queue.
//It will ask for the expression from the user and output the result.
//It will use the queue class and source code. To compile run with queue.cpp
//To use, follow the directions on the screen.
//Overall design is to use an array as the queue. Each entered expression will
//   be added to the queue using the FIFO method. It can also be removed using
//   the same method.

int main()
{
  queue myQueue;
  string first;

  myQueue.add("A");
  myQueue.add("B");
  myQueue.add("C");
  myQueue.displayAll();


  while(!myQueue.isFull())
  {
    try{
      myQueue.frontElem(first);
      myQueue.add(first + "A");  
      myQueue.add(first + "B");
      myQueue.add(first + "C");
      myQueue.remove(first);
      myQueue.displayAll();
    }

  catch (queue::Overflow)
  {
    cout << "There was an overflow." << endl;
    return 1;
  }
  catch (queue::Underflow)
  {
    cout << "There was an underflow." << endl;
    return 1;
  }
}

  return 0;
}