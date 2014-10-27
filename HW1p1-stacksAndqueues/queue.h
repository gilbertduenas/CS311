//==============================
//HW1P1 queue
//Gilbert Duenas
//Compiler:  g++
//File type: queue class header file
//==============================
#ifndef QUEUE_H
#define QUEUE_H

#include<string>
using namespace std;

const int MAX_SIZE = 60;  // this is the max number of elements
typedef string el_t;      // el_t is an alias for string

class queue  
{
 private:
  el_t el[MAX_SIZE];  // an array called el.
  //  Elements will be found between front and rear but
  // front may be behind rear since the queue wraps around
  int  count;  // how many elements do we have right now?
  int  front;  // where the front element of the queue is.
  int  rear;   // where the rear element of the queue is.
  
 public:
  class Overflow{};   // exception handling class  
  class Underflow{};  // exception handling class  
  
  queue();   // default constructor 
  ~queue();  // default destructor 
  
  // PURPOSE: returns true if queue is empty, otherwise false
  // HOW TO CALL: not applicable
  bool isEmpty();
  
  // PURPOSE: returns true if queue is full, otherwise false
  // HOW TO CALL: not applicable
  bool isFull();
  
  // PURPOSE: if full, throws an exception Overflow
  // if not full, enters an element at the rear 
  // HOW TO CALL: pass the element to be added
  void add(el_t);
  
  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, removes the front element to give it back 
  // HOW TO CALL: pass a holder for the element removed (pass by ref)
  void remove(el_t&);
  
  // PURPOSE: if empty, throws an exception Underflow
  // if not empty, give back the front element (but does not remove it)
  // HOW TO CALL: pass a holder for the element (pass by ref)
  void frontElem(el_t&);
  
  // PURPOSE: returns the current size to make it 
  // accessible to the client caller
  // HOW TO CALL: not applicable
  int getSize();
  
  // PURPOSE: display everything in the queue from front to rear
  //  enclosed in [] if empty, displays [ empty ]		
  // HOW TO CALL: not applicable
  void displayAll();
  
  // PURPOSE: if empty, throws an exception Underflow
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  // HOW TO CALL: not applicable
  void goToBack();
};           
#endif //QUEUE_H
