//==============================
//HW1P1 stack
//Gilbert Duenas
//Compiler:  g++ 
//File type: stack class header file
//==============================
#ifndef STACK_H
#define STACK_H

#include<string>
using namespace std;

const int MAX = 10;   // The MAX number of elements for the stack
typedef int el_t;     // el_t is an alias for integer

class stack
{ 
 private:
  el_t el[MAX];  // el is  an array of el_t's
  int top;       // integer for the index of an array 
  
 public: 
  class Overflow{};   // exception handling class  
  class Underflow{};  // exception handling class  
  
  stack();   // default constructor
  ~stack();  // default destructor  
  
  // PURPOSE: if not full, insert element at the top; 
  // else throw overflow exception
  // HOW TO CALL: pass the element to be pushed
  void push(int);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  // else throw underflow exception
  // HOW TO CALL: pass a variable to receive the popped element
  void pop(el_t&); 
  
  // PURPOSE: if not empty, gives the top element without removing it;
  // else throw underflow exception
  // HOW TO CALL: pass a variable to receive the popped element
  void topElem(el_t&);
  
  // PURPOSE: convert a character to integer for stack
  // HOW TO CALL: pass character to be converted
  int charToInt(el_t); 
  
  // PURPOSE: check if the stack is empty, if so - Underflow
  // HOW TO CALL: not applicable
  bool isEmpty(); 
  
  // PURPOSE: check if the stack is full, if so - Overflow
  // HOW TO CALL: not applicable
  bool isFull(); 
  
  // PURPOSE: displays the stack vertically
  // HOW TO CALL: not applicable
  void displayAll(); 
  
  // PURPOSE: empties the stack
  // HOW TO CALL: pass the top element of the stack to be cleared
  void clearIt(el_t&);  
};  
#endif //STACK_H
