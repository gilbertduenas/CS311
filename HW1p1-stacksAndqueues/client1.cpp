//==============================
//HW1P1 stack
//Gilbert Duenas
//Compiler:  g++
//File type: Client file
//==============================
#ifndef CLIENT1_CPP
#define CLIENT1_CPP

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

// Purpose of the program: Demonstrate a stack data structure using 
// a static array. The program will ask for user input in the form of 
// a postfix expression.
// Compile client1.cpp stack.h and stack.cpp together. Run the program 
// and enter your values.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   //required to store user input
  
  cout << "type a postfix expression: ";
  cin >> expression;
  
  int i = 0;      // character position within expression
  int number = 0; // stores integer converted from a character
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result = 0;  // placeholder for calculations
  
  while (expression[i] != '\0')  // loop through string entered
    {
      try
	{
	  if(expression.size()<3)  // test for minimum input
	    throw "Please enter 2 operands followed by an operator";
	  // check for integer operators
	  if(expression[i]>47 && expression[i]<58)
	    {  
	      // call function to convert char to integer
	      number = postfixstack.charToInt(expression[i]);
	      postfixstack.push(number);  // call push function
	      postfixstack.displayAll();  // show stack as per example
	      cout << "-------------------" << endl;
	    } 
	  // check for operators
	  else if((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*'))
	    {
	      // check for the appropriate number of operands
	      if(postfixstack.isEmpty()==true)  
		throw "First box empty, too few operands";
	      else
		postfixstack.pop(box1);
	      
	      // check for the appropriate number of operands
	      if(postfixstack.isEmpty()==true)
		throw "Second box empty, too few operands";
	      else
		postfixstack.pop(box2);
	      
	      // check for which operator is used
	      if (expression[i] == '-') 
		{
		  result = box2-box1;
		}
	      else if(expression[i] == '+')
		{				
		  result =  box2 + box1;
		}
	      
	      else if(expression[i] == '*')
		{				
		  result = box2 * box1;
		}           
	      
	      // push the value onto the stack
	      postfixstack.push(result); 
	      postfixstack.displayAll();
	      cout << "-------------------" << endl;
	    }
	  else{ throw "You may only enter operands and operators";}
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      catch (stack::Overflow)
	{ 
	  cerr << "Overflow: Please enter less than 11 integers" << endl;
	  exit(1);
	}
      catch (stack::Underflow)
	{
	  cerr << "Underflow: Please enter more than 1 integer" << endl;
	  exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cerr << "Error: " << errorcode << endl;
	  exit(1);
	}
      i++;
    }// end of while
  
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(box1);
  
  //if the stack contains more than one value throw exception
  try
    {
      if(postfixstack.isEmpty()!=true)
	throw "Incomplete expression found";
    }
  catch(char const* errorcode2)
    {
      cerr<<"Error: " << errorcode2 << endl; 
      exit(1);
    }
  
  cout << "The result is " << box1 << endl; 
  
  return 0;
}
#endif //CLIENT1_CPP
