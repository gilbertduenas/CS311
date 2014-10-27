//==============================
//HW1P1 queue
//Gilbert Duenas
//Complier:  g++
//File type: queue implementation file
//==============================
#ifndef QUEUE_CPP
#define QUEUE_CPP

#include<iostream>
#include "queue.h"   

// PURPOSE: creates a queue with elements and variables initialized
queue::queue()
{
  el[0] = "A";
  el[1] = "B";
  el[2] = "C";
  count = 3;
  front = 0;
  rear = 2;
}

// PURPOSE: none since we are using a static array
queue::~queue(){}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count == 0)  // checks the number of elements in the queue
    {
      cout << "The queue is empty." << endl;
      return true; 
    }
  else 
    return false; 
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count > MAX_SIZE)  // checks the number of elements in the queue, 60 is max
    {
      cout << "The queue is full." << endl;
      return true; 
    }
  else 
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// HOW TO CALL: provide the element to be added
void queue::add(el_t e)
{
  if(isFull())  // check if the queue is full
    {
      throw Overflow();
    }
  else
    {
      // calculate the rear index of the new element added
      // we take the modulus in order to wrap from the rear to the front
      // for example if the rear index is 59, then the next index cannot be 60.
      // but (59+1)%MAX_SIZE gives us 0 which is the beginning cell.
      rear = (rear+1) % MAX_SIZE;  
      el[rear] = el[front] + e;  // concatenate the string with a string
      count+=1;  // increment to track added element
    }
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& e)
{
  if(isEmpty())  // check if empty
    {
      cout << " [empty] " <<endl;
      exit(1);  
    }
  else
    {	
      string oldFront = el[front];
      //calculate the new front index similar to calculating the rear index
      front = (front+1) % MAX_SIZE;  
      count-=1;  // decrement to track deleted element
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& e)
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else
    {	
      e = el[front];  // pass the front element to the client file
      cout << e << endl;
    }
}

// PURPOSE: returns the current size for the client caller
// HOW TO CALL: not applicable
int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in [] if empty, displays [ empty ]
// HOW TO CALL: not applicable
void queue::displayAll()
{
  cout << "Count = " << count << " Front = " << front 
       << " Rear = " << rear << endl;
  cout << "[ ";
  // checks if rear index is less than front index
  // this is necessary to print the items in the correct order
  if(rear<front)  
    {
      for(int i = front; i<MAX_SIZE; i++)
	{
	  cout << el[i] << " "; 
	}
      for(int i=0; i<front; i++)
	{
	  cout << el[i] << " "; 
	}
    }
  else
    {
      // the count+front should never be greater than 60
      for(int i = front; i < count+front; i++)
	{
	  cout << el[i] << " "; 
	}
    }
  cout << "]" << endl;
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
// HOW TO CALL: not applicable
void queue::goToBack()
{
  if(isEmpty())
    {
      throw Underflow();
    }
  else if(count == 1)
    {
    }
  else
    {
      add(el[front]);
      remove(el[front]);
    }
}
#endif //QUEUE_CPP
