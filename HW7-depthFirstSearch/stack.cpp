//==============================
//HW7p2
//Gilbert Duenas
//Compiler:  g++
//File type: stack implementation file
//==============================
#ifndef STACK_CPP
#define STACK_CPP

#include<iostream>
#include "stack.h"

// PURPOSE: creates an empty stack, note top set at -1
stack::stack()
{ 
  top = -1; 
} 

// PURPOSE: none since we are using a static array
stack::~stack(){ /* nothing to do */ }

// PURPOSE: calls isFull and if true, throws an exception (Overflow)
// Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{ 
  if(isFull()) 
  {
    throw Overflow();
  }
  else 
  { 
    top++; 
    el[top] = elem; 
  }
}

// PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
// Otherwise, removes an element from el and gives it back.
void stack::pop(el_t& elem)
{ 
  if (isEmpty())  // checks if the stack is empty
  {
    throw Underflow();
  }
  else 
  { 
    elem = el[top]; 
    top--;  // move the top of the stack to the next element
  }
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
// Otherwise, gives back the top element from el.
void stack::topElem(el_t& elem)
{ 
  if (isEmpty())  // checks if the stack is empty
  {
    throw Underflow();
  }
  else 
  { 
    elem = el[top]; 
  } 
}

// PURPOSE: checks if top is -1 and returns true if empty, false otherwise.
bool stack::isEmpty()
{ 
  if (top == -1)  // the stack is empty if the top is -1
    return true; 
  else 
    return false; 
}   

// PURPOSE: checks if top is 9 and returns true if full, false otherwise.
bool stack::isFull()
{ 
  if(top == MAX-1)  // the stack is full if the top is MAX-1
    return true; 
  else 
    return false; 
}

// PURPOSE: calls isEmpty and if true, displays [ empty ].
// ALGORITHM: else for loop used to display elements vertically
void stack::displayAll()
{  
  if (isEmpty()) 
  {
    cout << "[ empty ]" << endl;
  }
  else 
  {
    cout << "[";
    for (int i=0; i<=top; i++)  // decrement until top is -1
    { 
      cout << el[i] << " "; 
    }
    cout << "top]" << endl;
  }  
}

// PURPOSE: removes all the elements from the stack to make it empty 
// if it is not empty yet.
// ALGORITHM: while loop used to pop elements until the stack is empty
void stack::clearIt(el_t& elem)
{ 
  if(!isEmpty())  // check if elements exist 
  {
  while(top != -1) // pop elements until top is -1
    pop(elem);
  }
}
#endif //STACK_CPP
