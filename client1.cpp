// =========================================================

//HW1P1 stack client
//Your name: Kristen Osborne
//Complier:  gcc
//File type: .cpp

//================================================================

#include <iostream>
#include <string>
using namespace std;
#include "stack.h"


//Purpose of program is to implement a postfixstack expression.
//It will ask for the expression from the user and output the result.
//It will use the stack class and source code. To compile run with stack.cpp
//To use, follow the directions on the screen.
//Overall design is to use an array as the stack. Each operator and operand will
//   be put into the stack. It will evaluate the top two values first, then work
//   its way down until one result remains. If more or less than one result, it 
//   will throw an exception.

int main()
{
  stack postfixstack;  // integer stack
  string expression;
  
  cout << "Type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
  {
    try
    {
      item = expression[i]; //1.  read an item.
      if(int(item) >= 48 && int(item) <= 57) //2.  if it is an operand (number), 
        postfixstack.push(int(item) - 48); //push it (you might get Overflow exception)
      else if((item == '+') || (item == '-') || (item == '*')) //3.  else if it is an operator,
      { 
        postfixstack.pop(box1);
        postfixstack.pop(box2); //pop the two operands (you might get Underflow exception), and
      
        //	 apply the operator to the two operands, and
        //    push the result.
        switch(item)
        {
          case '+':
          {
            postfixstack.push(box2+box1);
            break;
          }
          case '-':
          {
            postfixstack.push(box2-box1);
            break;
          }
          case '*':
          {
            postfixstack.push(box2*box1);
            break;
          }
        }

      }
      else
      {
        throw "invalid item";
      } 
    } // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
    catch (stack::Overflow)
    {
      cout << "There was an overflow." << endl;
      return 1;
    }
    catch (stack::Underflow)
    {
      cout << "There was an underflow." << endl;
      return 1;
    }
    catch (char const* errorcode) // for invalid item
    {
      cout << "Invalid item." << endl;
      return 1;
    }
      // go back to the loop
    i++;
  }// end of while
  
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
  int result;
  postfixstack.pop(result);

  if(!postfixstack.isEmpty())
  {
    cout << "Incomplete expression." << endl;
    return 1;
  }

  else
    cout << "Result: " << result << endl;


  return 0;
}