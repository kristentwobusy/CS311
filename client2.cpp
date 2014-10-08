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
//Overall design is to use an array as the queue. The queue is filled with A, B,
//   and C. Then the first element is added with another A, B, and C, each being
//   added to the end of the array. This process will happen until the array 
//   is full.

int main()
{
  queue myQueue;
  string first;

  myQueue.add("A");
  myQueue.add("B");
  myQueue.add("C");
  myQueue.displayAll();


  while(!myQueue.isFull()) //continue filling array until full
  {
    try{
      myQueue.frontElem(first); //get the first element
      myQueue.add(first + "A"); //Add A to the first and put at end of queue
      myQueue.add(first + "B"); //Add B to the first and put at end of queue
      myQueue.add(first + "C"); //Add C to the first and put at end of queue
      myQueue.remove(first); //remove the first element
      myQueue.displayAll();
    } //end of try

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
  } //end of while

  return 0;
}//end of main